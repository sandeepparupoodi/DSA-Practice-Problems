#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int head[MAXN], to[2 * MAXN], next_edge[2 * MAXN], edge_cnt = 0;
char s[MAXN];
int cnt[MAXN][26];

void add_edge(int u, int v) {
    to[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt++;

    to[edge_cnt] = u;
    next_edge[edge_cnt] = head[v];
    head[v] = edge_cnt++;
}

void dfs(int u, int p) {
    cnt[u][s[u - 1] - 'a'] = 1;

    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to[e];
        if (v != p) {
            dfs(v, u);
            for (int ch = 0; ch < 26; ch++) {
                cnt[u][ch] += cnt[v][ch];
            }
        }
    }
}

int main() {
    int N, Q, i;
    if (scanf("%d %d", &N, &Q) != 2) return 0;

    scanf("%s", s);

    for (i = 1; i <= N; i++) {
        head[i] = -1;
    }

    for(i = 0;i<N-1;i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    dfs(1, 0);

    while(Q--) {
        int u;
        char c;
        scanf("%d %c", &u, &c);
        printf("%d\n", cnt[u][c - 'a']);
    }

    return 0;
}