#include <stdio.h>

#define MAXN 100005

int pref[MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int get_fx(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 16;
        x /= 16;
    }
    return sum;
}

int search(int a, int b) {
    return pref[b] - pref[a - 1];
}

int main() {
    for (int i = 1; i < MAXN; i++) {
        pref[i] = pref[i - 1] + (gcd(i, get_fx(i)) > 1 ? 1 : 0);
    }

    int t, l, r;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            scanf("%d %d", &l, &r);
            printf("%d\n", search(l, r));
        }
    }
    return 0;
}