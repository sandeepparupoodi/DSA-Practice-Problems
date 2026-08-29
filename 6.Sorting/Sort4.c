#include <stdio.h>

void bubble_sort(int arr[],int no) {
    int i, j, temp;
    for (i = 0; i < no - 1; i++) {
        for (j = 0; j < no - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int MEGA_SALE(int arr[],int no,int k) {
    bubble_sort(arr, no);
    
    int max_earn = 0;
    for (int i = 0; i < k && i < no; i++) {
        if (arr[i] < 0) {
            max_earn += -arr[i];
        } else {
            break;
        }
    }
    return max_earn;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int result = MEGA_SALE(arr, n, m);
        printf("%d\n", result);
    }

    return 0;
}