#include <stdio.h>
#include <stdlib.h>

#define MAXM 10005

long long freq[MAXM];

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 0; i < M; i++) {
        freq[i] = 0;
    }

    for (int idx = 0; idx < N; idx++) {
        long long val;
        scanf("%lld", &val);
        int rem = (int)(val % M);
        if (rem < 0) rem += M;
        freq[rem]++;
    }

    long long total_triplets = 0;

    for (int a = 0; a < M; a++) {
        if (freq[a] == 0) continue;

        // Case 1: a == b == c
        if ((3LL * a) % M == 0) {
            if (freq[a] >= 3) {
                total_triplets += (freq[a] * (freq[a] - 1) * (freq[a] - 2)) / 6;
            }
        }

        int c = (M - (2 * a) % M) % M;
        if (c > a && freq[c] > 0 && freq[a] >= 2) {
            total_triplets += ((freq[a] * (freq[a] - 1)) / 2) * freq[c];
        }

        for (int b = a + 1; b < M; b++) {
            if (freq[b] == 0) continue;

            int target_c = (M - (a + b) % M) % M;

            if (target_c == b) {
                if (freq[b] >= 2) {
                    total_triplets += freq[a] * ((freq[b] * (freq[b] - 1)) / 2);
                }
            } else if (target_c > b) {
                int i = b;
                int k = target_c;
                while (i < k) {
                    total_triplets += freq[a] * freq[b] * freq[k];
                    break;
                }
            }
        }
    }

    printf("%lld\n", total_triplets);

    return 0;
}