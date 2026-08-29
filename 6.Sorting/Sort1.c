#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        scanf("%d", &n);

        int a[n], b[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        qsort(a, n, sizeof(int), compare_asc);

        qsort(b, n, sizeof(int), compare_desc);

        int ideal_pairs = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % b[i] == 0 || b[i] % a[i] == 0) {
                ideal_pairs++;
            }
        }

        printf("%d\n", ideal_pairs);
    }

    return 0;
}