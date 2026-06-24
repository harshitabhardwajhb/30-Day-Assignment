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

    int maxFreq = 0, maxElement = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxFreq) {
            maxFreq = count;
            maxElement = arr[i];
        }
    }

    printf("Element with maximum frequency is: %d\n", maxElement);
    printf("Frequency: %d\n", maxFreq);

    return 0;
}
