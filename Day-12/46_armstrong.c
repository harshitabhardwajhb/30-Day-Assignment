#include <stdio.h>
int armstrong(int n)
{
    int original = n, ld, s = 0;
    while (n > 0)
    {
        ld = n % 10;
        s = s + ld * ld * ld;
        n = n / 10;
    }
    if (original == s)
        return 1;
    else
        return 0;
}
int main()
{
    int num;
    printf("enter num");
    scanf("%d", &num);
    if (armstrong(num))
    {
        printf("%d is an armstrong number", num);
    }
    else
        printf("%d is not an armstrong number", num);
    return 0;
}