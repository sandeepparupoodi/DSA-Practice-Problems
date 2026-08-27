#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_Data(struct node **head, int n) {
    struct node *tail = NULL;
    for (int i = 1; i <= n; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
}

void delete_Alt(struct node **head) {
    if (*head == NULL) return;

    struct node *a = *head;
    struct node *b;

    while (a != NULL && a->next != NULL) {
        b = a->next;
        a->next = b->next;
        free(b);
        a = a->next;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    struct node *head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    insert_Data(&head, n);
    delete_Alt(&head);
    display(head);

    return 0;
}