#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL 200005

typedef struct {
    int val;
    int count;
} Node;

Node s[MAX_TOTAL];
int sz = 0;

int find_idx(int val) {
    int l = 0, r = sz - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (s[mid].val == val) return mid;
        if (s[mid].val < val) l = mid + 1;
        else r = mid - 1;
    }
    return -l - 1;
}

int main() {
    int N, Q, i;
    if (scanf("%d", &N) != 1) return 0;

    int total_count = 0;
    for(i=0;i<N;i++) {
        int x;
        scanf("%d", &x);
        int idx = find_idx(x);
        if (idx >= 0) {
            s[idx].count++;
        } else {
            int pos = -idx - 1;
            for (int j = sz; j > pos; j--) {
                s[j] = s[j - 1];
            }
            s[pos].val = x;
            s[pos].count = 1;
            sz++;
        }
        total_count++;
    }

    if (scanf("%d", &Q) != 1) return 0;

    while (Q--) {
        int val;
        scanf("%d", &val);
        int idx = find_idx(val);
        int max_val = s[sz - 1].val;

        if (idx < 0) {
            int pos = -idx - 1;
            for (int j = sz; j > pos; j--) {
                s[j] = s[j - 1];
            }
            s[pos].val = val;
            s[pos].count = 1;
            sz++;
            total_count++;
        } else {
            if (val < max_val && s[idx].count < 2) {
                s[idx].count++;
                total_count++;
            }
        }
        printf("%d\n", total_count);
    }

    // Output strictly increasing part
    for (int j = 0; j < sz; j++) {
        printf("%d ", s[j].val);
    }

    // Output strictly decreasing part
    for (int j = sz - 1; j >= 0; j--) {
        if (s[j].count == 2) {
            printf("%d ", s[j].val);
        }
    }
    printf("\n");

    return 0;
}