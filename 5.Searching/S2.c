#include <stdio.h>
#include <string.h>

#define MAXP 100
#define BUFLEN 110

char *gems[]={"NONE","Garnet","Amethyst","Aquamarine","Diamond","Emerald","Pearl","Ruby","Peridot","Sapphire","Tourmaline","Topaz","Lapis",0};

int get_rank(char *name) {
    char copy[BUFLEN];
    strcpy(copy, name);
    int best = 0;
    char *word = strtok(copy, " \r\n");
    while (word) {
        for (int i = 1; gems[i]; i++) {
            if (strcmp(word, gems[i]) == 0 && i > best) {
                best = i;
            }
        }
        word = strtok(NULL, " \r\n");
    }
    return best;
}

int main() {
    char ponies[MAXP][BUFLEN];
    int n = 0;

    while (fgets(ponies[n], BUFLEN, stdin)) {
        ponies[n][strcspn(ponies[n], "\r\n")] = 0;
        if (strcmp(ponies[n], "END") == 0) break;
        if (strlen(ponies[n]) > 0) n++;
    }

    for (int a = 0; a < n - 1; a++) {
        for (int b = a + 1; b < n; b++) {
            int ra = get_rank(ponies[a]);
            int rb = get_rank(ponies[b]);
            if (ra < rb || (ra == rb && strcmp(ponies[a],ponies[b])>0)) {
                char temp[BUFLEN];
                strcpy(temp, ponies[a]);
                strcpy(ponies[a], ponies[b]);
                strcpy(ponies[b], temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", ponies[i]);
    }
    return 0;
}