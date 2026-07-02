#include <stdio.h>
#include <string.h>

void compressString(const char *str) {
    int len = strlen(str);
    int count = 1;
    int i;

    if (len == 0) {
        printf("Empty string\n");
        return;
    }

    for (i = 1; i <= len; i++) {
        if (i < len && str[i] == str[i - 1]) {
            count++;
        } else {
            printf("%c%d", str[i - 1], count);
            count = 1;
        }
    }
}

int main(void) {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Compressed string: ");
    compressString(str);
    printf("\n");

    return 0;
}
