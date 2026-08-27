#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 0;

    while (current != NULL) {
        if (count == index)
            return current->data;
        count++;
        current = current->next;
    }
    return -1;
}

void printList(struct node* node) {
    printf("Linked list:");
    while (node != NULL) {
        printf("-->%d", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, val, index;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&head, val);
    }

    scanf("%d", &index);

    printList(head);
    printf("Node at index=%d:%d\n", index, GetNth(head, index));

    return 0;
}