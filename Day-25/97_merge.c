#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;
    
    // Compare elements from both arrays and add the smaller one
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    // Add remaining elements from arr1
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    
    // Add remaining elements from arr2
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

// Function to display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n1, n2;
    
    // Input size of first array
    printf("Enter the size of first sorted array: ");
    scanf("%d", &n1);
    
    // Input size of second array
    printf("Enter the size of second sorted array: ");
    scanf("%d", &n2);
    
    // Create arrays
    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n2 * sizeof(int));
    int *merged = (int *)malloc((n1 + n2) * sizeof(int));
    
    // Input first array
    printf("Enter elements of first array (in sorted order):\n");
    for (int i = 0; i < n1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    
    // Input second array
    printf("Enter elements of second array (in sorted order):\n");
    for (int i = 0; i < n2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }
    
    // Merge arrays
    mergeArrays(arr1, n1, arr2, n2, merged);
    
    // Display results
    printf("\nFirst array: ");
    displayArray(arr1, n1);
    
    printf("Second array: ");
    displayArray(arr2, n2);
    
    printf("Merged sorted array: ");
    displayArray(merged, n1 + n2);
    
    // Free allocated memory
    free(arr1);
    free(arr2);
    free(merged);
    
    return 0;
}
