#include <stdio.h>
int recursivesum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + recursivesum(n - 1);
    }
}
int main()
{
    int n;
    printf("enter n:");
    scanf("%d", &n);
    printf("%d", recursivesum(n));
    return 0;
}