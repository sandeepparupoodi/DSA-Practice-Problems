#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
typedef unsigned long long ull;

const ull BASE = 1000000007ULL;
const ull LEAF_VAL = 1234567891ULL;

typedef struct {
    int *head;
    int *to;
    int *next;
    int edge_cnt;
} Tree;

void init_tree(Tree *tr, int n) {
    for (int i = 1; i <= n; i++) tr->head[i] = -1;
    tr->edge_cnt = 0;
}

void add_edge(Tree *tr, int u, int v) {
    tr->to[tr->edge_cnt] = v;
    tr->next[tr->edge_cnt] = tr->head[u];
    tr->head[u] = tr->edge_cnt++;

    tr->to[tr->edge_cnt] = u;
    tr->next[tr->edge_cnt] = tr->head[v];
    tr->head[v] = tr->edge_cnt++;
}

int cmp_ull(const void *a, const void *b) {
    ull x = *(const ull *)a;
    ull y = *(const ull *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

ull get_hash(Tree *tr, int u, int p) {
    ull child_hashes[MAXN];
    int child_cnt = 0;

    for (int e = tr->head[u]; e != -1; e = tr->next[e]) {
        int v = tr->to[e];
        if (v != p) {
            child_hashes[child_cnt++] = get_hash(tr, v, u);
        }
    }

    if (child_cnt == 0) {
        return LEAF_VAL;
    }

    qsort(child_hashes, child_cnt, sizeof(ull), cmp_ull);

    ull h = BASE;
    for (int i = 0; i < child_cnt; i++) {
        h = h * BASE + child_hashes[i];
    }
    return h;
}

int head1[MAXN], to1[2 * MAXN], next1[2 * MAXN];
int head2[MAXN], to2[2 * MAXN], next2[2 * MAXN];

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    Tree tr1 = {head1, to1, next1, 0};
    Tree tr2 = {head2, to2, next2, 0};

    while (t--) {
        int n;
        scanf("%d", &n);

        init_tree(&tr1, n);
        init_tree(&tr2, n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(&tr1, u, v);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(&tr2, u, v);
        }

        ull hash1 = get_hash(&tr1, 1, 0);
        ull hash2 = get_hash(&tr2, 1, 0);

        if (hash1 == hash2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}