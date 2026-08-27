#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

int main() {
    int budget, items;
    if (scanf("%d %d", &budget, &items) != 2) return 0;

    char name[MAX][LEN];
    int price[MAX];
    int afford[MAX];
    int order[MAX];

    for(int i=0;i<items;i++) {
        afford[i] = 0;
        order[i] = i;
        scanf("%s %d", name[i], &price[i]);
    }

    for (int i = 0; i < items - 1; i++) {
        for (int j = i + 1; j < items; j++) {
            if (price[order[i]] > price[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    int remaining = budget;
    int bought_count = 0;

    for(int i=0;i<items;i++) {
        int idx = order[i];
        if (remaining >= price[idx]) {
            afford[idx] = 1;
            remaining -= price[idx];
            bought_count++;
        }
    }

    for(int i=0;i<items;i++) {
        if (afford[i]) {
            printf("I can afford %s\n", name[i]);
        } else {
            printf("I can't afford %s\n", name[i]);
        }
    }

    if (bought_count == 0) {
        printf("I need more Dollar!\n");
    } else {
        printf("%d\n", remaining);
    }

    return 0;
}