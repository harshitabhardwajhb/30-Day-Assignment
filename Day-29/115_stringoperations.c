#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp[100], ch;
    int choice, len, i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    while (1) {
        printf("\n===== String Operations Menu =====\n");
        printf("1. Display String\n");
        printf("2. Length of String\n");
        printf("3. Reverse String\n");
        printf("4. Convert to Uppercase\n");
        printf("5. Convert to Lowercase\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("String: %s\n", str);
                break;
            case 2:
                len = strlen(str);
                printf("Length of string: %d\n", len);
                break;
            case 3:
                len = strlen(str);
                for (i = 0, j = len - 1; i < j; i++, j--) {
                    temp[i] = str[i];
                    str[i] = str[j];
                    str[j] = temp[i];
                }
                printf("Reversed string: %s\n", str);
                break;
            case 4:
                for (i = 0; str[i] != '\0'; i++) {
                    if (str[i] >= 'a' && str[i] <= 'z') {
                        str[i] = str[i] - 32;
                    }
                }
                printf("Uppercase string: %s\n", str);
                break;
            case 5:
                for (i = 0; str[i] != '\0'; i++) {
                    if (str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] = str[i] + 32;
                    }
                }
                printf("Lowercase string: %s\n", str);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
