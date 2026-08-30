#include <stdio.h>

#define MAXN 100005

int parent_node[MAXN];
int sz[MAXN];
int components;
int max_size;

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

int join(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);

    if (root_i != root_j) {
        if (sz[root_i] < sz[root_j]) {
            int temp = root_i;
            root_i = root_j;
            root_j = temp;
        }

        parent_node[root_j] = root_i;
        sz[root_i] += sz[root_j];

        if (sz[root_i] > max_size) {
            max_size = sz[root_i];
        }

        components--;
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    components = n;
    max_size = 1;

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        sz[i] = 1;
    }

    for (int k = 0; k < m; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        join(u, v);
        printf("%d %d\n", components, max_size);
    }

    return 0;
}