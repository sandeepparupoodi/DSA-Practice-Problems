#include <stdio.h>

int main() {
    int n, count = 0;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        double width, height;
        scanf("%lf %lf", &width, &height);

        if(width/height>=1.6 && width/height<=1.7) {
            count++;
        }
        else if(height/width >=1.6 && height/width<=1.7) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}