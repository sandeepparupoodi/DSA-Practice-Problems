#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BOYS 1005
#define MAX_GIRLS 1005
#define MAX_EDGES 2005
#define INF 1e9

int head[MAX_BOYS], to[MAX_EDGES], next_edge[MAX_EDGES], edge_cnt = 0;
int match_boy[MAX_BOYS], match_girl[MAX_GIRLS];
int dist[MAX_BOYS];
int queue[MAX_BOYS];

void link(int u, int v) {
    edge_cnt++;
    to[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt;
}

int bfs(int n) {
    int q_head = 0, q_tail = 0;
    for (int u = 1; u <= n; ++u) {
        if (match_boy[u] == 0) {
            dist[u] = 0;
            queue[q_tail++] = u;
        } else {
            dist[u] = INF;
        }
    }

    dist[0] = INF;

    while (q_head < q_tail) {
        int u = queue[q_head++];
        if (dist[u] < dist[0]) {
            for (int e = head[u]; e != 0; e = next_edge[e]) {
                int v = to[e];
                int paired_boy = match_girl[v];
                if (dist[paired_boy] == INF) {
                    dist[paired_boy] = dist[u] + 1;
                    queue[q_tail++] = paired_boy;
                }
            }
        }
    }
    return (dist[0] != INF);
}

bool dfs(int u) {
    if (u == 0) return true;

    for (int e = head[u]; e != 0; e = next_edge[e]) {
        int v = to[e];
        int paired_boy = match_girl[v];
        if (dist[paired_boy] == dist[u] + 1) {
            if (dfs(paired_boy)) {
                match_girl[v] = u;
                match_boy[u] = v;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    for (int i = 0; i < k; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u, v);
    }

    int max_matching = 0;
    while (bfs(n)) {
        for (int u = 1; u <= n; ++u) {
            if (match_boy[u] == 0) {
                if (dfs(u)) {
                    max_matching++;
                }
            }
        }
    }

    printf("%d\n", max_matching);
    for (int u = 1; u <= n; ++u) {
        if (match_boy[u] != 0) {
            printf("%d %d\n", u, match_boy[u]);
        }
    }

    return 0;
}