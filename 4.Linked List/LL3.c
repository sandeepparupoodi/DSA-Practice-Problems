#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* current = *head_ref;

    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    else if (current->data >= new_node->data) {
        while (current->next != *head_ref) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        while (current->next != *head_ref && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->next = NULL;
        sortedInsert(&head, new_node);
    }

    printList(head);

    return 0;
}