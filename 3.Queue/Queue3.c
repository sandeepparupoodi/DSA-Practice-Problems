#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int i;

void enqueue(int data) {
    if (rear < MAX - 1) {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front <= rear) {
        front++;
        if (front <= rear) {
            for(i=front;i<=rear;i++) {
                printf("%d%c", queue[i], (i == rear) ? '\n' : ' ');
            }
        }
    }
}

int main() {
    int size, data;
    if (scanf("%d", &size) != 1) return 0;

    for (int j = 0; j < size; j++) {
        scanf("%d", &data);
        enqueue(data);
    }

    printf("Dequeuing elements:\n");
    for (int j = 0; j < size; j++) {
        dequeue();
    }

    return 0;
}