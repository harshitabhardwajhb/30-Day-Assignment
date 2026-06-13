#include <stdio.h>

int main()
{
    int s = 0, n, r, x;
    printf("enter the value of n");
    scanf("%d", &n);
    x = n;
    while (x > 0)
    {
        r = x % 10;
        x = x / 10;
        s = s + r * r * r;
    }

    if (n == s)
    {
        printf("%d is an armstrong number", n);
    }
    else
        printf("%d is not an armstrong number", n);
}