#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *a = (long long *)malloc(n * sizeof(long long));
    int *F = (int *)malloc(n * sizeof(int));
    int *G = (int *)malloc(n * sizeof(int));

    for (int k = 0; k < n; k++) {
        scanf("%lld", &a[k]);
    }

    int i, j;

    for (i = 0; i < n; i++) {
        F[i] = -1;
        for (j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                F[i] = j;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        G[i] = -1;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                G[i] = j;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (F[i] != -1 && G[F[i]] != -1) {
            printf("%lld ", a[G[F[i]]]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");

    free(a);
    free(F);
    free(G);
    return 0;
}