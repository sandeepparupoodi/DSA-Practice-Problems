#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return 1;
    }
    return 0;
}

void postToPre(char* post_exp, char* result) {
    char stack[MAX][MAX];
    int top = -1;

    int length = strlen(post_exp);

    for (int i = 0; i < length; i++) {
        if (isOperator(post_exp[i])) {
            char op2[MAX], op1[MAX];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            char temp[MAX];
            temp[0] = post_exp[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);

            strcpy(stack[++top], temp);
        } else {
           
            char temp[2];
            temp[0] = post_exp[i];
            temp[1] = '\0';
            strcpy(stack[++top], temp);
        }
    }

    strcpy(result, stack[top]);
}

int main() {
    char post_exp[MAX];
    char result[MAX];

    if (scanf("%s", post_exp) == 1) {
        postToPre(post_exp, result);
        printf("%s\n", result);
    }

    return 0;
}