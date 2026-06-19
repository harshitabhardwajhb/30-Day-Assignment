#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int num1, num2, result;
    printf("enter the numbers");
    scanf("%d %d", &num1, &num2);
    result = max(num1, num2);
    printf("max=%d\n", result);
    return 0;
}
