#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node **head,int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

struct node* reverseList(struct node* head) {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void foldList(struct node* head) {
    if (head == NULL || head->next == NULL) return;

    
    struct node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *head2 = reverseList(slow->next);
    slow->next = NULL;

    struct node *head1 = head;
    while (head2 != NULL) {
        struct node *temp1 = head1->next;
        struct node *temp2 = head2->next;

        head1->next = head2;
        head2->next = temp1;

        head1 = temp1;
        head2 = temp2;
    }
}

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct node *head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        create(&head, val);
    }

    printf("Link list data:");
    print(head);

    foldList(head);

    printf("Link list data after fold:");
    print(head);

    return 0;
}