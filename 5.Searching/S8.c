#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMDS 5
#define TOKENS 4
#define MAXWORDS 50
#define BUFLEN 256

int cl[CMDS];
char *lists[CMDS][MAXWORDS];
char *tokens[TOKENS]={"[N]","[AV]","[V]","[AJ]"};
char *cmds[CMDS]={"NOUNS","ADVERBS","VERBS","ADJECTIVES","END"};
int ptr[TOKENS];

void print_replaced(char *story) {
    char s[BUFLEN];
    strcpy(s, story);
    char *tok = strtok(s, " \r\n");
    int first = 1;
    while (tok) {
        int matched = -1;
        for (int i = 0; i < TOKENS; i++) {
            if (strcmp(tok, tokens[i]) == 0) matched = i;
        }
        if (!first) printf(" ");
        first = 0;
        if (matched != -1) printf("%s", lists[matched][ptr[matched]++]);
        else printf("%s", tok);
        tok = strtok(NULL, " \r\n");
    }
    printf("\n");
}

int main() {
    char story[BUFLEN], line[BUFLEN];
    if (!fgets(story, BUFLEN, stdin)) return 0;

    int cur_cat = -1;
    while (fgets(line, BUFLEN, stdin)) {
        line[strcspn(line, "\r\n")] = 0;
        if (!line[0]) continue;

        int cmd_idx = -1;
        for (int i = 0; i < CMDS; i++) {
            if (strcmp(line, cmds[i]) == 0) cmd_idx = i;
        }

        if (cmd_idx == 4) break;
        if (cmd_idx != -1) cur_cat = cmd_idx;
        else lists[cur_cat][cl[cur_cat]++] = strdup(line);
    }

    print_replaced(story);
    print_replaced(story);
    return 0;
}