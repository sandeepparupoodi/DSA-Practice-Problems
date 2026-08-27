#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

#define read(x) scanf("%d", &(x))

int s[MAXN];

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sol() {
    int n;
    if (read(n) != 1) return;

    for (int i = 0; i < n; i++) {
        read(s[i]);
    }

    qsort(s, n, sizeof(int), cmp);

    int total_treats = 0;
    int current_treat = 1;

    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] > s[i - 1]) {
            current_treat++;
        }
        total_treats += current_treat;
    }

    printf("%d\n", total_treats);
}

int main() {
    int t;
    if (read(t) == 1) {
        while (t--) {
            sol();
        }
    }
    return 0;
}