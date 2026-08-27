#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int i;

void enqueue(int data) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1) {
        printf("Enqueuing %d\n", data);
        front = 0;
        rear = 0;
        queue[rear] = data;
    } else {
        for(i=front;i<=rear;i++) {
            printf("%d ", queue[i]);
        }
        printf("Enqueuing %d\n", data);
        rear++;
        queue[rear] = data;
    }
}

void disp() {
    if (front == -1) {
        return;
    }
    for(i=front;i<=rear;i++) {
        printf("%d%c", queue[i], (i == rear) ? '\n' : ' ');
    }
}

int main() {
    int size, data;
    if (scanf("%d", &size) != 1) return 0;

    for (int j = 0; j < size; j++) {
        scanf("%d", &data);
        enqueue(data);
    }

    disp();

    return 0;
}