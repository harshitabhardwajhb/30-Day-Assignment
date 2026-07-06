#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char holderName[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int count = 0;

void readInput(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int findAccount(int accountNumber) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

void createAccount() {
    if (count >= MAX_ACCOUNTS) {
        printf("Bank is full. Cannot create more accounts.\n");
        return;
    }

    Account a;
    printf("Enter Account Number: ");
    scanf("%d", &a.accountNumber);
    getchar();

    printf("Enter Holder Name: ");
    readInput(a.holderName, sizeof(a.holderName));

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);
    getchar();

    accounts[count++] = a;
    printf("Account created successfully!\n");
}

void displayAccounts() {
    if (count == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("\nAccount Details:\n");
    printf("Account No.\tHolder Name\t\tBalance\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t\t%-20s%.2f\n",
               accounts[i].accountNumber,
               accounts[i].holderName,
               accounts[i].balance);
    }
}

void depositMoney() {
    int accNo;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);
    getchar();

    int index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found.\n");
    } else {
        accounts[index].balance += amount;
        printf("Deposit successful!\n");
    }
}

void withdrawMoney() {
    int accNo;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);
    getchar();

    int index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found.\n");
    } else if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
    } else {
        accounts[index].balance -= amount;
        printf("Withdrawal successful!\n");
    }
}

void checkBalance() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();

    int index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found.\n");
    } else {
        printf("Balance for account %d is %.2f\n", accounts[index].accountNumber, accounts[index].balance);
    }
}

int main() {
    int choice;

    printf("===============================\n");
    printf("Bank Account Management System\n");
    printf("===============================\n");

    do {
        printf("\n1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                checkBalance();
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
