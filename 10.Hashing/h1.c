#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000003

typedef struct Node {
    long long key;
    struct Node* next;
} Node;

Node* hash_table[HASH_SIZE];

int hash_func(long long key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}

int insert(long long key) {
    int idx = hash_func(key);
    Node* curr = hash_table[idx];
    while (curr != NULL) {
        if (curr->key == key) return 0;
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hash_table[idx];
    hash_table[idx] = newNode;
    return 1;
}

int main() {
    int n, i;
    if (scanf("%d", &n) != 1) return 0;

    long long arr[n];
    long long max = 0;

    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int suffix_unique[n + 1];
    suffix_unique[n] = 0;

    int distinct_count = 0;
    for (i = n - 1; i >= 0; i--) {
        if (insert(arr[i])) {
            distinct_count++;
        }
        suffix_unique[i] = distinct_count;
    }

    for (i = 0; i < HASH_SIZE; i++) {
        Node* curr = hash_table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hash_table[i] = NULL;
    }

    long long total_pairs = 0;
    for (i = 0; i < n; i++) {
        if (insert(arr[i])) {
            total_pairs += suffix_unique[i + 1];
        }
    }

    printf("%lld\n", total_pairs);

    return 0;
}