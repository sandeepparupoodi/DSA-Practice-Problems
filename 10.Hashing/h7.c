#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000003

typedef struct Node {
    long long val;
    struct Node* next;
} Node;

Node* hash_table[HASH_SIZE];

int hash_func(long long val) {
    long long h = val % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return (int)h;
}

int insert_hash(long long val) {
    int idx = hash_func(val);
    Node* curr = hash_table[idx];
    while (curr != NULL) {
        if (curr->val == val) {
            return 0;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = hash_table[idx];
    hash_table[idx] = newNode;
    return 1;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int NA[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &NA[i]);
    }

    long long unique_sum = 0;

    for (int i = 0; i < N; i++) {
        long long max_so_far = NA[i];
        long long current_sum = 0;

        for (int j = i; j < N; j++) {
            if (current_sum + NA[j] > NA[j]) {
                current_sum += NA[j];
            } else {
                current_sum = NA[j];
            }

            if (current_sum > max_so_far) {
                max_so_far = current_sum;
            }

            if (insert_hash(max_so_far)) {
                unique_sum += max_so_far;
            }
        }
    }

    printf("%lld\n", unique_sum);

    return 0;
}