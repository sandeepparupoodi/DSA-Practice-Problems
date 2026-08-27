#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data, int l) {
    if (rear == l - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void reverse() {
    int i, j;
    for (i = front, j = rear; i < j; i++, j--) {
        int temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
}

int main() {
    int n, t;
    if (scanf("%d", &n) != 1) return 0;

    int count = 0;
    while (count < n) {
        scanf("%d", &t);
        enqueue(t,n);
        count++;
    }

    printf("Queue:");
    for (int i = front; i <= rear; i++) {
        printf("%d%c", queue[i], (i == rear) ? '\n' : ' ');
    }

    reverse();

    printf("Reversed Queue:");
    for (int i = front; i <= rear; i++) {
        printf("%d%c", queue[i], (i == rear) ? '\n' : ' ');
    }

    return 0;
}