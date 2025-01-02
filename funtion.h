//#ifndef FUNTION_H
//#define FUNTION_H
#include "datatype.h"
#include "include/function.h"
//Nguyen mau ham 

void printSlowly(const char *mes, int delay);
void printfinish();
void back_or_exit();
void menuStart(*menu);
void displayMenu();
void showAllStudents();
void addStudent();
void editStudent();
void searchStudent();
void deleted(struct Student students[], int *n);
void sort_Student_i_or_d(struct Student students[100],int n);
//void saveToFile(struct Student *students, int n, const char *filename);
//void loadFromFile(struct Student *students, int *n, const char *filename);

//#endif 

