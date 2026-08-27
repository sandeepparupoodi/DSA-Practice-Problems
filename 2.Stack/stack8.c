#include <stdio.h>

long long arr[1000000];
long long st[1000000];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int i, j;
    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    for (i = n - 1; i >= 0; i--) {
        st[i] = arr[i];
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                st[i] = arr[i] ^ st[j];
                break;
            }
        }
    }

    long long max_stamina = 0;
    for (i = 0; i < n; i++) {
        if (st[i] > max_stamina) {
            max_stamina = st[i];
        }
    }

    printf("%lld\n", max_stamina);

    return 0;
}