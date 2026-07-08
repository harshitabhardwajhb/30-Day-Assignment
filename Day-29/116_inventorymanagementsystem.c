#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Item items[100];
    int count = 0, choice, i, id;

    while (1) {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &items[count].id);
                printf("Enter item name: ");
                scanf("%s", items[count].name);
                printf("Enter quantity: ");
                scanf("%d", &items[count].quantity);
                printf("Enter price: ");
                scanf("%f", &items[count].price);
                count++;
                printf("Item added successfully.\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No items available.\n");
                } else {
                    printf("\nInventory List:\n");
                    for (i = 0; i < count; i++) {
                        printf("ID: %d | Name: %s | Qty: %d | Price: %.2f\n",
                               items[i].id, items[i].name, items[i].quantity, items[i].price);
                    }
                }
                break;

            case 3:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                for (i = 0; i < count; i++) {
                    if (items[i].id == id) {
                        printf("Item found:\n");
                        printf("ID: %d | Name: %s | Qty: %d | Price: %.2f\n",
                               items[i].id, items[i].name, items[i].quantity, items[i].price);
                        break;
                    }
                }
                if (i == count) {
                    printf("Item not found.\n");
                }
                break;

            case 4:
                printf("Enter item ID to update quantity: ");
                scanf("%d", &id);
                for (i = 0; i < count; i++) {
                    if (items[i].id == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &items[i].quantity);
                        printf("Quantity updated successfully.\n");
                        break;
                    }
                }
                if (i == count) {
                    printf("Item not found.\n");
                }
                break;

            case 5:
                printf("Exiting inventory system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
