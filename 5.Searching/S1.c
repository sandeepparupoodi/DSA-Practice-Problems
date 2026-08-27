#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN 32

int main() {
    char var[3][LEN];
    char inp[3][LEN];
    double M = 0.0, D = 0.0, X = 0.0, ans = 0.0;
    char target = 0;

    for (int i = 0; i < 3; i++) {
        scanf("%s %s", var[i], inp[i]);
        if (inp[i][0] == '?') {
            target = tolower(var[i][0]);
        } else {
            double v = atof(inp[i]);
            if (var[i][0] == 'M') M = v;
            else if (var[i][0] == 'D') D = v;
            else if (var[i][0] == 'X') X = v;
        }
    }

    if (target == 'm') ans = -(D * X);
    else if (target == 'd') ans = -(M / X);
    else if (target == 'x') ans = -(M / D);

    printf("%c %.2f\n", target, ans);
    return 0;
}