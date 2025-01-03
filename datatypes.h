#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct Date{
	int month,day,year; 
};
struct Student{
	char student_id[100];
	char classroom[100];
	char name[50];
	struct Date date;
	bool gender;
	char email[50];
	char phone[20];
	char password[50];
	int number_course;
};
struct Student students[5] = {
    {"1", "ENG_A", "Nguyen Van A", {1, 12, 2000}, true, "TVA@gmail.com", "0123456789", "QAZ123", 3},
    {"2", "ENG_B", "Nguyen Thi V", {23, 5, 2002}, false, "TTV@gmail.com", "0122837333", "qaz468", 4},
    {"3", "ENG_C", "Nguyen Van D", {11, 10, 2004}, true, "TVH@gmail.com", "0738493720", "tdz246", 2},
    {"4", "ENG_D", "Nguyen Van T", {3, 11, 2005}, true, "TVT@gmail.com", "0627392739", "plm678", 5},
    {"5", "ENG_A", "Nguyen Thi B", {18, 2, 2003}, false, "TTB@gmail.com", "0937595931", "ugc789", 1}
}
struct Classroom{
	char classroom_id[10];
    char teacher[10];
	char classroom[20];
	struct Student student[];
};


