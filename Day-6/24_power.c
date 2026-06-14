#include <stdio.h>
int main()
{
    int x, n;
    long long result = 1;
    printf("enter x");
    scanf("%d", &x);
    printf("enter n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        result *= x;
    }
    printf("%d^%d = %lld\n", x, n, result);
    return 0;
}