#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char sentence[201];
    int i, wordCount = 0;
    int inWord = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
        return 1;

    for (i = 0; sentence[i] != '\0'; i++) {
        if (!isspace((unsigned char)sentence[i])) {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    printf("Word count: %d\n", wordCount);
    return 0;
}
