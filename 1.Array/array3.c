#include <stdio.h>

void stockBuySell(int arr[], int n) {
    if (n <= 1) {
        printf("No Profit\n");
        return;
    }

    int i = 0;
    int count = 0;

    while (i < n - 1) {
        while (i < n - 1 && arr[i + 1] <= arr[i]) {
            i++;
        }

        if (i == n - 1) break;

        int buy = i;
        i++;

        while (i < n) {
            if(arr[i]>arr[i-1]) {
                i++;
            } else {
                break;
            }
        }

        int sell = i - 1;
        printf("(%d %d)", buy, sell);
        count++;
    }

    if (count == 0) {
        printf("No Profit");
    }
    printf("\n");
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            scanf("%d", &n);
            int arr[100];
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            stockBuySell(arr, n);
        }
    }
    return 0;
}