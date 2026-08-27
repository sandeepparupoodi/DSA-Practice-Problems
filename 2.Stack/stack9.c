#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int val) {
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) return -1;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}

int getFront(Queue *q) {
    if (q->size == 0) return -1;
    return q->arr[q->front];
}

typedef struct {
    Queue q;
} Stack;

void push(Stack *s, int val) {
    int sz = s->q.size;
    enqueue(&(s->q), val);
    for (int i = 0; i < sz; i++) {
        enqueue(&(s->q), dequeue(&(s->q)));
    }
}

void pop(Stack *s) {
    dequeue(&(s->q));
}

int top(Stack *s) {
    return getFront(&(s->q));
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Stack s;
    initQueue(&(s.q));

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&s, val);
    }

    printf("top of element %d\n", top(&s));

    for (int i = 0; i < m; i++) {
        pop(&s);
    }

    printf("top of element %d\n", top(&s));

    return 0;
}