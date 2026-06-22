#include <stdio.h>

int main() {
    int n, key, i;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Element %d found at %d position in the array\n",key,i+1);
    }else printf("element 5d not found in the array",key);

    return 0;
}
