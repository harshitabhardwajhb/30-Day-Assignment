#include <stdio.h>

int main() {
    int n;
    long long fact = 1;

    printf("Enter Number: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        fact *= i;
    }

    printf("Factorial = %lld\n", fact);

    return 0;
}