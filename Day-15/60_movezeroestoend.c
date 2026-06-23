#include <stdio.h>

int main(void) {
    int n;
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

    int write_index = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            arr[write_index++] = arr[i];
        }
    }
    while (write_index < n) {
        arr[write_index++] = 0;
    }

    printf("Array after moving zeros to the end:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
