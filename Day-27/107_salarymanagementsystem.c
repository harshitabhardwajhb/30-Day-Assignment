#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define FILE_NAME "salary_records.dat"

typedef struct {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float bonus;
    float totalSalary;
} EmployeeSalary;

EmployeeSalary employees[MAX_EMPLOYEES];
int employeeCount = 0;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void readString(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void saveToFile(void) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Unable to save records.\n");
        return;
    }

    fwrite(employees, sizeof(EmployeeSalary), employeeCount, file);
    fclose(file);
}

void loadFromFile(void) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        return;
    }

    employeeCount = fread(employees, sizeof(EmployeeSalary), MAX_EMPLOYEES, file);
    fclose(file);
}

void calculateSalary(EmployeeSalary *emp) {
    emp->totalSalary = emp->basicSalary + emp->bonus;
}

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Salary list is full.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &employees[employeeCount].id);
    clearInputBuffer();

    printf("Enter Name: ");
    readString(employees[employeeCount].name, sizeof(employees[employeeCount].name));

    printf("Enter Department: ");
    readString(employees[employeeCount].department, sizeof(employees[employeeCount].department));

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[employeeCount].basicSalary);
    clearInputBuffer();

    printf("Enter Bonus: ");
    scanf("%f", &employees[employeeCount].bonus);
    clearInputBuffer();

    calculateSalary(&employees[employeeCount]);
    employeeCount++;
    saveToFile();
    printf("Employee salary record added successfully.\n");
}

void displayAllEmployees(void) {
    if (employeeCount == 0) {
        printf("No salary records found.\n");
        return;
    }

    printf("\nSalary Records:\n");
    printf("--------------------------------------------------------------\n");
    printf("ID | Name           | Department     | Basic Salary | Bonus | Total Salary\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++) {
        printf("%-2d | %-14s | %-14s | %-12.2f | %-5.2f | %.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].basicSalary,
               employees[i].bonus,
               employees[i].totalSalary);
    }
}

void searchEmployee(void) {
    int id;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Bonus: %.2f\n", employees[i].bonus);
            printf("Total Salary: %.2f\n", employees[i].totalSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void updateEmployee(void) {
    int id;
    int found = 0;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Enter new Name: ");
            readString(employees[i].name, sizeof(employees[i].name));

            printf("Enter new Department: ");
            readString(employees[i].department, sizeof(employees[i].department));

            printf("Enter new Basic Salary: ");
            scanf("%f", &employees[i].basicSalary);
            clearInputBuffer();

            printf("Enter new Bonus: ");
            scanf("%f", &employees[i].bonus);
            clearInputBuffer();

            calculateSalary(&employees[i]);
            saveToFile();
            printf("Employee salary record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee(void) {
    int id;
    int found = 0;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            saveToFile();
            printf("Employee salary record deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void displayTotalSalary(void) {
    float total = 0;

    for (int i = 0; i < employeeCount; i++) {
        total += employees[i].totalSalary;
    }

    printf("\nTotal Salary Expense: %.2f\n", total);
}

int main(void) {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee Salary\n");
        printf("2. Display All Salary Records\n");
        printf("3. Search Employee Salary\n");
        printf("4. Update Employee Salary\n");
        printf("5. Delete Employee Salary\n");
        printf("6. Show Total Salary Expense\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                displayTotalSalary();
                break;
            case 7:
                printf("Exiting program.\n");
                saveToFile();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
