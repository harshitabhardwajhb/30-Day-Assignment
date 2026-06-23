#include <stdio.h>

int main(void) {
    int n, d;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate left: ");
    if (scanf("%d", &d) != 1) {
        printf("Invalid rotation count\n");
        return 1;
    }

    d %= n;
    if (d < 0) {
        d += n;
    }

    printf("Original array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Array after %d left rotation(s):\n", d);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[(i + d) % n]);
    }
    printf("\n");

    return 0;
}
