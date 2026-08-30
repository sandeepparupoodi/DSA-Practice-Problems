#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005
#define MAXVAL 600005

typedef struct {
    char type;
    int a;
    int b;
} Query;

int p[MAXN];
Query queries[MAXN];
int vals[MAXVAL];
int bit[MAXVAL];
int total_vals;

int compare(const void *a,const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int get_id(int val) {
    int l = 0, r = total_vals - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (vals[mid] == val) return mid + 1;
        if (vals[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return l + 1;
}

int get_upper_id(int val) {
    int l = 0, r = total_vals - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (vals[mid] <= val) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans + 1;
}

int get_lower_id(int val) {
    int l = 0, r = total_vals - 1, ans = total_vals;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (vals[mid] >= val) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans + 1;
}

void update(int i,int n,int x) {
    for (; i <= n; i += (i & -i)) {
        bit[i] += x;
    }
}

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= (i & -i)) {
        sum += bit[i];
    }
    return sum;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int v_count = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        vals[v_count++] = p[i];
    }

    for (int i = 0; i < q; i++) {
        scanf(" %c %d %d", &queries[i].type, &queries[i].a, &queries[i].b);
        if (queries[i].type == '!') {
            vals[v_count++] = queries[i].b;
        } else {
            vals[v_count++] = queries[i].a;
            vals[v_count++] = queries[i].b;
        }
    }

    qsort(vals, v_count, sizeof(int), compare);
    total_vals = 0;
    for (int i = 0; i < v_count; i++) {
        if (i == 0 || vals[i] != vals[i - 1]) {
            vals[total_vals++] = vals[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        int id = get_id(p[i]);
        update(id, total_vals, 1);
    }

    for (int i = 0; i < q; i++) {
        if (queries[i].type == '!') {
            int k = queries[i].a;
            int new_val = queries[i].b;
            int old_id = get_id(p[k]);
            int new_id = get_id(new_val);
            update(old_id, total_vals, -1);
            update(new_id, total_vals, 1);
            p[k] = new_val;
        } else {
            int a = queries[i].a;
            int b = queries[i].b;
            int right_id = get_upper_id(b);
            int left_id = get_lower_id(a);
            int ans = query(right_id) - query(left_id - 1);
            printf("%d\n", ans);
        }
    }

    return 0;
}