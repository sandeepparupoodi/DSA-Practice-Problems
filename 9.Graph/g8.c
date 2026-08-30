#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 200005
#define MAXE 400005

int head[MAXN], to[MAXE], next_edge[MAXE], edge_cnt = 0;
bool matched[MAXN];
int ans = 0;

void link(int i, int j) {
    edge_cnt++;
    to[edge_cnt] = j;
    next_edge[edge_cnt] = head[i];
    head[i] = edge_cnt;
}

void dfs(int p, int i) {
    for (int e = head[i]; e != 0; e = next_edge[e]) {
        int v = to[e];
        if (v != p) {
            dfs(i, v);
            if (!matched[i] && !matched[v]) {
                matched[i] = true;
                matched[v] = true;
                ans++;
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int k = 0; k < n - 1; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u, v);
        link(v, u);
    }

    dfs(0, 1);

    printf("%d\n", ans);

    return 0;
}