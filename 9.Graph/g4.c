#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int parent_arr[MAXN];
int rep[MAXN];

int find_set(int v) {
    if (v == parent_arr[v])
        return v;
    return parent_arr[v] = find_set(parent_arr[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_arr[b] = a;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    for (int i = 1; i <= n; i++) {
        parent_arr[i] = i;
    }

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        union_sets(u, v);
    }

    int rep_count = 0;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i) {
            rep[rep_count++] = i;
        }
    }

    int k = rep_count - 1;
    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%d %d\n", rep[i], rep[i + 1]);
    }

    return 0;
}