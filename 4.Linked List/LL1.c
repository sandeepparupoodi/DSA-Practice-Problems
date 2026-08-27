#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void del(int D) {
    while (head != NULL && head->data == D) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    struct node *p2 = head;
    while (p2 != NULL && p2->next != NULL) {
        if (p2->next->data == D) {
            struct node *temp = p2->next;
            p2->next = temp->next;
            free(temp);
        } else {
            p2=p2->next;
        }
    }
}

void display() {
    printf("Linked List:");
    struct node *temp = head;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val, d;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        create(val);
    }

    scanf("%d", &d);

    del(d);
    display();

    return 0;
}