#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};

struct n *head = NULL;
struct n *oddHead = NULL;
struct n *evenHead = NULL;

void insert(int data) {
    struct n *new_node = (struct n *)malloc(sizeof(struct n));
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        struct n *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}
struct n* insertInList(struct n* h, int data) {
    struct n *new_node = (struct n *)malloc(sizeof(struct n));
    new_node->data = data;

    if (h == NULL) {
        new_node->next = new_node;
        return new_node;
    }

    struct n *temp = h;
    while (temp->next != h) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = h;
    return h;
}

void display(struct n *h) {
    if (h == NULL) return;

    printf("[h]");
    struct n *temp = h;
    do {
        printf("=>%d", temp->data);
        temp = temp->next;
    } while (temp != h);
    printf("=>[h]\n");
}

int main() {
    int count;

    if (scanf("%d", &count) != 1) return 0;

    for (int i = 1; i <= count; i++) {
        insert(i);
        if (i % 2 != 0) {
            oddHead = insertInList(oddHead, i);
        } else {
            evenHead = insertInList(evenHead, i);
        }
    }

    printf("Complete linked_list:\n");
    display(head);

    printf("Odd:\n");
    display(oddHead);

    printf("Even:\n");
    display(evenHead);

    return 0;
}