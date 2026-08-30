#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 300005

int parent_arr[MAXN];
int weight_to_parent[MAXN];
int cycle_flag[MAXN];

int dfs1(int np, int lst) {
    if (np == lst) return np;
    return dfs1(parent_arr[np], lst);
}

int find_set(int v, int *w) {
    if (v == parent_arr[v]) {
        *w = 0;
        return v;
    }
    int parent_w = 0;
    int root = find_set(parent_arr[v], &parent_w);
    *w = weight_to_parent[v] ^ parent_w;
    parent_arr[v] = root;
    weight_to_parent[v] = *w;
    return root;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        parent_arr[i] = i;
        weight_to_parent[i] = 0; 
        cycle_flag[i] = 0; 
    }

    while (q--) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);

        int wu = 0, wv = 0;
        int root_u = find_set(u, &wu);
        int root_v = find_set(v, &wv);

        if (root_u != root_v) {
            parent_arr[root_u] = root_v;
            weight_to_parent[root_u] = wu ^ wv ^ x;
            cycle_flag[root_v] |= cycle_flag[root_u];
            printf("YES\n");
        } else {
            int path_xor = wu ^ wv;
            int cycle_xor = path_xor ^ x;

            if (!cycle_flag[root_u] && cycle_xor == 1) {
                cycle_flag[root_u] = 1; // Mark component as containing a cycle
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}