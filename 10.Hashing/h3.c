#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007

typedef struct Festival {
    char name[15];
    long long top[3];
    int count;
    struct Festival* next;
} Festival;

Festival* hash_table[HASH_SIZE];

unsigned int hash_func(const char* str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_SIZE;
}

void add_spending(Festival* f, long long x) {
    if (f->count < 3) {
        f->top[f->count++] = x;
    } else {
        int min_idx = 0;
        if (f->top[1] < f->top[min_idx]) min_idx = 1;
        if (f->top[2] < f->top[min_idx]) min_idx = 2;
        
        if (x > f->top[min_idx]) {
            f->top[min_idx] = x;
        }
    }
}

Festival* get_or_create(const char* name) {
    unsigned int idx = hash_func(name);
    Festival* curr = hash_table[idx];
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    Festival* new_node = (Festival*)malloc(sizeof(Festival));
    strcpy(new_node->name, name);
    new_node->count = 0;
    new_node->top[0] = new_node->top[1] = new_node->top[2] = 0;
    new_node->next = hash_table[idx];
    hash_table[idx] = new_node;
    return new_node;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, i;
        scanf("%d", &n);

        for (i = 0; i < HASH_SIZE; i++) {
            hash_table[i] = NULL;
        }

        for (i = 0; i < n; i++) {
            char name[15];
            long long x;
            scanf("%s %lld", name, &x);
            Festival* f = get_or_create(name);
            add_spending(f, x);
        }

        char best_name[15] = "";
        long long max_sum = -1;

        for (i = 0; i < HASH_SIZE; i++) {
            Festival* curr = hash_table[i];
            while (curr != NULL) {
                long long current_sum = 0;
                for (int j = 0; j < curr->count; j++) {
                    current_sum += curr->top[j];
                }

                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    strcpy(best_name, curr->name);
                } else if (current_sum == max_sum) {
                    if (best_name[0] == '\0' || strcmp(curr->name, best_name) < 0) {
                        strcpy(best_name, curr->name);
                    }
                }

                Festival* temp = curr;
                curr = curr->next;
                free(temp);
            }
            hash_table[i] = NULL;
        }

        printf("%s %lld\n", best_name, max_sum);
    }

    return 0;
}