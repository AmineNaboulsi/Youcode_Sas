#ifndef HEADER_H
#define HEADER_H
#define List_Length 200

typedef struct{
    int day;
    int month;
    int year;
}DateTime;

typedef struct{
    int IdDep ;
    char NameD[255];
}Department;

typedef struct{
    int Id;
    char Firstame[255];
    char LastName[255];
    DateTime date;
    Department Department;
    float Note;
}Student;

int Id_Counter ;
int List_Counter ;
int List_Dep_Conter ;

//Main menu
void MainList_Options();

//Add Student
void Add_Student(Student List_Student[],Department List_Departement[],int len);

//Update Student
void Update_Student(Student List_Student[],Department List_Departement[]);

//Delete student
void Delete_Student(Student List_Student[], int ID);

//Display Student
void DisplayStudent(Student List_Student[]);

//Search Student By ID 
int getStudientById(Student List_Student[] ,int Student_id);

//Fill the Name departement using ID Picked from Drop down list  
void gestDepartementById(int Id , char* Dep,Department List_Departement[],int len);

//DateTime Validation
int check_Day_Validation(int day);
int check_Month_Validation(int month);
int check_Year_Validation(int year);

//-------Statistics

//Calculate avarage for eatch departement 
float GetDepartementAvg(Student List_Student[],char name[]);


//-------Sort 

//Sort A - Z
void SortACS(Student List_Student[]);

//Sort highest to lowest
void SortACSByAvg(Student List_Student[]);

//Sort and get top 3 
void SortAndGet_TopTree(Student List_Student[]);


#endif