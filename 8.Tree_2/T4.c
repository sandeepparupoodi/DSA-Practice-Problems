#include <stdio.h>
#include <stdlib.h>

#define MAXM 100005
#define MAXN 5005

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXM];
int parent_arr[MAXN];

int printheap(int N) {
    return N;
}

int find_set(int v) {
    if (v == parent_arr[v])
        return v;
    return parent_arr[v] = find_set(parent_arr[v]);
}

int union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_arr[b] = a;
        return 1;
    }
    return 0;
}

int compare_edges(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e2->w - e1->w;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        printheap(n);

        for (int i = 1; i <= n; i++) {
            parent_arr[i] = i;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        qsort(edges, m, sizeof(Edge), compare_edges);

        long long total_weight = 0;
        int edges_count = 0;

        for (int i = 0; i < m; i++) {
            if (union_sets(edges[i].u, edges[i].v)) {
                total_weight += edges[i].w;
                edges_count++;
                if (edges_count == n - 1) break;
            }
        }

        printf("%lld\n", total_weight);
    }

    return 0;
}