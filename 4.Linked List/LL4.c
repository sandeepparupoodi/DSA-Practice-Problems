#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void append(int val) {
    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = val;
    p1->next = NULL;

    if (start == NULL) {
        start = p1;
    } else {
        struct node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p1;
    }
}

void insertBefore(int p, int x) {
    if (start == NULL) {
        printf("Node not found!\n");
        return;
    }

    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = x;
    p1->next = NULL;

    if (start->data == p) {
        p1->next = start;
        start = p1;
        return;
    }

    struct node *p2 = start;
    while (p2->next != NULL && p2->next->data != p) {
        p2 = p2->next;
    }

    if (p2->next == NULL) {
        printf("Node not found!\n");
        free(p1);
    } else {
        p1->next = p2->next;
        p2->next=p1;
    }
}

void display() {
    printf("Linked List:");
    struct node *temp = start;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val, p, x;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(val);
    }

    scanf("%d", &p);
    scanf("%d", &x);

    insertBefore(p, x);
    display();

    return 0;
}