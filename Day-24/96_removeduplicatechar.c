#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int seen[256] = {0};
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (!seen[(unsigned char)str[i]]) {
            seen[(unsigned char)str[i]] = 1;
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}

int main(void) {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    removeDuplicates(str);
    printf("String after removing duplicates: %s\n", str);

    return 0;
}
