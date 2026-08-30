#include <stdio.h>

#define MAXN 1005

int p1[MAXN], p2[MAXN];
int ans_u[MAXN], ans_v[MAXN];

int find1(int x) {
    if (p1[x] == x) return x;
    return p1[x] = find1(p1[x]);
}

int find2(int x) {
    if (p2[x] == x) return x;
    return p2[x] = find2(p2[x]);
}

int main() {
    int n, m1, m2;
    if (scanf("%d %d %d", &n, &m1, &m2) != 3) return 0;

    for (int i = 1; i <= n; i++) {
        p1[i] = i;
        p2[i] = i;
    }

    while(m1--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int root_u = find1(u);
        int root_v = find1(v);
        if (root_u != root_v) {
            p1[root_u] = root_v;
        }
    }

    while (m2--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int root_u = find2(u);
        int root_v = find2(v);
        if (root_u != root_v) {
            p2[root_u] = root_v;
        }
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find1(i) != find1(j) && find2(i) != find2(j)) {
                p1[find1(i)] = find1(j);
                p2[find2(i)] = find2(j);
                ans_u[count] = i;
                ans_v[count] = j;
                count++;
            }
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", ans_u[i], ans_v[i]);
    }

    return 0;
}