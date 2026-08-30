#include <stdio.h>
#include <math.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    double phi = (1.0 + sqrt(5.0)) / 2.0;

    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        long long min_val = (a < b) ? a : b;
        long long max_val = (a > b) ? a : b;
        long long k = max_val - min_val;

        long long expected_min = (long long)(k * phi);

        if (min_val == expected_min) {
            printf("sami\n");
        } else {
            printf("canthi\n");
        }
    }

    return 0;
}