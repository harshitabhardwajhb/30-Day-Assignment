#include <stdio.h>

int main() {
    int a, b, x, y, gcd, lcm, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    x = a;
    y = b;

    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }

    gcd = x;
    lcm = (a * b) / gcd;

    printf("LCM = %d\n", lcm);

    return 0;
}