#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct mystack {
    Node* head;
    Node* tail;
} mystack;

mystack* createStack() {
    mystack* ms = (mystack*)malloc(sizeof(mystack));
    ms->head = NULL;
    ms->tail = NULL;
    return ms;
}

void push(int data, mystack* ms) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ms->head;
    ms->head = newNode;
    
    if (ms->tail == NULL) {
        ms->tail = newNode;
    }
}

int pop(mystack* ms) {
    if (ms->head == NULL) return -1;
    Node* temp = ms->head;
    int val = temp->data;
    ms->head = ms->head->next;
    if (ms->head == NULL) {
        ms->tail = NULL;
    }
    free(temp);
    return val;
}

void merge(mystack* ms1, mystack* ms2) {
    if (ms1->head == NULL) {
        ms1->head = ms2->head;
        ms1->tail = ms2->tail;
    } else if (ms2->head != NULL) {
        ms1->tail->next = ms2->head;
        ms1->tail = ms2->tail;
    }
}

void display(mystack* ms) {
    Node* curr = ms->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    mystack* ms1 = createStack();
    mystack* ms2 = createStack();

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(val, ms1);
    }

    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        push(val, ms2);
    }

    merge(ms1, ms2);

    display(ms1);

    return 0;
}