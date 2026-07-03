#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to find and display common characters in two strings
void findCommonCharacters(char str1[], char str2[]) {
    printf("Common characters: ");
    bool found = false;
    
    // Track which characters we've already printed to avoid duplicates
    bool printed[256] = {false};
    
    // Iterate through first string
    for (int i = 0; str1[i] != '\0'; i++) {
        char ch = str1[i];
        
        // Skip if already printed
        if (printed[(unsigned char)ch]) {
            continue;
        }
        
        // Check if character exists in second string
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == ch) {
                printf("%c ", ch);
                printed[(unsigned char)ch] = true;
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        printf("No common characters found");
    }
    printf("\n");
}

// Function to find common characters using frequency array
void findCommonCharactersOptimized(char str1[], char str2[]) {
    // Create frequency arrays for both strings
    int freq1[256] = {0};
    int freq2[256] = {0};
    
    // Count frequency of characters in first string
    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }
    
    // Count frequency of characters in second string
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }
    
    // Find common characters
    printf("Common characters (optimized): ");
    bool found = false;
    
    for (int i = 0; i < 256; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            printf("%c ", (char)i);
            found = true;
        }
    }
    
    if (!found) {
        printf("No common characters found");
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100];
    int choice;
    
    printf("=== Find Common Characters in Strings ===\n\n");
    
    // Input strings
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline
    
    // Choose method
    printf("\nChoose method:\n");
    printf("1. Simple comparison method\n");
    printf("2. Frequency array method (optimized)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("\n");
    
    if (choice == 1) {
        findCommonCharacters(str1, str2);
    } else if (choice == 2) {
        findCommonCharactersOptimized(str1, str2);
    } else {
        printf("Invalid choice!\n");
    }
    
    // Display statistics
    printf("\nString 1: %s (length: %zu)\n", str1, strlen(str1));
    printf("String 2: %s (length: %zu)\n", str2, strlen(str2));
    
    return 0;
}
