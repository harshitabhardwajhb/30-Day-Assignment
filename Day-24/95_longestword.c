#include <stdio.h>
#include <string.h>

int main(void) {
    char sentence[200];
    char word[50];
    char longest[50];
    int i = 0, j = 0, len, maxLen = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    while (sentence[i] != '\0') {
        while (sentence[i] == ' ') {
            i++;
        }

        j = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            word[j++] = sentence[i++];
        }
        word[j] = '\0';

        len = strlen(word);
        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, word);
        }
    }

    if (maxLen == 0) {
        printf("No word found.\n");
    } else {
        printf("Longest word: %s\n", longest);
    }

    return 0;
}
