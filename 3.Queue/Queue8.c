#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    struct QNode *prev, *next;
    unsigned pageNumber;
} QNode;

typedef struct Queue {
    unsigned count;
    unsigned numberOfFrames;
    QNode *front, *rear;
} Queue;

typedef struct Hash {
    int capacity;
    QNode* *array;
} Hash;

QNode* newQNode(unsigned pageNumber) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->pageNumber = pageNumber;
    temp->prev = temp->next = NULL;
    return temp;
}

Queue* createQueue(int numberOfFrames) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->count = 0;
    queue->front = queue->rear = NULL;
    queue->numberOfFrames = numberOfFrames;
    return queue;
}

Hash* createHash(int capacity) {
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    hash->capacity = capacity;
    hash->array = (QNode**)malloc(hash->capacity * sizeof(QNode*));
    for (int i = 0; i < hash->capacity; ++i)
        hash->array[i] = NULL;
    return hash;
}

int AreAllFramesFull(Queue* queue) {
    return queue->count == queue->numberOfFrames;
}

int isQueueEmpty(Queue* queue) {
    return queue->rear == NULL;
}

void deQueue(Queue* queue) {
    if (isQueueEmpty(queue))
        return;

    if (queue->front == queue->rear)
        queue->front = NULL;

    QNode* temp = queue->rear;
    queue->rear = queue->rear->prev;

    if (queue->rear)
        queue->rear->next = NULL;

    free(temp);
    queue->count--;
}

void Enqueue(Queue* queue, Hash* hash, unsigned pageNumber) {
    if (AreAllFramesFull(queue)) {
        hash->array[queue->rear->pageNumber] = NULL;
        deQueue(queue);
    }

    QNode* temp = newQNode(pageNumber);
    temp->next = queue->front;

    if (isQueueEmpty(queue))
        queue->rear = queue->front = temp;
    else {
        queue->front->prev = temp;
        queue->front = temp;
    }

    hash->array[pageNumber] = temp;
    queue->count++;
}

void ReferencePage(Queue* queue, Hash* hash, unsigned pageNumber) {
    QNode* reqPage = hash->array[pageNumber];

    if (reqPage == NULL) {
        Enqueue(queue, hash, pageNumber);
    } else if (reqPage != queue->front) {
        reqPage->prev->next = reqPage->next;
        if (reqPage->next)
            reqPage->next->prev = reqPage->prev;

        if (reqPage == queue->rear) {
            queue->rear = reqPage->prev;
            queue->rear->next = NULL;
        }

        reqPage->next = queue->front;
        reqPage->prev = NULL;
        reqPage->next->prev = reqPage;
        queue->front = reqPage;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Queue* q = createQueue(m);
    Hash* hash = createHash(100);

    for (int i = 0; i < n; i++) {
        int page;
        scanf("%d", &page);
        ReferencePage(q, hash, page);
    }

    QNode* cur = q->front;
    while (cur != NULL) {
        printf("%u%c", cur->pageNumber, (cur->next == NULL) ? '\n' : ' ');
        cur = cur->next;
    }

    return 0;
}