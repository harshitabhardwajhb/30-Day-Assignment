#include <stdio.h>

int main()
{
    long long n;
    long long largestPrime = -1;

    printf("Enter a number: ");
    scanf("%lld", &n);

    while (n % 2 == 0)
    {
        largestPrime = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            largestPrime = i;
            n /= i;
        }
    }

    if (n > 2)
    {
        largestPrime = n;
    }

    printf("Largest Prime Factor = %lld", largestPrime);

    return 0;
}