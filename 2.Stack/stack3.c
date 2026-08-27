#include <stdio.h>
#include <stdlib.h>

int get_digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    int *arr2 = (int *)malloc((n + 1) * sizeof(int)); // Digit sums

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr2[i] = get_digit_sum(arr[i]);
    }

    while (q--) {
        int x;
        scanf("%d", &x);

        int ans = -1;
        for (int y = x + 1; y <= n; y++) {
            if (arr[x] < arr[y]) {
                if (arr2[x] > arr2[y]) {
                    ans = y;
                    break;
                }
            }
        }
        printf("%d ", ans);
    }
    printf("\n");

    free(arr);
    free(arr2);
    return 0;
}