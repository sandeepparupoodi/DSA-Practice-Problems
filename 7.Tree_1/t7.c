#include <stdio.h>
#include <stdlib.h>

const int MAXL=200005;

typedef struct state {
    int len, link;
    int next[100];
} state;

// Using a pointer or dynamic allocation satisfies both C rules and the keywords
state *st;
int sz;

void sam_init() {
    st = (state*)malloc(sizeof(state) * MAXL);
    st[0].len = 0;
    st[0].link = -1;
    for (int i = 0; i < 100; i++) st[0].next[i] = 0;
    sz = 1;
}

int sam_extend(int c, int last_node) {
    if (st[last_node].next[c]) {
        int q = st[last_node].next[c];
        if (st[q].len == st[last_node].len + 1) {
            return q;
        }
        int clone = sz++;
        st[clone].len = st[last_node].len + 1;
        for (int i = 0; i < 100; i++) st[clone].next[i] = st[q].next[i];
        st[clone].link = st[q].link;
        while (last_node != -1 && st[last_node].next[c] == q) {
            st[last_node].next[c] = clone;
            last_node = st[last_node].link;
        }
        st[q].link = clone;
        return clone;
    }

    int cur = sz++;
    st[cur].len = st[last_node].len + 1;
    for (int i = 0; i < 100; i++) st[cur].next[i] = 0;

    int p = last_node;
    while (p != -1 && !st[p].next[c]) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            for (int i = 0; i < 100; i++) st[clone].next[i] = st[q].next[i];
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    return cur;
}

#define MAXN 100005

int head[MAXN], to[2 * MAXN], nxt[2 * MAXN], edge_cnt;
int deg[MAXN];

void add_edge(int u, int v) {
    to[++edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt;
}

void dfs(int u, int p, int last_sam) {
    int cur_sam = sam_extend(deg[u], last_sam);
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != p) {
            dfs(v, u, cur_sam);
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
        deg[u]++;
        deg[v]++;
    }

    sam_init();
    dfs(1, 0, 0);

    long long distinct_trips = 0;
    for (int i = 1; i < sz; i++) {
        distinct_trips += st[i].len - st[st[i].link].len;
    }

    printf("%lld\n", distinct_trips);

    return 0;
}