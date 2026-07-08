#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

struct Book {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int available; // 1 = available, 0 = borrowed
};

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n\n");
        return;
    }

    struct Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    clearInputBuffer();

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.available = 1;
    library[*count] = newBook;
    (*count)++;
    printf("Book added successfully.\n\n");
}

void showBooks(const struct Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n\n");
        return;
    }

    printf("\nMini Library Catalog\n");
    printf("--------------------------------------------------------------\n");
    printf("%-6s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-30s %-20s %-10s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].available ? "Available" : "Borrowed");
    }
    printf("--------------------------------------------------------------\n\n");
}

int findBookById(const struct Book library[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            return i;
        }
    }
    return -1;
}

void borrowBook(struct Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n\n");
        return;
    }

    int id;
    printf("Enter book ID to borrow: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findBookById(library, count, id);
    if (index == -1) {
        printf("Book with ID %d not found.\n\n", id);
    } else if (!library[index].available) {
        printf("That book is already borrowed.\n\n");
    } else {
        library[index].available = 0;
        printf("Book borrowed successfully.\n\n");
    }
}

void returnBook(struct Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n\n");
        return;
    }

    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findBookById(library, count, id);
    if (index == -1) {
        printf("Book with ID %d not found.\n\n", id);
    } else if (library[index].available) {
        printf("That book is already in the library.\n\n");
    } else {
        library[index].available = 1;
        printf("Book returned successfully.\n\n");
    }
}

void searchBook(const struct Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n\n");
        return;
    }

    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findBookById(library, count, id);
    if (index == -1) {
        printf("Book with ID %d not found.\n\n", id);
    } else {
        printf("\nBook Details:\n");
        printf("ID: %d\n", library[index].id);
        printf("Title: %s\n", library[index].title);
        printf("Author: %s\n", library[index].author);
        printf("Status: %s\n\n", library[index].available ? "Available" : "Borrowed");
    }
}

int main(void) {
    struct Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("Mini Library System\n");
        printf("1. Add Book\n");
        printf("2. Show All Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                showBooks(library, count);
                break;
            case 3:
                borrowBook(library, count);
                break;
            case 4:
                returnBook(library, count);
                break;
            case 5:
                searchBook(library, count);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 6);

    return 0;
}
