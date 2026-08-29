#include <stdio.h>
#include <stdlib.h>

void insertionSort(long int *p,long int n) {
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    while (q--) {
        long int n;
        scanf("%ld", &n);

        long int row_sum[n];
        long int col_sum[n];
        long int i, j;

        for (i = 0; i < n; i++) {
            row_sum[i] = 0;
            col_sum[i] = 0;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                long int val;
                scanf("%ld", &val);
                row_sum[i] += val;
                col_sum[j] += val;
            }
        }

        insertionSort(row_sum, n);
        insertionSort(col_sum, n);

        int possible = 1;
        for (i = 0; i < n; i++) {
            if (row_sum[i] != col_sum[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}