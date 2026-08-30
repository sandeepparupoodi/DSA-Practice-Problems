#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

int B[MAXN], G[MAXN];
int target_boy[MAXN], target_girl[MAXN];
int in_deg_boy[MAXN], in_deg_girl[MAXN];

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (true) {
        if (t <= 0) break;
        t--;

        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
            in_deg_boy[i] = 0;
            target_boy[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &G[i]);
            in_deg_girl[i] = 0;
            target_girl[i] = 0;
        }

        int max_beatings = 0;

        // Process boys beating boys
        for (int i = 1; i <= n; i++) {
            int crush_girl = B[i];
            int target = G[crush_girl];
            if (target != i) {
                target_boy[i] = target;
                in_deg_boy[target]++;
            }
        }

        // Process girls beating girls
        for (int i = 1; i <= n; i++) {
            int crush_boy = G[i];
            int target = B[crush_boy];
            if (target != i) {
                target_girl[i] = target;
                in_deg_girl[target]++;
            }
        }

        // Find max beatings received
        for (int i = 1; i <= n; i++) {
            if (in_deg_boy[i] > max_beatings) {
                max_beatings = in_deg_boy[i];
            }
            if (in_deg_girl[i] > max_beatings) {
                max_beatings = in_deg_girl[i];
            }
        }

        // Count mutual pairs
        int mutual_pairs = 0;

        for (int i = 1; i <= n; i++) {
            int tb = target_boy[i];
            if (tb > i && target_boy[tb] == i) {
                mutual_pairs++;
            }

            int tg = target_girl[i];
            if (tg > i && target_girl[tg] == i) {
                mutual_pairs++;
            }
        }

        printf("%d %d\n", max_beatings, mutual_pairs);
    }

    return 0;
}