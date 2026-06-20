#include <stdio.h>

int palindrome(int n)
{
    int original = n, rev = 0, ld;
    while (n > 0)
    {
        ld = n % 10;
        rev = rev * 10 + ld;
        n = n / 10;
    }
    if (original == rev)
    
        return 1;
        else return 0;
    
    
}
int main()
{
    int num;
    printf("enter num");
    scanf("%d", &num);
    if (palindrome(num))
    {
        printf("%d is a palindrome number", num);
    }
    else
        printf("%d is not a palindrome number", num);
    return 0;
}