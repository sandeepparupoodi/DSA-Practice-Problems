#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;

    if (f == NULL && r == NULL) {
        f = r = n;
        r->next = f;
    } else {
        r->next = n;
        r = n;
        r->next = f;
    }
}

void dequeue() {
    if (f == NULL) return;
    struct node* t = f;
    if (f == r) {
        f = r = NULL;
    } else {
        f = f->next;
        r->next = f;
    }
    free(t);
}

void display() {
    if (f == NULL) return;
    struct node* t = f;
    do {
        printf("%d\n", t->data);
        t = t->next;
    } while (t != f);
}

int main() {
    int size, data;
    if (scanf("%d", &size) != 1) return 0;

    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    display();

    return 0;
}