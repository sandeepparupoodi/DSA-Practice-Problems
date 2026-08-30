#include <stdio.h>

#define MAXN 200005

int tree[4 * MAXN];
int a[MAXN];

void build(int k,int l,int r) {
    if (l == r) {
        tree[k] = 1; 
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}

int query_and_remove(int k, int l, int r, int p) {
    if (l == r) {
        tree[k] = 0; 
        return l;
    }
    int mid = (l + r) / 2;
    int idx;
    if (tree[2 * k] >= p) {
        idx = query_and_remove(2 * k, l, mid, p);
    } else {
        idx = query_and_remove(2 * k + 1, mid + 1, r, p - tree[2 * k]);
    }
    tree[k] = tree[2 * k] + tree[2 * k + 1];
    return idx;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    build(1, 1, n);

    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        int original_idx = query_and_remove(1, 1, n, p);
        printf("%d ", a[original_idx]);
    }
    printf("\n");

    return 0;
}