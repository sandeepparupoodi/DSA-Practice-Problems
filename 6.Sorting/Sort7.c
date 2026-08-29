#include <stdio.h>

void sort(int a[],int n,int flag) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (flag == 1) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            } else {
                if (a[j] < a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
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

        sort(a, n, 1);

        sort(b, n, 0);

        long long min_sum = 0;
        for (int i = 0; i < n; i++) {
            min_sum += (long long)a[i] * b[i];
        }

        printf("%lld\n", min_sum);
    }

    return 0;
}