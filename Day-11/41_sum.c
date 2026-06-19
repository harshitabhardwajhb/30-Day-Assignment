#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}
int main()
{
    int num1, num2, result;
    printf("enter the two numbers");
    scanf("%d %d", &num1, &num2);
    result = sum(num1, num2);
    printf("sum=%d", result);
    return 0;
}
