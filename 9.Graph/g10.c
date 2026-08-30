#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 505
#define MAXM 2005

int capacity[MAXN][MAXN];
int flow_net[MAXN][MAXN];
int parent_node[MAXN];
int queue[MAXN];
bool visited[MAXN];

int edge_u[MAXM], edge_v[MAXM], edge_total = 0;

void link(int i, int h) {
    capacity[i][h] += 1;
    capacity[h][i] += 1;
    edge_u[edge_total] = i;
    edge_v[edge_total] = h;
    edge_total++;
}

int bfs(int n, int s, int t) {
    memset(parent_node, 0, sizeof(parent_node));
    int head = 0, tail = 0;

    queue[tail++] = s;
    parent_node[s] = -1;

    while (head < tail) {
        int u = queue[head++];

        for (int v = 1; v <= n; v++) {
            if (parent_node[v] == 0 && capacity[u][v] - flow_net[u][v] > 0) {
                parent_node[v] = u;
                if (v == t) return 1;
                queue[tail++] = v;
            }
        }
    }
    return 0;
}

void dfs_reach(int u, int n) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && capacity[u][v] - flow_net[u][v] > 0) {
            dfs_reach(v, n);
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    memset(capacity, 0, sizeof(capacity));
    memset(flow_net, 0, sizeof(flow_net));

    for (int idx = 0; idx < m; idx++) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u, v);
    }

    int s = 1, t = n;

    while (bfs(n, s, t)) {
        int curr = t;
        while (curr != s) {
            int prev = parent_node[curr];
            flow_net[prev][curr] += 1;
            flow_net[curr][prev] -= 1;
            curr = prev;
        }
    }

    memset(visited, false, sizeof(visited));
    dfs_reach(s, n);

    int cut_edges[MAXM][2];
    int cut_count = 0;

    for (int i = 0; i < edge_total; i++) {
        int u = edge_u[i];
        int v = edge_v[i];
        if (visited[u] != visited[v]) {
            cut_edges[cut_count][0] = u;
            cut_edges[cut_count][1] = v;
            cut_count++;
        }
    }

    printf("%d\n", cut_count);
    for (int i = 0; i < cut_count; i++) {
        printf("%d %d\n", cut_edges[i][0], cut_edges[i][1]);
    }

    return 0;
}