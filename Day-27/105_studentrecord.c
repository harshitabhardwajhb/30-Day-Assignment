#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

typedef struct {
    int rollNo;
    char name[50];
    int age;
    float marks;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

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

    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
}

void loadFromFile(void) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        return;
    }

    studentCount = fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);
}

void addStudent(void) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[studentCount].rollNo);
    clearInputBuffer();

    printf("Enter Name: ");
    readString(students[studentCount].name, sizeof(students[studentCount].name));

    printf("Enter Age: ");
    scanf("%d", &students[studentCount].age);
    clearInputBuffer();

    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);
    clearInputBuffer();

    studentCount++;
    saveToFile();
    printf("Student added successfully.\n");
}

void displayAllStudents(void) {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("---------------------------------------------------\n");
    printf("Roll No | Name             | Age | Marks\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%-8d | %-15s | %-3d | %.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].age,
               students[i].marks);
    }
}

void searchStudent(void) {
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}

void updateStudent(void) {
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter new Name: ");
            readString(students[i].name, sizeof(students[i].name));

            printf("Enter new Age: ");
            scanf("%d", &students[i].age);
            clearInputBuffer();

            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            clearInputBuffer();

            saveToFile();
            printf("Student updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}

void deleteStudent(void) {
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveToFile();
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}

int main(void) {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting program.\n");
                saveToFile();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
