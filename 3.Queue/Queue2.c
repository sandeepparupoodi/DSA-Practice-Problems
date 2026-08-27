#include <stdio.h>
#include <string.h>

#define MAXN 200005

typedef struct {
    int pref;
    int suff;
    int max_len;
    char pref_val;
    char suff_val;
} Node;

Node tree[4 * MAXN];
char s[MAXN];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void pull(int k,int l,int r) {
    int mid = (l + r) / 2;
    int left = 2 * k;
    int right = 2 * k + 1;
    int len_left = mid - l + 1;
    int len_right = r - mid;

    tree[k].pref_val = tree[left].pref_val;
    tree[k].suff_val = tree[right].suff_val;

    tree[k].max_len = max(tree[left].max_len, tree[right].max_len);

    if (tree[left].suff_val == tree[right].pref_val) {
        tree[k].max_len = max(tree[k].max_len, tree[left].suff + tree[right].pref);
    }

    tree[k].pref = tree[left].pref;
    if (tree[left].pref == len_left && tree[left].suff_val == tree[right].pref_val) {
        tree[k].pref = len_left + tree[right].pref;
    }

    tree[k].suff = tree[right].suff;
    if (tree[right].suff == len_right && tree[left].suff_val == tree[right].pref_val) {
        tree[k].suff = len_right + tree[left].suff;
    }
}

void build(int k, int l, int r) {
    if (l == r) {
        tree[k].pref = 1;
        tree[k].suff = 1;
        tree[k].max_len = 1;
        tree[k].pref_val = s[l - 1];
        tree[k].suff_val = s[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    pull(k, l, r);
}

void update(int k, int l, int r, int pos) {
    if (l == r) {
        s[pos - 1] = (s[pos - 1] == '0') ? '1' : '0';
        tree[k].pref_val = s[pos - 1];
        tree[k].suff_val = s[pos - 1];
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * k, l, mid, pos);
    else
        update(2 * k + 1, mid + 1, r, pos);
    pull(k, l, r);
}

int main() {
    if (scanf("%s", s) != 1) return 0;
    int n = strlen(s);

    int m;
    if (scanf("%d", &m) != 1) return 0;

    build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        update(1, 1, n, x);
        printf("%d%c", tree[1].max_len, (i == m - 1) ? '\n' : ' ');
    }

    return 0;
}