#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 200005
#define MAXE 400005

int head[MAXV], to[MAXE], next_edge[MAXE], edge_cnt = 0;
int dfn[MAXV], low[MAXV], scc[MAXV], stack_arr[MAXV];
bool in_stack[MAXV];
int timer = 0, top = 0, scc_cnt = 0;

void link(int i, int j) {
    edge_cnt++;
    to[edge_cnt] = j;
    next_edge[edge_cnt] = head[i];
    head[i] = edge_cnt;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stack_arr[++top] = u;
    in_stack[u] = true;

    for (int e = head[u]; e != 0; e = next_edge[e]) {
        int v = to[e];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        scc_cnt++;
        while (1) {
            int v = stack_arr[top--];
            in_stack[v] = false;
            scc[v] = scc_cnt;
            if (u == v) break;
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        char s1, s2;
        int u, v;
        scanf(" %c %d %c %d", &s1, &u, &s2, &v);

        int lit1 = (s1 == '+') ? (2 * (u - 1)) : (2 * (u - 1) + 1);
        int lit2 = (s2 == '+') ? (2 * (v - 1)) : (2 * (v - 1) + 1);

        link(lit1 ^ 1, lit2);
        link(lit2 ^ 1, lit1);
    }

    int total_nodes = 2 * m;
    for (int i = 0; i < total_nodes; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        int pos_node = 2 * (i - 1);
        int neg_node = 2 * (i - 1) + 1;
        if (scc[pos_node] == scc[neg_node]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        int pos_node = 2 * (i - 1);
        int neg_node = 2 * (i - 1) + 1;
        if (scc[pos_node] < scc[neg_node]) {
            printf("+ ");
        } else {
            printf("- ");
        }
    }
    printf("\n");

    return 0;
}