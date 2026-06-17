#include <stdio.h>
int main()
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        char ch = 'A';
        for (j = 0; i >= j; j++)
        {
            printf("%c", ch + i);
        }
        printf("\n");
    }
    return 0;
}