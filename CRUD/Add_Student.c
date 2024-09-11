#include "header.h"

//Add student
void Add_Student(Student List_Student[],Department List_Departement[],int len){
    if(List_Counter>List_Length){
        printf("\nThis App version not support memory allocation, try later.\n");
        return ;
    }
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
    
    //Departement
    int ID_Picked = -1;
    printf("\nEnter the student Department :\n");
    printf("\t 0-Adding new Departement.\n");
    for (int i = 0; i < List_Dep_Conter; i++)
    {
        printf("\t %d-%s.\n",List_Departement[i].IdDep,List_Departement[i].NameD);
    }

    InvalidDep:
    printf("choose : ");
    scanf("%d",&ID_Picked);
    if(ID_Picked<0 || List_Dep_Conter<ID_Picked)
        goto InvalidDep;
    else if(ID_Picked==0){
        char new_dep[255];
        printf("Enter new dep : ");
        scanf("%s",new_dep);
        List_Departement[List_Dep_Conter].IdDep = List_Dep_Conter + 1 ;
        strcpy(List_Departement[List_Dep_Conter].NameD , new_dep);
        ID_Picked = List_Dep_Conter+1;
        List_Dep_Conter++;
    }
    //Affect Vale to Department struct imbriquer
    List_Student[List_Counter].Department.IdDep = ID_Picked;
    gestDepartementById(ID_Picked ,&List_Student[List_Counter].Department.NameD,
                List_Departement,len);
                
    InvalidNote:
    printf("\nEnter the student generate note :");
    scanf("%f",&List_Student[List_Counter].Note);
    if(List_Student[List_Counter].Note<0 || List_Student[List_Counter].Note>20){
        printf("require Note between 0 and 20"); 
        goto InvalidNote ;
    }
    //Increment List_Counter after adding student
    List_Counter++;

    printf("\n---------------------\n");
    printf("Added Successfully");
    printf("\n---------------------\n");
}
