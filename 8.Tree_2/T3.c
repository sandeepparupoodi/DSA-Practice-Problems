#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXM 200005

typedef struct {
    int head[MAXN];
    int to[MAXM];
    int next[MAXM];
    int edge_cnt;
} Graph;

Graph g, rg;

void init_graph(Graph *graph, int n) {
    for (int i = 1; i <= n; i++) graph->head[i] = -1;
    graph->edge_cnt = 0;
}

void add_edge(Graph *graph, int u, int v) {
    graph->to[graph->edge_cnt] = v;
    graph->next[graph->edge_cnt] = graph->head[u];
    graph->head[u] = graph->edge_cnt++;
}

int visited[MAXN];
int order[MAXN], order_len = 0;
int comp[MAXN], num_comps = 0;
int comp_rep[MAXN];

void dfs1(int u) {
    visited[u] = 1;
    for (int e = g.head[u]; e != -1; e = g.next[e]) {
        int v = g.to[e];
        if (!visited[v]) dfs1(v);
    }
    order[order_len++] = u;
}

void dfs2(int u, int c) {
    comp[u] = c;
    for (int e = rg.head[u]; e != -1; e = rg.next[e]) {
        int v = rg.to[e];
        if (comp[v] == 0) dfs2(v, c);
    }
}

int in_deg[MAXN], out_deg[MAXN];
int sources[MAXN], sinks[MAXN];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    init_graph(&g, n);
    init_graph(&rg, n);

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&g, u, v);
        add_edge(&rg, v, u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    for (int i = order_len - 1; i >= 0; i--) {
        int u = order[i];
        if (comp[u] == 0) {
            num_comps++;
            comp_rep[num_comps] = u;
            dfs2(u, num_comps);
        }
    }

    if (num_comps == 1) {
        printf("0\n");
        return 0;
    }

    for (int u = 1; u <= n; u++) {
        for (int e = g.head[u]; e != -1; e = g.next[e]) {
            int v = g.to[e];
            if (comp[u] != comp[v]) {
                out_deg[comp[u]]++;
                in_deg[comp[v]]++;
            }
        }
    }

    int src_cnt = 0, snk_cnt = 0;
    for (int i = 1; i <= num_comps; i++) {
        if (in_deg[i] == 0) sources[src_cnt++] = comp_rep[i];
        if (out_deg[i] == 0) sinks[snk_cnt++] = comp_rep[i];
    }

    int k = src_cnt > snk_cnt ? src_cnt : snk_cnt;
    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        int u = (i < snk_cnt) ? sinks[i] : sinks[0];
        int v = (i < src_cnt) ? sources[i] : sources[0];
        printf("%d %d\n", u, v);
    }

    return 0;
}