#include <stdio.h>
int isPerfect(int n)
{
    int i, s = 0;
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            s = s + i;
        }
    }
    return (s == n);
}
int main()
{
    int num;
    printf("enter num");
    scanf("%d", &num);
    if (isPerfect(num))
    {
        printf("%d is a perfect number", num);
    }
    else
        printf("%d is not a perfect number", num);
    return 0;
}