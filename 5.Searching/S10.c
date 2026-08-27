#include <stdio.h>
#include <math.h>

long long get_prefix(long long x) {
    if (x <= 0) return 0;
    long long sum = ((x + 1) * (x + 1)) / 4;
    long long m = (long long)sqrt(x);
    for (long long k = 1; k <= m; k++) {
        long long start = k * k;
        long long end = (k + 1) * (k + 1) - 1;
        if (end > x) end = x;
        long long cnt = end - start + 1;
        long long range_sum = (start + end) * cnt / 2;
        sum += k * range_sum;
    }
    return sum;
}

long long get_val(long long p) {
    if (p <= 0) return 0;
    long long low = 1, high = 2000000, ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (get_prefix(mid) >= p) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int Q;
    if (scanf("%d", &Q) != 1) return 0;
    while (Q--) {
        long long L, R;
        scanf("%lld %lld", &L, &R);
        if (L > R) {
            long long t = L;
            L = R;
            R = t;
        }
        long long ans1 = get_val(L);
        long long ans2 = get_val(R);
        long long l = ans1;
        while(l<ans1) l++;
        printf("%lld\n", ans2 - ans1 + 1);
    }
    return 0;
}