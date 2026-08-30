#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

int query(Node* root, int y) {
    int ans = -1;
    while (root != NULL) {
        if (root->key >= y) {
            ans = root->key;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}

int main() {
    int n, q, i;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    Node* root = NULL;

    for (i = 0; i < q; i++) {
        int type, val;
        scanf("%d %d", &type, &val);

        if (type == 1) {
            root = insert(root, val);
        } else if (type == 2) {
            printf("%d\n", query(root, val));
        }
    }

    return 0;
}