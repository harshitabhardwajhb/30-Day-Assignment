#include <stdio.h>

int main(void) {
    int n1, n2, k = 0;
    int arr1[100], arr2[100], intersection[200];
    int i, j, exists;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < n1; i++) {
        exists = 0;
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                exists = 1;
                break;
            }
        }

        if (exists) {
            for (j = 0; j < k; j++) {
                if (intersection[j] == arr1[i]) {
                    exists = 0;
                    break;
                }
            }
        }

        if (exists) {
            intersection[k++] = arr1[i];
        }
    }

    printf("Intersection of arrays is: ");
    if (k == 0) {
        printf("No common elements\n");
    } else {
        for (i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }

    return 0;
}
