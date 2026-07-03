#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

// Function to swap two strings
void swapStrings(char str1[], char str2[]) {
    char temp[MAX_NAME_LENGTH];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Function to sort names using bubble sort
void sortNamesBubbleSort(char names[][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare names alphabetically
            if (strcmp(names[j], names[j + 1]) > 0) {
                swapStrings(names[j], names[j + 1]);
            }
        }
    }
}

// Comparison function for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Function to sort names using qsort (built-in)
void sortNamesQSort(char names[][MAX_NAME_LENGTH], int n) {
    qsort(names, n, MAX_NAME_LENGTH, compareStrings);
}

// Function to display names
void displayNames(char names[][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}

int main() {
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int n;
    int choice;
    
    printf("=== Sort Names Alphabetically ===\n\n");
    
    // Input number of names
    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();  // Consume newline after scanf
    
    if (n <= 0 || n > MAX_NAMES) {
        printf("Invalid number of names!\n");
        return 1;
    }
    
    // Input names
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        // Remove newline from input
        names[i][strcspn(names[i], "\n")] = '\0';
    }
    
    // Choose sorting method
    printf("\nChoose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort (qsort)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("\n");
    
    if (choice == 1) {
        sortNamesBubbleSort(names, n);
        printf("Names sorted using Bubble Sort:\n");
    } else if (choice == 2) {
        sortNamesQSort(names, n);
        printf("Names sorted using Quick Sort:\n");
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    displayNames(names, n);
    
    return 0;
}
