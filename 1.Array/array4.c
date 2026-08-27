#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int array[n];

    for(int i=0;i<n;i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(array[i]>array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < n - 1; i += 2) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }

    // Print the wave sorted array
    for (int i = 0; i < n; i++) {
        printf("%d%s", array[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}