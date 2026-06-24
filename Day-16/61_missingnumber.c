#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements from 1 to %d (one number is missing): ", n, n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    printf("Missing number is %d\n", expectedSum - actualSum);
    return 0;
}
