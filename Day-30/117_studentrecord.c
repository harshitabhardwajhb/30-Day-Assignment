#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int id;
    char name[NAME_LENGTH];
    char grade;
    float marks;
};

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full. Cannot add more records.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    clearInputBuffer();

    printf("Enter student name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter student grade (A-F): ");
    scanf(" %c", &newStudent.grade);
    clearInputBuffer();

    printf("Enter student marks: ");
    scanf("%f", &newStudent.marks);
    clearInputBuffer();

    students[*count] = newStudent;
    (*count)++;
    printf("Record added successfully.\n\n");
}

void showStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n\n");
        return;
    }

    printf("\nStudent Records\n");
    printf("----------------------------------------------------\n");
    printf("%-6s %-20s %-7s %-7s\n", "ID", "Name", "Grade", "Marks");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-7c %-7.2f\n",
               students[i].id,
               students[i].name,
               students[i].grade,
               students[i].marks);
    }
    printf("----------------------------------------------------\n\n");
}

int findStudentById(const struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n\n");
        return;
    }

    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("Student with ID %d not found.\n\n", id);
    } else {
        printf("\nFound Student:\n");
        printf("ID: %d\n", students[index].id);
        printf("Name: %s\n", students[index].name);
        printf("Grade: %c\n", students[index].grade);
        printf("Marks: %.2f\n\n", students[index].marks);
    }
}

void updateStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n\n");
        return;
    }

    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("Student with ID %d not found.\n\n", id);
        return;
    }

    printf("Enter new student name: ");
    fgets(students[index].name, NAME_LENGTH, stdin);
    students[index].name[strcspn(students[index].name, "\n")] = '\0';

    printf("Enter new student grade (A-F): ");
    scanf(" %c", &students[index].grade);
    clearInputBuffer();

    printf("Enter new student marks: ");
    scanf("%f", &students[index].marks);
    clearInputBuffer();

    printf("Record updated successfully.\n\n");
}

void deleteStudent(struct Student students[], int *count) {
    if (*count == 0) {
        printf("No student records available.\n\n");
        return;
    }

    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(students, *count, id);
    if (index == -1) {
        printf("Student with ID %d not found.\n\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    printf("Record deleted successfully.\n\n");
}

void sortStudentsById(struct Student students[], int count) {
    if (count < 2) {
        printf("Not enough records to sort.\n\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Records sorted by student ID.\n\n");
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("Student Record System\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by ID\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 6:
                sortStudentsById(students, count);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 7);

    return 0;
}
