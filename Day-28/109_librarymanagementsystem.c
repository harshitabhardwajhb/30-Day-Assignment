#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[50];
    char author[50];
    int available;
} Book;

Book books[MAX_BOOKS];
int count = 0;

void readString(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void addBook() {
    if (count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar();

    printf("Enter Book Title: ");
    readString(b.title, sizeof(b.title));

    printf("Enter Author Name: ");
    readString(b.author, sizeof(b.author));

    b.available = 1;
    books[count++] = b;

    printf("Book added successfully!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    printf("ID\tTitle\t\tAuthor\t\tStatus\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s%-20s%s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].available ? "Available" : "Issued");
    }
}

int findBookById(int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    getchar();

    int index = findBookById(id);
    if (index == -1) {
        printf("Book not found.\n");
    } else {
        printf("\nBook Found:\n");
        printf("ID: %d\n", books[index].id);
        printf("Title: %s\n", books[index].title);
        printf("Author: %s\n", books[index].author);
        printf("Status: %s\n", books[index].available ? "Available" : "Issued");
    }
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    getchar();

    int index = findBookById(id);
    if (index == -1) {
        printf("Book not found.\n");
    } else if (!books[index].available) {
        printf("Book is already issued.\n");
    } else {
        books[index].available = 0;
        printf("Book issued successfully!\n");
    }
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    getchar();

    int index = findBookById(id);
    if (index == -1) {
        printf("Book not found.\n");
    } else if (books[index].available) {
        printf("Book is already available.\n");
    } else {
        books[index].available = 1;
        printf("Book returned successfully!\n");
    }
}

int main() {
    int choice;

    printf("===============================\n");
    printf("Library Management System\n");
    printf("===============================\n");

    do {
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
