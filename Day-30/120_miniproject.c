#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 50
#define NAME_LEN 50
#define CATEGORY_LEN 30

struct Item {
    int id;
    char name[NAME_LEN];
    char category[CATEGORY_LEN];
    int quantity;
};

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void addItem(struct Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n\n");
        return;
    }

    struct Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    clearInputBuffer();

    printf("Enter item name: ");
    fgets(newItem.name, NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    printf("Enter item category: ");
    fgets(newItem.category, CATEGORY_LEN, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    clearInputBuffer();

    items[*count] = newItem;
    (*count)++;
    printf("Item added successfully.\n\n");
}

void showItems(const struct Item items[], int count) {
    if (count == 0) {
        printf("No items in the inventory.\n\n");
        return;
    }

    printf("\nMini Project Inventory\n");
    printf("--------------------------------------------------------------\n");
    printf("%-6s %-20s %-18s %-8s\n", "ID", "Name", "Category", "Qty");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-18s %-8d\n",
               items[i].id,
               items[i].name,
               items[i].category,
               items[i].quantity);
    }
    printf("--------------------------------------------------------------\n\n");
}

int findItemById(const struct Item items[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchItem(const struct Item items[], int count) {
    if (count == 0) {
        printf("No items in the inventory.\n\n");
        return;
    }

    int id;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findItemById(items, count, id);
    if (index == -1) {
        printf("Item with ID %d not found.\n\n", id);
    } else {
        printf("\nItem Details:\n");
        printf("ID: %d\n", items[index].id);
        printf("Name: %s\n", items[index].name);
        printf("Category: %s\n", items[index].category);
        printf("Quantity: %d\n\n", items[index].quantity);
    }
}

void updateItem(struct Item items[], int count) {
    if (count == 0) {
        printf("No items in the inventory.\n\n");
        return;
    }

    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findItemById(items, count, id);
    if (index == -1) {
        printf("Item with ID %d not found.\n\n", id);
        return;
    }

    printf("Enter new item name: ");
    fgets(items[index].name, NAME_LEN, stdin);
    items[index].name[strcspn(items[index].name, "\n")] = '\0';

    printf("Enter new category: ");
    fgets(items[index].category, CATEGORY_LEN, stdin);
    items[index].category[strcspn(items[index].category, "\n")] = '\0';

    printf("Enter new quantity: ");
    scanf("%d", &items[index].quantity);
    clearInputBuffer();

    printf("Item updated successfully.\n\n");
}

void deleteItem(struct Item items[], int *count) {
    if (*count == 0) {
        printf("No items in the inventory.\n\n");
        return;
    }

    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findItemById(items, *count, id);
    if (index == -1) {
        printf("Item with ID %d not found.\n\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        items[i] = items[i + 1];
    }
    (*count)--;
    printf("Item deleted successfully.\n\n");
}

int main(void) {
    struct Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        printf("Mini Project - Inventory Management\n");
        printf("1. Add Item\n");
        printf("2. Show All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                showItems(items, count);
                break;
            case 3:
                searchItem(items, count);
                break;
            case 4:
                updateItem(items, count);
                break;
            case 5:
                deleteItem(items, &count);
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
