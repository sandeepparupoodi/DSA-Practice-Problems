#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int biggest = -1;
    int big = -1;
    int small = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > biggest) {
            small = big;
            big = biggest;
            biggest = a[i];
        } else if (a[i] > big) {
            small = big;
            big = a[i];
        } else if (a[i] > small) {
            small = a[i];
        }

        if (biggest < big) {
            int temp = biggest;
            biggest = big;
            big = temp;
        }

        if (i < 2) {
            printf("-1\n");
        } else {
            long long product = (long long)biggest * big * small;
            printf("%lld\n", product);
        }
    }

    return 0;
}