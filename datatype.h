//#ifndef DATATYPE_H
//#define DATATYPE_H
#include <stdbool.h>

struct Date {
    int day, month, year;
};
struct Student {
    char student_id[10];
    char classroom[10];
    char name[50];
    struct Date date;
    bool gender; // true = male, false = female
    char email[50];
    char phone[20];
    char password[50];
    int number_course;
};

//#endif // DATATYPE_H

