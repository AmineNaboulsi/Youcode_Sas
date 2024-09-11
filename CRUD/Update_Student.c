#include "header.h"

//Update student
void Update_Student(Student List_Student[],Department List_Departement[]){
    int OptionMenu_Selected = 0;
    int Student_id = 0;
    Menu_Update:
    printf("Before going to update let me have the number of the student .\n");
    printf("Choose :");
    scanf("%d",&Student_id);
    int resultat = getStudientById(List_Student ,Student_id);
    if(resultat == -1){
        printf("---------------------\nIncorrect ID\n---------------------");
        goto Menu_Update;
    }
    Menu_Update_AfterCheck:
    printf("Witch element u want to update\n");
    printf("\t1.Fist Name.\n");
    printf("\t2.Last Name.\n");
    printf("\t3.Birthay date.\n");
    printf("\t4.Departement.\n");
    printf("\t5.Note.\n");
    printf("\t6.Quit.\n");
    printf("Choose :");
    scanf("%d",&OptionMenu_Selected);
    if(OptionMenu_Selected==1){
        printf("Entre new fist name : ");
        scanf("%s",List_Student[resultat].Firstame);
        goto Menu_Update_AfterCheck;
    }else if(OptionMenu_Selected==2){
        printf("Entre new last name : ");
        scanf("%s",List_Student[resultat].LastName);
        goto Menu_Update_AfterCheck;
    }else if(OptionMenu_Selected==3){
        printf("\tYear : ");
        scanf("%d",&List_Student[resultat].date.year);
        printf("\tMonth : ");
        scanf("%d",&List_Student[resultat].date.year);
        printf("\tDay : ");
        scanf("%d",&List_Student[resultat].date.year);
        goto Menu_Update_AfterCheck;
    }
    else if(OptionMenu_Selected==4){
        int ID_Picked = -1;
        printf("\nDepartment :\n");
        for (int i = 0; i < List_Dep_Conter; i++)
        {
            printf("\t %d-%s.\n",List_Departement[i].IdDep,List_Departement[i].NameD);
        }
        InvalidDep:
        printf("choose new departelent : ");
        scanf("%d",&ID_Picked);
        if(ID_Picked<=0 || List_Dep_Conter<ID_Picked)
            goto InvalidDep;
        List_Student[resultat].Department.IdDep = ID_Picked;
        gestDepartementById(ID_Picked ,&List_Student[resultat].Department.NameD,
                List_Departement,List_Dep_Conter);
        goto Menu_Update_AfterCheck;        
    }
    else if(OptionMenu_Selected==5){
        printf("\nnew note : ");
        scanf("%f",&List_Student[resultat].Note);
        goto Menu_Update_AfterCheck;  
    }
    else if(OptionMenu_Selected==6){}
    else 
        goto Menu_Update_AfterCheck; 
}
