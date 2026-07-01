#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0};
    int i;
    unsigned char max_char = 0;
    int max_freq = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char) str[i];
        freq[ch]++;
        if (freq[ch] > max_freq) {
            max_freq = freq[ch];
            max_char = ch;
        }
    }

    if (max_freq > 0) {
        printf("Maximum occurring character: %c\n", max_char);
        printf("Frequency: %d\n", max_freq);
    } else {
        printf("No characters found in the input.\n");
    }

    return 0;
}
