#include <stdio.h>

int main() {
    int n, original, rev = 0;

    printf("Enter Number: ");
    scanf("%d", &n);

    original = n;

    while(n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    if(original == rev)
        printf("Palindrome Number\n");
    else
        printf("Not a Palindrome Number\n");

    return 0;
}