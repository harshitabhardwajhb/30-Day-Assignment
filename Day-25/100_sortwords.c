#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Structure to store word and its length
typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

// Comparison function for ascending order (shortest to longest)
int compareAscending(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    
    if (word1->length != word2->length) {
        return word1->length - word2->length;
    }
    // If lengths are same, sort alphabetically
    return strcmp(word1->word, word2->word);
}

// Comparison function for descending order (longest to shortest)
int compareDescending(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    
    if (word1->length != word2->length) {
        return word2->length - word1->length;
    }
    // If lengths are same, sort alphabetically
    return strcmp(word1->word, word2->word);
}

// Function to bubble sort words by length
void sortWordsManual(Word words[], int n, int order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int comparison;
            
            if (order == 1) {  // Ascending
                if (words[j].length > words[j + 1].length) {
                    Word temp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = temp;
                }
            } else {  // Descending
                if (words[j].length < words[j + 1].length) {
                    Word temp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = temp;
                }
            }
        }
    }
}

// Function to display words with their lengths
void displayWords(Word words[], int n) {
    printf("%-20s %s\n", "Word", "Length");
    printf("%-20s %s\n", "----", "------");
    for (int i = 0; i < n; i++) {
        printf("%-20s %d\n", words[i].word, words[i].length);
    }
}

int main() {
    Word words[MAX_WORDS];
    int n;
    int choice, sortChoice;
    
    printf("=== Sort Words by Length ===\n\n");
    
    // Input number of words
    printf("Enter number of words: ");
    scanf("%d", &n);
    getchar();  // Consume newline after scanf
    
    if (n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words!\n");
        return 1;
    }
    
    // Input words and calculate their lengths
    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Word %d: ", i + 1);
        fgets(words[i].word, MAX_WORD_LENGTH, stdin);
        // Remove newline from input
        words[i].word[strcspn(words[i].word, "\n")] = '\0';
        // Calculate length
        words[i].length = strlen(words[i].word);
    }
    
    // Choose sorting method
    printf("\nChoose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort (qsort)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    // Choose sorting order
    printf("\nChoose sorting order:\n");
    printf("1. Ascending (Shortest to Longest)\n");
    printf("2. Descending (Longest to Shortest)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &sortChoice);
    
    printf("\n");
    
    if (choice == 1) {
        sortWordsManual(words, n, sortChoice);
        if (sortChoice == 1) {
            printf("Words sorted by length (Ascending) using Bubble Sort:\n");
        } else {
            printf("Words sorted by length (Descending) using Bubble Sort:\n");
        }
    } else if (choice == 2) {
        if (sortChoice == 1) {
            qsort(words, n, sizeof(Word), compareAscending);
            printf("Words sorted by length (Ascending) using Quick Sort:\n");
        } else {
            qsort(words, n, sizeof(Word), compareDescending);
            printf("Words sorted by length (Descending) using Quick Sort:\n");
        }
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    printf("\n");
    displayWords(words, n);
    
    return 0;
}
