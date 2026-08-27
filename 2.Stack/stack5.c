#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    char items[MAX];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

bool empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, char c) {
    s->items[++(s->top)] = c;
}

char pop(stack *s) {
    if (!empty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

bool is_matching_pair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

int main() {
    char exp[MAX];
    if (scanf("%s", exp) != 1) return 0;

    stack s;
    init(&s);

    bool is_balanced = true;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (empty(&s)) {
                is_balanced = false;
                break;
            }
            char popped = pop(&s);
            if (!is_matching_pair(popped, ch)) {
                is_balanced = false;
                break;
            }
        }
    }

    if (is_balanced && empty(&s)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}