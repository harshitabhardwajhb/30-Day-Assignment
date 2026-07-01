#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0};
    int i;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char) str[i];
        freq[ch]++;
    }

    // Find first non-repeating character
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char) str[i];
        if (freq[ch] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found.\n");
    return 0;
}
