#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101];
    int i, j;
    int isPalindrome = 1;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    /* Remove newline from input if present */
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(str);
    i = 0;
    j = len - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (isPalindrome)
        printf("%s is a palindrome string.\n", str);
    else
        printf("%s is not a palindrome string.\n", str);

    return 0;
}
