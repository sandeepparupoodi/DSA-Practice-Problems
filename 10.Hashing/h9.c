#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000

int divisors[MAX_VAL + 1];
long long div_count_freq[1000];

void precompute_divisors() {
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = i; j <= MAX_VAL; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    precompute_divisors();

    int N;
    if (scanf("%d", &N) != 1) return 0;

    int val;
    scanf("%d", &val);
    div_count_freq[divisors[val]]++;

    while (--N) {
        scanf("%d", &val);
        div_count_freq[divisors[val]]++;
    }

    long long total_pairs = 0;
    for (int i = 0; i < 1000; i++) {
        if (div_count_freq[i] > 1) {
            total_pairs += (div_count_freq[i] * (div_count_freq[i] - 1)) / 2;
        }
    }

    printf("%lld\n", total_pairs);

    return 0;
}