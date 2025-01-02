#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<windows.h>

struct Date {
    int month, day, year;
};

struct Student {
    char student_id[10];
    char classroom[10];
    char name[50];
    struct Date date;
    bool gender; 
    char email[50];
    char phone[20];
    char password[50];
    int number_course;
};

struct Student students[100] = {
    {"1", "ENG_A", "Nguyen Van A", {1, 12, 2000}, true, "TVA@gmail.com", "0123456789", "QAZ123", 3},
    {"2", "ENG_B", "Nguyen Thi V", {23, 5, 2002}, false, "TTV@gmail.com", "0122837333", "qaz468", 4},
    {"3", "ENG_C", "Nguyen Van D", {11, 10, 2004}, true, "TVH@gmail.com", "0738493720", "tdz246", 2},
    {"4", "ENG_D", "Nguyen Van T", {3, 11, 2005}, true, "TVT@gmail.com", "0627392739", "plm678", 5},
    {"5", "ENG_A", "Nguyen Thi B", {18, 2, 2003}, false, "TTB@gmail.com", "0937595931", "ugc789", 1}
};
int n = 5; 

void menuStart(int *menu) {
    do {
        printf("\n*** Student Management System Using C ***\n");
        printf("\n\t    CHOOSE YOUR ROLE\n");
        printf("\t=======================\n");
        printf("\t[1] Admin.\n");
        printf("\t[2] Student.\n");
        printf("\t[3] Teacher.\n");
        printf("\t[4] Exit the Program.\n");
        printf("\n\tEnter your choice: ");
        if (scanf("%d", menu) != 1) {
            printf("Invalid input! Exiting.\n");
            exit(1);
        }
    } while (*menu < 1 || *menu > 4);
}

//hamhamamaaaka
void displayMenu(){
	printf("\n\t     *** Student Menu ***\n");
	printf("\t=============================\n");
    printf("\t[1]. Show student list\n");
    printf("\t[2]. Add a new student\n");
    printf("\t[3]. Edit student information\n");
    printf("\t[4]. Search a student by name\n");
    printf("\t[5]. Sort a student by name\n");
    printf("\t[6]. Delecte a student by name\n");
    printf("\t[7] Exit\n");
    printf("\n\tEnter your choice: ");
}

void showAllStudents() {
    printf("\n\t\t\t\t\t**** All Students List ****\n");
    printf("\n");
    printf("|========================================================================================================|\n");
    printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
    printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-7d |\n",
               students[i].student_id,
               students[i].classroom,
               students[i].name,
               students[i].date.day,
               students[i].date.month,
               students[i].date.year,
               students[i].gender ? "Male" : "Female",
               students[i].email,
               students[i].phone,
               students[i].number_course);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}

void addStudent() {
	struct Student new_student;
	system("cls");
    if (n >= 100) {
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;
    }
    char temp_id[100];
    int check = 0;
    printf("\n\t\t****Add a new student****\n");
    printf("\n\tEnter information for new student:\n");
    while(!check){
    	printf("\n\tInput Student ID: ");
        scanf("%s", temp_id);
        check = 1;
        for(int i=0;i<n;i++){
        	if(strcmp(students[i].student_id,temp_id)==0){
        		printf("Error: Duplicate id\n");
        		check = 0;
        		break;
			}
		}
		if(strlen(temp_id)>10){
			printf("Error : ID cannot be more than 10 characters.\n");
            check = 0;
		}
	}
	strcpy(new_student.student_id,temp_id);
	////////
	char temp_classroom[11];
    while(1){
    printf("\tInput a classroom : ");
    getchar();
    fgets(new_student.classroom,sizeof(new_student.classroom),stdin);
    new_student.classroom[strcspn(new_student.classroom,"\n")]='\0';
	if(strlen(temp_classroom)>10){
			printf("Error : ID classroom cannot be more than 10 characters.\n");
	/*}else if(strlen(temp_classroom) == '0'){
		printf("Error: Classroom cannot be empty ^ ^\n");*/
	}else{
		break;
	}	
	}
	strcpy(new_student.classroom,temp_classroom);
	////////
    printf("\tInput the name: ");
    getchar(); 
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';
    ////////
    printf("\tBirthdate (day month year): ");
    scanf("%d/%d/%d", &new_student.date.day, &new_student.date.month, &new_student.date.year);
    /////////
	printf("\tGender (1 for Male, 0 for Female): ");
    int gender_input;
    getchar();
    scanf("%d", &gender_input);
    new_student.gender = gender_input == 1;
    ///////
    printf("\tEmail: ");
    scanf("%s", new_student.email);
    getchar();
    printf("\tPhone: ");
    scanf("%s", new_student.phone);
    getchar();
    printf("\tPassword: ");
    scanf("%s", new_student.password);
    getchar();
    printf("\tNumber of courses: ");
    scanf("%d", &new_student.number_course);
    getchar();
    students[n] = new_student;
    n++;
    //student[n++]=new_student;
    printf("\tStudent added successfully.\n");
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

    printf("Birthdate (day/month/year) (current: %02d/%02d/%04d): ",
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
    getchar();
    printf("Student information updated successfully.\n");
    
}
void searchStudent() {
    if (n <= 0) {
        printf("\n\tNo student data available to search.\n");
        return;
    }
    char search[50];
    printf("Enter name student to search: ");
    getchar();
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';
    int check = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(students[i].name, search) != NULL) {
            if (check == 0) {
                printf("\n\tStudent information found!!\n");
                printf("|========================================================================================================|\n");
				printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
                printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
            }
            printf("| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-12s | %-7d |\n",
                   students[i].student_id,
                   students[i].classroom,
                   students[i].name,
                   students[i].date.day,
                   students[i].date.month,
                   students[i].date.year,
                   students[i].gender ? "Male" : "Female",
                   students[i].email,
                   students[i].phone,
                   students[i].number_course);
            check = 1;
        }
    }
    if (!check) {
        printf("Student information not found.\n");
    } else {
        printf("|---------------------------------------------------------------------------------------------------------------|\n");
    }
}
//In kieu ms(mili/s)
void printSlowly(const char *mes, int delay){///chonay quennnn
	for(int i = 0; mes[i] != '\0'; i++){
		printf("%c",mes[i]);
		fflush(stdout);
		Sleep(delay);
	}
}
//In ket thuc chuong trinh 
void printfinish(){
	printf("\n\t\t========== Thank You ==========");
	printf("\n\t\t ======= See You Soon ========");
}
void back_or_exit(){
	char choice;
    while(1){
	printf("\n\t\tGo back (b) or Exit (0) ? : ");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice == '0'){
		printSlowly("\n\tExiting program",40);
		printSlowly("...\n",160);
		printfinish();
		exit(0);
	}else if(choice == 'b'){
		return;
		//in la loi do
	}else{
		printSlowly("\n\t\t\tInvalid choice",100);
		printSlowly(" !!!\n",180);
	}
    }
}
/*void deleted(struct Student students[],int *n){
	printf("Input the ID of the student to delete : ");
	int id;
	fflush(stdin);
	scanf("%d",&id);
	int check = -1;
	for(int i=0;i<*n;i++){
		if(students[i].student_id == id){
			check = i;
			break;
		}
	}
	check = -1;
	if(check == -1){
		printf("Student with ID : %d not found ^ ^",id);
	}else{
		printf("Student found with ID : %d is : ");
		printf("You that su muon xoa ID nay chuw : ");
	//	int confirm;
		getchar();
		scanf("%d",confirm);
		if(confirm == "YES"){
		    printf("|========================================================================================================|\n");
				printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
                printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
            }
            printf("| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-12s | %-7d |\n",
                   students[i].student_id,
                   students[i].classroom,
                   students[i].name,
                   students[i].date.day,
                   students[i].date.month,
                   students[i].date.year,
                   students[i].gender ? "Male" : "Female",
                   students[i].email,
                   students[i].phone,
                   students[i].number_course);
	    }else if(confirm == "NO"){
	    ////	
		}else{
			printf("Invalid ....");
		}
		printf("Student found with ID: %d\n", id);
    printf("|========================================================================================================|\n");
    printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
    printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
    printf("| %-2d | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-12s | %-7d |\n",
           students[index].student_id,
           students[index].classroom,
           students[index].name,
           students[index].date.day,
           students[index].date.month,
           students[index].date.year,
           students[index].gender ? "Male" : "Female",
           students[index].email,
           students[index].phone,
           students[index].number_course);

    char confirm[4];
    printf("Are you sure you want to delete this student? (YES/NO): ");
    scanf("%s", confirm);

    if (strcmp(confirm, "YES") == 0) {
        // Delete the student by shifting the array
        for (int i = index; i < *n - 1; i++) {
            students[i] = students[i + 1];
        }
        (*n)--; // Decrease the size of the array
        printf("Student deleted successfully!\n");
    } else if (strcmp(confirm, "NO") == 0) {
        printf("Deletion canceled.\n");
    } else {
        printf("Invalid input. Deletion canceled.\n");
    }
}
	}
}*/
void deleted(struct Student students[], int *n) {
    printf("Input the ID of the student to delete: ");
    char id[10]; 
    fflush(stdin);
    scanf("%s", id);  
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i].student_id, id) == 0) {
            index = i; 
            break;
        }
    }
    if (index == -1) {
        printf("Student with ID: %s not found.\n", id);
    } else {
        printf("Student found with ID: %s\n", id);
        printf("|========================================================================================================|\n");
        printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
        printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
        printf("| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-12s | %-7d |\n",
               students[index].student_id,
               students[index].classroom,
               students[index].name,
               students[index].date.day,
               students[index].date.month,
               students[index].date.year,
               students[index].gender ? "Male" : "Female",
               students[index].email,
               students[index].phone,
               students[index].number_course);
        printf("|========================================================================================================|\n");

        char confirm[4];
        printf("Are you sure you want to delete this student? (YES/NO): ");
        scanf("%s", confirm);

        if (strcmp(confirm, "YES") == 0) {
            for (int i = index; i < *n - 1; i++) {
                students[i] = students[i + 1];
            }
            (*n)--;  
            printf("Student deleted successfully!\n");
        } else if (strcmp(confirm, "NO") == 0) {
            printf("Deletion canceled.\n");
        } else {
            printf("Invalid input. Deletion canceled.\n");
        }
    }
}

 
//0giam1tang
void sort_Student_i_or_d(struct Student students[100],int n){
	struct Student temp;
	int check = 0;
	char choice;
	do{
		printf("Choose the order in which student list is sorted : \n");
		printf("\n\t\t[1]. Increase\n");
		printf("\t\t[2]. Decrease\n");
		printf("\n\tYour choice : ");
	    //while(getchar() != '\n');
	    //getchar();
	    fflush(stdin);
		scanf("%c", &choice);
	}
	while(choice != '1' && choice != '2');
	check = (choice == '1'? 1 : 0);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(check ? strcmp(students[i].name, students[j].name)>0:
			           strcmp(students[i].name,students[j].name)<0){
					   temp = students[i];
					   students[i]=students[j];
					   students[j]=temp;
			}
		}
	}
	printf("\nThe list of students after sorting is : \n");
	printf("\n\t\t|========================================================================================================|\n");
	printf("\t\t| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
    printf("\t\t|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
    for(int i = 0; i < n; i++){
        printf("\t\t| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-7d |\n",
		        students[i].student_id,
                students[i].classroom,
                students[i].name,
                students[i].date.day,
                students[i].date.month,
                students[i].date.year,
                students[i].gender ? "Male" : "Female",
                students[i].email,
                students[i].phone,
                students[i].number_course);
    }
    printf("\t\t----------------------------------------------------------------------------------------------------------\n");
    back_or_exit();
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
                    	sort_Student_i_or_d(students,n);
                    	break;
					case 6:
						system("cls");
						deleted(students, &n);
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


