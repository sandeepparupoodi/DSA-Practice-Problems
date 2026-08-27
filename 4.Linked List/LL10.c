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

void deleteFromStart(int d) {
    for (int i = 0; i < d && head != NULL; i++) {
        struct node *temp = head;
        head = head->next;
        free(temp);
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
    int n, val, d, i;

    if (scanf("%d", &n) != 1) return 0;

    for(i=0;i<n;i++) {
        scanf("%d", &val);
        create(val);
    }

    scanf("%d", &d);

    deleteFromStart(d);
    display();

    return 0;
}