#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char input[201];
    char output[201];
    int i, j = 0;

    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
        return 1;

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    for (i = 0; input[i] != '\0'; i++) {
        if (!isspace((unsigned char)input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    printf("String without spaces: %s\n", output);
    return 0;
}
