#include <stdio.h>
long long fact(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    } return fact;

}
int main()
{
    {
        int num, result;
        printf("enter num");
        scanf("%d", &num);

        printf("factorial of %d=%lld", num, fact(num));
        return 0;
    }
}