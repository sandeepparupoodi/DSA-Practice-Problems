#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int preorder[MAXN];
int inorder[MAXN];
int pos[MAXN]; 

void getPostOrder(int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return;
    }

    int rootVal = preorder[preStart];
    int rootIdx = pos[rootVal];
    int leftSize = rootIdx - inStart;

    getPostOrder(preStart + 1, preStart + leftSize, inStart, rootIdx - 1);

    getPostOrder(preStart + leftSize + 1, preEnd, rootIdx + 1, inEnd);

    printf("%d ", rootVal);
}

int main() {
    int n, i;

    if (scanf("%d", &n) != 1) return 0;

    for (i = 1; i <= n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (i = 1; i <= n; i++) {
        scanf("%d", &inorder[i]);
        pos[inorder[i]] = i;
    }

    getPostOrder(1, n, 1, n);
    printf("\n");

    return 0;
}