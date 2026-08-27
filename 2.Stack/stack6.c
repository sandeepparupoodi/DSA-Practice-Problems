#include <stdio.h>
#include <stdlib.h>

void calculateSpan(int price[], int n, int S[]) {
    int *st = (int *)malloc(n * sizeof(int));
    int top = -1;

    S[0] = 1;
    st[++top] = 0;

    for (int i = 1; i < n; i++) {
       
        while (top >= 0 && price[st[top]] <= price[i]) {
            top--;
        }

     
        S[i] = (top < 0) ? (i + 1) : (i - st[top]);

        st[++top] = i;
    }

    free(st);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *price = (int *)malloc(n * sizeof(int));
    int *S = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    calculateSpan(price, n, S);
    printArray(S, n);

    free(price);
    free(S);
    return 0;
}