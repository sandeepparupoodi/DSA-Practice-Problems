#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
} Queue;

void enQueue(Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (q->front == NULL) {
        q->front = temp;
    } else {
        q->rear->next = temp;
    }

    q->rear = temp;
    q->rear->next = q->front;
}

int deQueue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    int value;
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return value;
}

void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    printf("Elements in Circular Queue are:");
    while (temp->next != q->front) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enQueue(q, val);
    }

    displayQueue(q);
    printf("Deleted value = %d\n", deQueue(q));
    printf("Deleted value = %d", deQueue(q));
    displayQueue(q);

    return 0;
}