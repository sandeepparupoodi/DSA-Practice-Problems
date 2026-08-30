#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003

typedef struct HashNode {
    long long age;
    int count;
    struct HashNode *next;
} HashNode;

HashNode *hash_table[HASH_SIZE];

int get_hash(long long key) {
    long long h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return (int)h;
}

int add_and_get_count(long long age) {
    int h = get_hash(age);
    HashNode *curr = hash_table[h];
    while (curr != NULL) {
        if (curr->age == age) {
            curr->count++;
            return curr->count;
        }
        curr = curr->next;
    }
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    new_node->age = age;
    new_node->count = 1;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
    return 1;
}

long long arr[100005];

int main() {
    int n;
    long long m;
    if (scanf("%d %lld", &n, &m) != 2) return 0;

    for (int j = 0; j < n; j++) {
        scanf("%lld", &arr[j]);
    }

    long long best_age = 0;
    int max_count = 0;

    int cnt = add_and_get_count(arr[0]);
    best_age = arr[0];
    max_count = cnt;
    printf("%lld %d\n", best_age, max_count);

    int i;
    for(i = 0;i<n-1;i++) {
        long long age = arr[i + 1];
        int current_count = add_and_get_count(age);

        if (current_count > max_count) {
            max_count = current_count;
            best_age = age;
        } else if (current_count == max_count) {
            if (age > best_age) {
                best_age = age;
            }
        }
        printf("%lld %d\n", best_age, max_count);
    }

    return 0;
}