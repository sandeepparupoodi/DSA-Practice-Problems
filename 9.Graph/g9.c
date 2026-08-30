#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 505

int capacity[MAXN][MAXN];
int flow[MAXN][MAXN];
int parent_node[MAXN];
int queue[MAXN];

int bfs(int n, int s, int t) {
    memset(parent_node, 0, sizeof(parent_node));
    int head = 0, tail = 0;

    queue[tail++] = s;
    parent_node[s] = -1;

    while (head < tail) {
        int u = queue[head++];

        for (int v = 1; v <= n; v++) {
            if (parent_node[v] == 0 && capacity[u][v] - flow[u][v] > 0) {
                parent_node[v] = u;
                if (v == t) return 1;
                queue[tail++] = v;
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        capacity[u][v] += 1;
    }

    int s = 1, t = n;
    int max_days = 0;

    // Edmonds-Karp Max Flow
    while (bfs(n, s, t)) {
        int curr = t;
        while (curr != s) {
            int prev = parent_node[curr];
            flow[prev][curr] += 1;
            flow[curr][prev] -= 1;
            curr = prev;
        }
        max_days++;
    }

    printf("%d\n", max_days);

    // Reconstruct each path
    int path[MAXN];
    for (int day = 0; day < max_days; day++) {
        int path_len = 0;
        int curr = s;
        path[path_len++] = curr;

        while (curr != t) {
            for (int next = 1; next <= n; next++) {
                if (flow[curr][next] > 0) {
                    flow[curr][next]--; // consume this edge
                    curr = next;
                    path[path_len++] = curr;
                    break;
                }
            }
        }

        printf("%d\n", path_len);
        for (int i = 0; i < path_len; i++) {
            printf("%d%c", path[i], (i == path_len - 1) ? '\n' : ' ');
        }
    }

    return 0;
}