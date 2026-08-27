#include <stdio.h>
#include <string.h>

int main() {
    char nums[13][256] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
        "SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE"
    };

    int req[26] = {0};
    int n;
    char token[50];

    while (scanf("%s", token) == 1) {
        printf("%s", token);
        if (strcmp(token, "0999") == 0 || strcmp(token, "999") == 0) {
            printf(". ");
            break;
        }
        printf(" ");

        int val = 0;
        int parsed = sscanf(token, "%d", &val);
        if (parsed == 1 && val >= 0 && val <= 12) {
            int current_cnt[26] = {0};
            for (int i = 0; nums[val][i] != '\0'; i++) {
                current_cnt[nums[val][i] - 'A']++;
            }
            for(n=0;n<26;n++) {
                if (current_cnt[n] > req[n]) {
                    req[n] = current_cnt[n];
                }
            }
        }
    }

    int first = 1;
    for(n=0;n<26;n++) {
        while (req[n] > 0) {
            if (!first) {
                printf(" ");
            }
            printf("%c", 'A' + n);
            first = 0;
            req[n]--;
        }
    }
    printf("\n");

    return 0;
}