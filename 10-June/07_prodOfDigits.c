#include <stdio.h>

int main() {
    int n, digit, product = 1;

    printf("Enter Number: ");
    scanf("%d", &n);

    while(n != 0) {
        digit = n % 10;
        product *= digit;
        n /= 10;
    }

    printf("Product of Digits = %d\n", product);

    return 0;
}