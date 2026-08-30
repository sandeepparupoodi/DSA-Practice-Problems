#include <stdio.h>

#define MAXN 200005

typedef long long ll;

ll tree_sum[4 * MAXN];
ll lazy_c[4 * MAXN];
ll lazy_d[4 * MAXN];
ll arr[MAXN];

ll sum_indices(ll l, ll r) {
    return (l + r) * (r - l + 1) / 2;
}

void apply_lazy(int k, int l, int r, ll c, ll d) {
    tree_sum[k] += c * (r - l + 1) + d * sum_indices(l, r);
    lazy_c[k] += c;
    lazy_d[k] += d;
}

void push_down(int k, int l, int r) {
    if (lazy_c[k] == 0 && lazy_d[k] == 0) return;
    int mid = (l + r) / 2;
    apply_lazy(2 * k, l, mid, lazy_c[k], lazy_d[k]);
    apply_lazy(2 * k + 1, mid + 1, r, lazy_c[k], lazy_d[k]);
    lazy_c[k] = 0;
    lazy_d[k] = 0;
}

void build(int k, int l, int r) {
    lazy_c[k] = 0;
    lazy_d[k] = 0;
    if (l == r) {
        tree_sum[k] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree_sum[k] = tree_sum[2 * k] + tree_sum[2 * k + 1];
}

void update(int k, int l, int r, int ql, int qr, ll c, ll d) {
    if (ql <= l && r <= qr) {
        apply_lazy(k, l, r, c, d);
        return;
    }
    push_down(k, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) update(2 * k, l, mid, ql, qr, c, d);
    if (qr > mid) update(2 * k + 1, mid + 1, r, ql, qr, c, d);
    tree_sum[k] = tree_sum[2 * k] + tree_sum[2 * k + 1];
}

ll query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree_sum[k];
    }
    push_down(k, l, r);
    int mid = (l + r) / 2;
    ll res = 0;
    if (ql <= mid) res += query(2 * k, l, mid, ql, qr);
    if (qr > mid) res += query(2 * k + 1, mid + 1, r, ql, qr);
    return res;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }

    build(1, 1, n);

    while (q--) {
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1) {
            // Adding (i - a + 1) = 1 * i + (1 - a)
            update(1, 1, n, a, b, 1 - a, 1);
        } else if (type == 2) {
            printf("%lld\n", query(1, 1, n, a, b));
        }
    }

    return 0;
}