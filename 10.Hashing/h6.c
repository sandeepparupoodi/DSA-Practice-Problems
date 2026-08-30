#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000005

int hash[MAX_VAL] = {0};

int main() {
    int M, Q, N;
    if (scanf("%d", &M) != 1) return 0;
    scanf("%d", &Q);
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    int max_val = 0;
    int i;

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        hash[A[i]]++;
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    int max_rating = 0;

    for (i = 1; i <= max_val; i++) {
        int current_count = 0;
        for (int k = -Q; k <= Q; k++) {
            int val = i + k * M;
            if (val >= 1 && val <= max_val) {
                current_count += hash[val];
            }
        }
        if (current_count > max_rating) {
            max_rating = current_count;
        }
    }

    printf("%d\n", max_rating);

    free(A);
    return 0;
}