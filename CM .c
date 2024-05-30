#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

// Structure to store student information
struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
};

// Function to add a new student record
void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter student age: ");
    scanf("%d", &students[*numStudents].age);
    printf("Enter student GPA: ");
    scanf("%f", &students[*numStudents].gpa);

    (*numStudents)++;
}

// Function to display all student records
void displayStudents(struct Student students[], int numStudents) {
    printf("Student Records:\n");
    printf("Name\t\tAge\t\tGPA\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\t\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
