#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int u, v;
    int l;
    int *tokens;
} Road;

int n, m, k;
long long c[100005];
Road roads[100005];
bool bought[100005];
int parent_arr[100005];

int find_root(int x) {
    if (parent_arr[x] == x)
        return x;
    return parent_arr[x] = find_root(parent_arr[x]);
}

bool union_nodes(int a, int b) {
    int rootA = find_root(a);
    int rootB = find_root(b);
    if (rootA != rootB) {
        parent_arr[rootA] = rootB;
        return true;
    }
    return false;
}

bool is_connected() {
    int i;
    for (i = 1; i <= n; ++i) {
        parent_arr[i] = i;
    }

    int components = n;

    for (int r = 0; r < m; ++r) {
        bool can_use = true;
        for (int t = 0; t < roads[r].l; ++t) {
            if (!bought[roads[r].tokens[t]]) {
                can_use = false;
                break;
            }
        }

        if (can_use) {
            if (union_nodes(roads[r].u, roads[r].v)) {
                components--;
            }
        }
    }

    return (components == 1);
}

int main() {
    if (scanf("%d %d %d", &n, &m, &k) != 3)
        return 0;

    for (int i = 1; i <= k; ++i) {
        scanf("%lld", &c[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &roads[i].u, &roads[i].v, &roads[i].l);
        roads[i].tokens = (int *)malloc(roads[i].l * sizeof(int));
        for (int j = 0; j < roads[i].l; ++j) {
            scanf("%d", &roads[i].tokens[j]);
        }
    }

    for (int i = 1; i <= k; ++i) {
        bought[i] = true;
    }

    if (!is_connected()) {
        printf("-1\n");
        return 0;
    }

    for (int t = k; t >= 1; --t) {
        bought[t] = false; 
        if (!is_connected()) {
            bought[t] = true; 
        }
    }

    long long total_cost = 0;
    for (int i = 1; i <= k; ++i) {
        if (bought[i]) {
            total_cost += c[i];
        }
    }

    printf("%lld\n", total_cost);

    return 0;
}