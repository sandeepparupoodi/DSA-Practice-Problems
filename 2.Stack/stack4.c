#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct twoStacks {
    int arr[SIZE];
    int top1;
    int top2;
} twoStacks;
twoStacks ts;

void push1(int x) {
    if (ts.top1 < ts.top2 - 1) {
        ts.arr[++ts.top1] = x;
    }
}

void push2(int x) {
    if (ts.top1 < ts.top2 - 1) {
        ts.arr[--ts.top2] = x;
    }
}

int pop1() {
    if (ts.top1 >= 0) {
        return ts.arr[ts.top1--];
    }
    return -1;
}

int pop2() {
    if (ts.top2 < SIZE) {
        return ts.arr[ts.top2++];
    }
    return -1;
}

int main() {
    ts.top1 = -1;
    ts.top2 = SIZE;

    int val;

    if (scanf("%d", &val) == 1) push1(val);

    if (scanf("%d", &val) == 1) push2(val);

    if (scanf("%d", &val) == 1) push1(val);

    if (scanf("%d", &val) == 1) push2(val);

    if (scanf("%d", &val) == 1) push1(val);

    printf("Popped element from stack1 is:%d\n", pop1());
    printf("Popped element from stack2 is:%d\n", pop2());

    return 0;
}