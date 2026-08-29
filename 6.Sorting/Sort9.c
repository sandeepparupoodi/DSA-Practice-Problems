#include <stdio.h>
#include <string.h>

int max(int a,int b) {
    return (a > b) ? a : b;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, k, p;
        scanf("%d %d %d", &n, &k, &p);

        int dp[p + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0;i < n;i++) {
            int pref[k + 1];
            pref[0] = 0;

            for (int j = 1; j <= k; j++) {
                int val;
                scanf("%d", &val);
                pref[j] = pref[j - 1] + val;
            }

            int next_dp[p + 1];
            for (int j = 0; j <= p; j++) {
                next_dp[j] = dp[j];
            }

            for (int j = 0; j <= p; j++) {
                for (int x = 1; x <= k && x <= j; x++) {
                    next_dp[j] = max(next_dp[j], dp[j - x] + pref[x]);
                }
            }

            for (int j = 0; j <= p; j++) {
                dp[j] = next_dp[j];
            }
        }

        printf("%d\n", dp[p]);
    }

    return 0;
}