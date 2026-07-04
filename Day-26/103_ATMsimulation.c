#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.0, deposit, withdraw;

    printf("Welcome to the ATM Simulation\n");
    printf("Initial Balance: $%.2f\n", balance);

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current Balance: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &deposit);
                balance += deposit;
                printf("Deposit successful. New Balance: $%.2f\n", balance);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdraw);
                if (withdraw <= balance) {
                    balance -= withdraw;
                    printf("Withdrawal successful. New Balance: $%.2f\n", balance);
                } else {
                    printf("Insufficient balance.\n");
                }
                break;
            case 4:
                printf("Thank you for using the ATM.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
