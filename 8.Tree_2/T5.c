#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

int heap[MAXN];
int heap_size = 0;

void heap_push(int val) {
    int i = heap_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= val) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = val;
}

int heap_pop() {
    int res = heap[0];
    int val = heap[--heap_size];
    int i = 0;
    while (i * 2 + 1 < heap_size) {
        int left = i * 2 + 1, right = i * 2 + 2, child = left;
        if (right < heap_size && heap[right] < heap[left]) child = right;
        if (heap[child] >= val) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = val;
    return res;
}

struct Queue {
    int (*top)(void);
    void (*pop)(void);
};

void dummy_pop(void) {
    heap_pop();
}

int dummy_top(void) {
    return heap[0];
}

int code[MAXN];
int degree[MAXN];

int main() {
    struct Queue q = { dummy_top, dummy_pop };

    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        degree[i] = 1;
    }

    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &code[i]);
        degree[code[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            heap_push(i);
        }
    }

    for (int i = 0; i < n - 2; i++) {
        int u = code[i];
        int v = q.top();
        q.pop();

        printf("%d %d\n", v, u);

        degree[u]--;
        if (degree[u] == 1) {
            heap_push(u);
        }
    }

    int u = q.top();
    q.pop();
    int v = q.top();
    q.pop();

    printf("%d %d\n", u, v);

    return 0;
}