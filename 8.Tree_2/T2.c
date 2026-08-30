#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

long long a[MAXN];
long long ans[MAXN];

int cmp(const void *p1, const void *p2) {
    long long x = *(long long *)p1;
    long long y = *(long long *)p2;
    return (x > y) - (x < y);
}

int main() {
    int n, q, i;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    long long total = 0;
    for(i=0;i<n;i++) {
        scanf("%lld", &a[i]);
        total += a[i];
    }

    qsort(a, n, sizeof(long long), cmp);

    int l = 0, r = n - 1;
    ans[0] = total;

    for (int k = 1; k < n; k++) {
        long long mn = a[l++];
        long long mx = a[r--];
        long long diff = mx - mn;
        total -= 2 * mn;
        ans[k] = total;
        int pos = r;
        while (pos >= l && a[pos] > diff) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = diff;
        r++;
    }

    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", ans[k]);
    }

    return 0;
}