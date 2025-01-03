#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct d?nh nghia
struct Date {
    int month, day, year;
};

struct Student {
    char student_id[100];
    char classroom[100];
    char name[50];
    struct Date date;
    bool gender; // true: Male, false: Female
    char email[50];
    char phone[20];
    char password[50];
    int number_course;
};

// M?ng sinh viên m?u
struct Student students[100] = {
    {"1", "ENG_A", "Nguyen Van A", {1, 12, 2000}, true, "TVA@gmail.com", "0123456789", "QAZ123", 3},
    {"2", "ENG_B", "Nguyen Thi V", {23, 5, 2002}, false, "TTV@gmail.com", "0122837333", "qaz468", 4},
    {"3", "ENG_C", "Nguyen Van D", {11, 10, 2004}, true, "TVH@gmail.com", "0738493720", "tdz246", 2},
    {"4", "ENG_D", "Nguyen Van T", {3, 11, 2005}, true, "TVT@gmail.com", "0627392739", "plm678", 5},
    {"5", "ENG_A", "Nguyen Thi B", {18, 2, 2003}, false, "TTB@gmail.com", "0937595931", "ugc789", 1}
};
int n = 5; // S? lu?ng sinh viên hi?n t?i

// Hàm hi?n th? menu chính
void menuStart(int *menu) {
    do {
        printf("\n*** Student Management System Using C ***\n");
        printf("\t[1] Admin.\n");
        printf("\t[2] Student.\n");
        printf("\t[3] Teacher.\n");
        printf("\t[0] Exit the Program.\n");
        printf("Enter your choice: ");
        if (scanf("%d", menu) != 1) {
            printf("Invalid input! Exiting.\n");
            exit(1);
        }
    } while (*menu < 0 || *menu > 3);
}
void displayMenu(){
	printf("\n\t*** Student Menu ***\n");
    printf("\t[1] Show student list\n");
    printf("\t[2] Add a new student\n");
    printf("\t[3] Edit student information\n");
    printf("\t[0] Exit\n");
    printf("Enter your choice: ");
}

void showAllStudents() {
    printf("\n**** All Students ****\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
    printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         |  Pass_word   | Courses |\n");
    printf("|____|___________|________________|____________|_________|_____________________|_______________|______________|_________|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-12s | %-7d |\n",
               students[i].student_id,
               students[i].classroom,
               students[i].name,
               students[i].date.day,
               students[i].date.month,
               students[i].date.year,
               students[i].gender ? "Male" : "Female",
               students[i].email,
               students[i].phone,
               students[i].password,
               students[i].number_course);
    }
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}

void addStudent() {
    if (n >= 100) {
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;
    }

    struct Student new_student;
    printf("\nEnter information for new student:\n");
    printf("Student ID: ");
    scanf("%s", new_student.student_id);

    printf("Classroom: ");
    scanf("%s", new_student.classroom);

    printf("Name: ");
    getchar(); 
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';

    printf("Birthdate (day month year): ");
    scanf("%d %d %d", &new_student.date.day, &new_student.date.month, &new_student.date.year);
    getchar();
    printf("Gender (1 for Male, 0 for Female): ");
    int gender_input;
    scanf("%d", &gender_input);
    new_student.gender = gender_input == 1;

    printf("Email: ");
    scanf("%s", new_student.email);
    getchar();
    printf("Phone: ");
    scanf("%s", new_student.phone);
    getchar();
    printf("Password: ");
    scanf("%s", new_student.password);
    getchar();
    printf("Number of courses: ");
    scanf("%d", &new_student.number_course);
    getchar();
    students[n] = new_student;
    n++;
    printf("Student added successfully.\n");
}

void editStudent() {
    char student_id[100];
    printf("\nEnter the ID of the student to edit: ");
    scanf("%s", student_id);

    int found = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Student with ID %s not found.\n", student_id);
        return;
    }

    struct Student *student = &students[found];
    printf("\nEditing information for student %s:\n", student->name);

    printf("Classroom (current: %s): ", student->classroom);
    scanf("%s", student->classroom);

    printf("Name (current: %s): ", student->name);
    getchar(); 
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    printf("Birthdate (day month year) (current: %02d/%02d/%04d): ",
           student->date.day, student->date.month, student->date.year);
    scanf("%d %d %d", &student->date.day, &student->date.month, &student->date.year);

    printf("Gender (1 for Male, 0 for Female) (current: %s): ",
           student->gender ? "Male" : "Female");
    int gender_input;
    scanf("%d", &gender_input);
    student->gender = gender_input == 1;

    printf("Email (current: %s): ", student->email);
    scanf("%s", student->email);

    printf("Phone (current: %s): ", student->phone);
    scanf("%s", student->phone);

    printf("Password (current: %s): ", student->password);
    scanf("%s", student->password);

    printf("Number of courses (current: %d): ", student->number_course);
    scanf("%d", &student->number_course);

    printf("Student information updated successfully.\n");
}

int main() {
    int menu;
    menuStart(&menu);

    switch (menu) {
        case 1:
            printf("Admin role is under development.\n");
            break;
        case 2:
            while (1) {
                int choice;
                displayMenu();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        showAllStudents();
                        break;
                    case 2:
                        addStudent();
                        break;
                    case 3:
                        editStudent();
                        break;
                    case 0:
                        printf("Exiting student menu...\n");
                        return 0;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }
            }
            break;
        case 3:
            printf("Teacher role is under development.\n");
            break;
        case 0:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    return 0;
}

