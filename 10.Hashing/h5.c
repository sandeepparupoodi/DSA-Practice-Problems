#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    int freq[256] = {0};
    int l = strlen(str);
    int i;

    for (i = 0; i < l; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (ch != '\n' && ch != '\r' && ch != ' ') {
            freq[ch]++;
        }
    }

    char max_char = 0;
    int max_freq = 0;

    for (i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = (char)i;
        }
    }

    printf("%c %d\n", max_char, max_freq);

    return 0;
}