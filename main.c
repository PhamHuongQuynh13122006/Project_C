#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int n = 5;
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
                system("cls");
                displayMenu();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                    	system("cls");
                        showAllStudents();
						back_or_exit();
                        break;
                    case 2:
                        addStudent();
                        back_or_exit();
                        break;
                    case 3:
                    	system("cls");
                        editStudent();
                        back_or_exit();
                        break;
                    case 4:
                    	system("cls");
                    	searchStudent();
                    	back_or_exit();
                    	break;
                    case 5:
                    	system("cls");
                    	sort_Student_i_or_d();
                    	break;
					case 6:
						system("cls");
						deleted();
						break;
					case 7:
                        printSlowly("\nExisting student menu",50);
                        printSlowly("...",150);
						printfinish();
                        return 0;
                    default:
                        printf("\tInvalid choice. Please try again.\n");/////////
                        break;
                }
            }
            break;
        case 3:
            printf("Teacher role is under development.\n");
            break;
        case 4:
            printSlowly("\n\tExiting program",50);
            printSlowly("...\n",150);
            printfinish();
            exit(0);
            return 0;
        default:
            printf("Invalid choice. Exiting...\n");
            back_or_exit();
            break;
    }
    return 0;
}


