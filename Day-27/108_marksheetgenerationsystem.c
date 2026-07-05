#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "marksheets.dat"

typedef struct {
    int rollNo;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
} StudentMarks;

StudentMarks students[MAX_STUDENTS];
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

    fwrite(students, sizeof(StudentMarks), studentCount, file);
    fclose(file);
}

void loadFromFile(void) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        return;
    }

    studentCount = fread(students, sizeof(StudentMarks), MAX_STUDENTS, file);
    fclose(file);
}

void calculateResult(StudentMarks *s) {
    int i;
    s->total = 0;

    for (i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }

    s->percentage = (float)s->total / 5;

    if (s->percentage >= 90) {
        s->grade = 'A';
    } else if (s->percentage >= 80) {
        s->grade = 'B';
    } else if (s->percentage >= 70) {
        s->grade = 'C';
    } else if (s->percentage >= 60) {
        s->grade = 'D';
    } else {
        s->grade = 'F';
    }
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

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &students[studentCount].marks[i]);
    }
    clearInputBuffer();

    calculateResult(&students[studentCount]);
    studentCount++;
    saveToFile();
    printf("Student marks added successfully.\n");
}

void displayAllMarksheets(void) {
    if (studentCount == 0) {
        printf("No marksheet records found.\n");
        return;
    }

    printf("\nMarksheet Records:\n");
    printf("-------------------------------------------------------------\n");
    printf("Roll | Name           | Total | Percentage | Grade\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%-4d | %-14s | %-5d | %-10.2f | %c\n",
               students[i].rollNo,
               students[i].name,
               students[i].total,
               students[i].percentage,
               students[i].grade);
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
            printf("\nMarksheet for Student:\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Subject Marks:\n");
            for (int j = 0; j < 5; j++) {
                printf("  Subject %d: %d\n", j + 1, students[i].marks[j]);
            }
            printf("Total: %d\n", students[i].total);
            printf("Percentage: %.2f\n", students[i].percentage);
            printf("Grade: %c\n", students[i].grade);
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

            printf("Enter new marks for 5 subjects:\n");
            for (int j = 0; j < 5; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%d", &students[i].marks[j]);
            }
            clearInputBuffer();

            calculateResult(&students[i]);
            saveToFile();
            printf("Student marks updated successfully.\n");
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
            printf("Student marks deleted successfully.\n");
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
        printf("\n===== Marksheet Generation System =====\n");
        printf("1. Add Student Marks\n");
        printf("2. Display All Marksheet Records\n");
        printf("3. Search Student Marksheet\n");
        printf("4. Update Student Marks\n");
        printf("5. Delete Student Marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllMarksheets();
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
