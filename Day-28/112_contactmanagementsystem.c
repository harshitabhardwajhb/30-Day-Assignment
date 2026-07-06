#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    int id;
    char name[50];
    char phone[15];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int count = 0;

void readInput(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int findContact(int id) {
    for (int i = 0; i < count; i++) {
        if (contacts[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addContact() {
    if (count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    Contact c;
    printf("Enter Contact ID: ");
    scanf("%d", &c.id);
    getchar();

    printf("Enter Name: ");
    readInput(c.name, sizeof(c.name));

    printf("Enter Phone Number: ");
    readInput(c.phone, sizeof(c.phone));

    printf("Enter Email: ");
    readInput(c.email, sizeof(c.email));

    contacts[count++] = c;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nContact List:\n");
    printf("ID\tName\t\tPhone\t\tEmail\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s%-15s%-20s\n",
               contacts[i].id,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }
}

void searchContact() {
    int id;
    printf("Enter Contact ID to search: ");
    scanf("%d", &id);
    getchar();

    int index = findContact(id);
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("\nContact Found:\n");
        printf("ID: %d\n", contacts[index].id);
        printf("Name: %s\n", contacts[index].name);
        printf("Phone: %s\n", contacts[index].phone);
        printf("Email: %s\n", contacts[index].email);
    }
}

void deleteContact() {
    int id;
    printf("Enter Contact ID to delete: ");
    scanf("%d", &id);
    getchar();

    int index = findContact(id);
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        for (int i = index; i < count - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        count--;
        printf("Contact deleted successfully!\n");
    }
}

int main() {
    int choice;

    printf("===============================\n");
    printf("Contact Management System\n");
    printf("===============================\n");

    do {
        printf("\n1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
