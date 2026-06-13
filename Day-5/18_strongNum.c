#include <stdio.h>

int main()
{
    int n, x, r, s = 0, fact;

    printf("Enter n: ");
    scanf("%d", &n);

    x = n;

    while (x > 0)
    {
        r = x % 10;

        fact = 1;
        for (int i = 1; i <= r; i++)
        {
            fact *= i;
        }

        s += fact;
        x = x / 10;
    }

    if (n == s)
    {
        printf("%d is a Strong Number", n);
    }
    else
    {
        printf("%d is not a Strong Number", n);
    }

    return 0;
}