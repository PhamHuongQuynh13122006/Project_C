//main
#include "include/datatype.h"
#include "include/function.h"
#include <stdio.h>
struct information *student;
int main(void) {
    int menu;
    int n;

    menuStudent(&menu);

   switch (menu) {
       case 1:
            addStudent(&student, &n);
            dataSave(&student, &n);
           break;

       case 2:
           dataLoad(&student, &n);
           showStudent(&student, &n);
           break;

       case 3:
           dataLoad(&student, &n);
           searchStudent(&student, &n);
           break;

       case 4:
           dataLoad(&student, &n);
           editStudent(&student, &n);
           dataSave(&student, &n);
           break;

       case 5:
           dataLoad(&student, &n);
           deleteStudent(&student, &n);
           dataSave(&student, &n);
           break;

       case 6:
           dataLoad(&student, &n);
           sortStudentBN(&student, &n);
           dataSave(&student, &n);
           break;

       default:
           printf("Exited !!!");
           return 1;
           break;
   }
    return 0;
}