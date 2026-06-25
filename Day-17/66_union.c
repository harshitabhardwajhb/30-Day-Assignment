#include <stdio.h>

int main(void) {
    int n1, n2, k = 0;
    int arr1[100], arr2[100], unionArr[200];
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
        for (j = 0; j < k; j++) {
            if (unionArr[j] == arr1[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArr[k++] = arr1[i];
        }
    }

    for (i = 0; i < n2; i++) {
        exists = 0;
        for (j = 0; j < k; j++) {
            if (unionArr[j] == arr2[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArr[k++] = arr2[i];
        }
    }

    printf("Union of arrays is: ");
    for (i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
