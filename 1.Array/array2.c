#include <stdio.h>

int main() {
    int p, q;
    if (scanf("%d %d", &p, &q) != 2) return 0;

    char mat[1000][1000];
    int top = 0, bottom = p - 1;
    int left = 0, right = q - 1;
    char ch = 'Y';

    while (top <= bottom && right >= left) {
        for (int j = left; j <= right; j++) {
            mat[top][j] = ch;
            mat[bottom][j] = ch;
        }
        for (int i = top; i <= bottom; i++) {
            mat[i][left] = ch;
            mat[i][right] = ch;
        }

        top++;
        bottom--;
        left++;
        right--;

        ch = (ch == 'Y') ? 'O' : 'Y';
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%c%s", mat[i][j], (j == q - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}