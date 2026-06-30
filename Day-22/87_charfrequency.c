#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char text[201];
    int freq[256] = {0};
    int i;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
        text[len - 1] = '\0';

    for (i = 0; text[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)text[i];
        if (ch != ' ') {
            freq[ch]++;
        }
    }

    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}
