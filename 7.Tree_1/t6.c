#include <stdio.h>

#define MAXN 200005
#define LOGN 20

int up[MAXN][LOGN];

void link(int i, int j) {
    up[i][0] = j;
}

int query(int x, int k) {
    for (int j = 0; j < LOGN; j++) {
        if ((k >> j) & 1) {
            x = up[x][j];
            if (x == 0) return -1;
        }
    }
    return (x == 0) ? -1 : x;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    up[1][0] = 0;

    // Read boss of employees 2 to n
    for (int i = 2; i <= n; i++) {
        int boss;
        scanf("%d", &boss);
        link(i, boss);
    }

    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != 0) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else {
                up[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        scanf("%d %d", &x, &k);
        printf("%d\n", query(x, k));
    }

    return 0;
}