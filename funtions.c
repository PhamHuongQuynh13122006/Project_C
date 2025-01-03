#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//logic ham 
//ham hien thi menu khi bat dau
void menuStart(int *menu) {
    do {
        printf(" *** Student Management System Using C *** \n");
        printf("\n");
        printf("\t\tCHOOSE YOUR ROLE\n");
        printf("\t=========================\n");
        printf("\t[1] Admin.\n");
        printf("\t[2] Student.\n");
        printf("\t[3] Teacher.\n");
        printf("\t[0] Exit the Program.\n");
        printf("\t=========================\n");
        printf("Enter your choice: ");
        scanf("%d", menu);
    } while (*menu > 3 || *menu < 0);
}

//ham hien thi menu for student
void displayMenu() {
	int choice;
	printf("\n***Student Management System Using C***\n");
    printf("\t\t\tSTUDENT MENU\n");
    printf("\t\t====================\n");
    printf("[1] Show student list")
    printf("[1] Add a new Student\n");
    printf("[2] Edit a student information\n");
    printf("[3] Delete a student\n");
    printf("[4] Search for a student by name\n");
    printf("[5] Arange a student list by name\n");
    printf("[0] Exit the Program.\n");
    printf("\t\t========================\n");
    printf("Enter The Choice: ");
    scanf("%d", &choice);
}
//ham in thong tin 5 sinh vien ban dau
void showAllStudents() {
    printf("\n**** All Students ****\n");
    printf(" ---------------------------------------------------------------------------------------------------------------------- \n");
    printf("| ID | Classroom|   Name         | Birthdate  | Gender  | Email               | Phone            | Password | No.Course|\n");
    printf("|____|__________|________________|____________|_________|_____________________|__________________|__________|__________|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-2s | %-8s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-16s | %-8s | %-8d |\n",
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
    printf("|____|__________|________________|____________|_________|_____________________|__________________|__________|__________|\n");
    printf("Go back(b)? or Exit(0)?: ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'b'){
        displayMenu();
    } else if (choice == '6'){
    	break;
    }
}
//
