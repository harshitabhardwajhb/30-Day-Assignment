#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize_string(char *dest, const char *src) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (!isspace((unsigned char)src[i])) {
            dest[j++] = tolower((unsigned char)src[i]);
        }
    }
    dest[j] = '\0';
}

int are_anagrams(const char *str1, const char *str2) {
    int freq[256] = {0};
    unsigned char ch;

    for (int i = 0; str1[i] != '\0'; i++) {
        ch = (unsigned char) str1[i];
        freq[ch]++;
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        ch = (unsigned char) str2[i];
        freq[ch]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input1[1000];
    char input2[1000];
    char str1[1000];
    char str2[1000];

    printf("Enter first string: ");
    if (fgets(input1, sizeof(input1), stdin) == NULL) {
        return 1;
    }
    printf("Enter second string: ");
    if (fgets(input2, sizeof(input2), stdin) == NULL) {
        return 1;
    }

    // Remove newline characters
    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    normalize_string(str1, input1);
    normalize_string(str2, input2);

    if (strlen(str1) != strlen(str2)) {
        printf("The strings are not anagrams.\n");
        return 0;
    }

    if (are_anagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
