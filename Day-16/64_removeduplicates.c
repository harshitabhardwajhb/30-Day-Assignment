#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int unique[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            unique[size] = arr[i];
            size++;
        }
    }

    printf("Array after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    return 0;
}
