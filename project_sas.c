#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int check_Day_Validation(int day){
    if(1<=day && day<=31)
        return 1;
    else 
        return 0;
}
int check_Month_Validation(int month){
   if(1<=month && month<=12)
        return 1;
    else 
        return 0;  
}
int check_Year_Validation(int year){
   if(1700<=year && year<=2999)
        return 1;
    else 
        return 0;
}

typedef struct{
    int Id;
    char Firstame[255];
    char LastName[255];
    DateTime date;
    Department Department;
    float Note;
}Student;

int Id_Counter = 1;
int List_Counter = 0;

//Ajouter un étudiant :
//Modifier ou supprimer un étudiant :
//Afficher les détails d'un étudiant :
//Calculer la moyenne générale :
//Statistiques :
//Rechercher un étudiant par:
//Trier un étudiant par:

void Add_Student(Student List_Student[]){

    //Add Student
    List_Student[List_Counter].Id = Id_Counter++;
    printf("Enter the student first name :");
    scanf("%s",List_Student[List_Counter].Firstame);
    printf("Enter the student last name :");
    scanf("%s",List_Student[List_Counter].LastName);

    //Day validation
    printf("Enter date birth start with \n");
    InvalidYear:
    printf("\tYear : ");
    scanf("%d",&List_Student[List_Counter].date.year);
    if(check_Year_Validation(List_Student[List_Counter].date.year)==0)
        goto InvalidYear;

    //Month validation
    InvalidMonth:
    printf("\tMounth : ");
    scanf("%d",&List_Student[List_Counter].date.month);
    if(check_Month_Validation(List_Student[List_Counter].date.month)==0)
        goto InvalidMonth;

    //Day validation
    InvalidDay:
    printf("\tDay : ");
    scanf("%d",&List_Student[List_Counter].date.day);
    if(check_Day_Validation(List_Student[List_Counter].date.day)==0)
        goto InvalidDay;
    
    printf("\nEnter the student Department :");
    scanf("%s",List_Student[List_Counter].Department.NameD);
    printf("\nEnter the student generate note :");
    scanf("%f",&List_Student[List_Counter].Note);

    //Increment List_Counter after adding student
    List_Counter++;
}


void DisplayStudent(Student List_Student[]){
    printf("\n-------------------------------------------------------------------\n");
    printf("%-2s %-15s %-20s %-20s %-25s %-2s\n","|","First Name","Last Name","Department","Note","|") ;
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < List_Counter; i++)
    {
        printf("%-2s %-15s %-20s %-20s %.2f %-2s\n","|",List_Student[i].Firstame,List_Student[i].LastName,List_Student[i].Department.NameD,&List_Student[i].Note,"|") ;
        printf("-------------------------------------------------------------------\n");
    }
    if(List_Counter==0)
    {
        printf("%-2s %-20s %-41s %-2s\n","|","","Empty List","|") ;
        printf("-------------------------------------------------------------------\n\n");
    }
}


float GetDepartementAvg(Student List_Student[],char Departement[]){
    int Count_Student = 0;
    int Avg = 0;
    for (int i = 0; i < List_Counter; i++)
    {
        if(strcasecmp(List_Student[List_Counter].LastName ,Departement )){
            Count_Student++;
            Avg++;
        }
   }
   if(Count_Student == 0)
      return -1 ;
   else 
      return Avg/=Count_Student;
}


void DisplayDepartementAvg(Student List_Student[],Department List_Departement[]){
    //Display Table Departement Avg
    int len = sizeof(List_Departement) / sizeof(List_Departement[0]);
    printf("\n-------------------------------------------------------------------\n");
    printf("%-2s %-15s %-20s %-2s\n","|","Departement","Avg","|") ;
    printf("-------------------------------------------------------------------\n");  
    for (size_t i = 0; i < len; i++)
    {
            printf("%-2s %-15s %.2f %-2s\n","|",
                        List_Student[i].Department.NameD,
                        GetDepartementAvg(List_Student , List_Student[i].Department.NameD)==-1?0.0:GetDepartementAvg(List_Student ,List_Student[i].Department.NameD),
                        "|") ;
            printf("-------------------------------------------------------------------\n");
    }
}


void Fill_Department(Department List_Department[]) {
    // Fill Data
    List_Department[0].IdDep = 1;
    strcpy(List_Department[0].NameD, "A");

    List_Department[1].IdDep = 2;
    strcpy(List_Department[1].NameD, "B");

    List_Department[2].IdDep = 3;
    strcpy(List_Department[2].NameD, "C");

    List_Department[3].IdDep = 4;
    strcpy(List_Department[3].NameD, "D");

    List_Department[4].IdDep = 5;
    strcpy(List_Department[4].NameD, "E");
}


int main(){
    //Option picked
    int Picked_Option ;
    //Student List
    Student List_Student[List_Length];
    //Department List
    Department List_Department[5];
    //Fill dataset
    Fill_Department(List_Department);

    do{
        printf("%-70s\n","_______________________________________________________________");
        printf("%-5s %-60s \n","","1. Add student");        
        printf("%-5s %-60s \n","","2. Update student");
        printf("%-5s %-60s \n","","3. Delete student");
        printf("%-5s %-60s \n","","4. View student details");
        printf("%-5s %-60s \n","","5. General average");
        printf("%-5s %-60s \n","","6. Search on student");
        printf("%-5s %-60s \n","","7. Sort student");
        printf("%-5s %-60s \n","","7. Exit");
        printf("%-70s \n","_______________________________________________________________");
        printf("Choose : ");
        scanf("%d",&Picked_Option);
        switch (Picked_Option){
        case 1:
            Add_Student(List_Student);
            break;
        case 4:
            DisplayStudent(List_Student);
            break;
        case 5:
            DisplayDepartementAvg(List_Student ,List_Department);
            break;
        default:
            break;
        }
    }while(Picked_Option!=8);
   
    

    return 0 ;
}