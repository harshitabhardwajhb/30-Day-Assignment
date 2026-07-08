#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define DEPT_LENGTH 30

struct Employee {
    int id;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    float salary;
};

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void addEmployee(struct Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full. Cannot add more employees.\n\n");
        return;
    }

    struct Employee newEmployee;
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    clearInputBuffer();

    printf("Enter employee name: ");
    fgets(newEmployee.name, NAME_LENGTH, stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0';

    printf("Enter department: ");
    fgets(newEmployee.department, DEPT_LENGTH, stdin);
    newEmployee.department[strcspn(newEmployee.department, "\n")] = '\0';

    printf("Enter salary: ");
    scanf("%f", &newEmployee.salary);
    clearInputBuffer();

    employees[*count] = newEmployee;
    (*count)++;
    printf("Employee added successfully.\n\n");
}

void showEmployees(const struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employee records available.\n\n");
        return;
    }

    printf("\nEmployee Records\n");
    printf("--------------------------------------------------------------\n");
    printf("%-6s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-20s %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
    printf("--------------------------------------------------------------\n\n");
}

int findEmployeeById(const struct Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchEmployee(const struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employee records available.\n\n");
        return;
    }

    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n\n", id);
    } else {
        printf("\nEmployee Details:\n");
        printf("ID: %d\n", employees[index].id);
        printf("Name: %s\n", employees[index].name);
        printf("Department: %s\n", employees[index].department);
        printf("Salary: %.2f\n\n", employees[index].salary);
    }
}

void updateEmployee(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employee records available.\n\n");
        return;
    }

    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n\n", id);
        return;
    }

    printf("Enter new name: ");
    fgets(employees[index].name, NAME_LENGTH, stdin);
    employees[index].name[strcspn(employees[index].name, "\n")] = '\0';

    printf("Enter new department: ");
    fgets(employees[index].department, DEPT_LENGTH, stdin);
    employees[index].department[strcspn(employees[index].department, "\n")] = '\0';

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);
    clearInputBuffer();

    printf("Employee updated successfully.\n\n");
}

void deleteEmployee(struct Employee employees[], int *count) {
    if (*count == 0) {
        printf("No employee records available.\n\n");
        return;
    }

    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findEmployeeById(employees, *count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    (*count)--;
    printf("Employee deleted successfully.\n\n");
}

int main(void) {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("Mini Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Show All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                showEmployees(employees, count);
                break;
            case 3:
                searchEmployee(employees, count);
                break;
            case 4:
                updateEmployee(employees, count);
                break;
            case 5:
                deleteEmployee(employees, &count);
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
