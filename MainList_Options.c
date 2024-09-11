#include "header.h"

void MainList_Options(){
     //Option picked
    int Picked_Option ;
    //Student List
    Student List_Student[List_Length];
    //Department List
    Department List_Department[50];

    //Fill dataset
    Fill_Department(List_Department,List_Dep_Conter);

    //Fill test data 
    filldata(List_Student);
    do{
        printf("%-70s\n","_______________________________________________________________");
        printf("%-5s %-60s \n","","1. Add student");        
        printf("%-5s %-60s \n","","2. Update student");
        printf("%-5s %-60s \n","","3. Delete student");
        printf("%-5s %-60s \n","","4. View student details");
        printf("%-5s %-60s \n","","5. General average");
        printf("%-5s %-60s \n","","6. View Statistics");
        printf("%-5s %-60s \n","","7. Search on student");
        printf("%-5s %-60s \n","","8. Sort student");
        printf("%-5s %-60s \n","","9. Exit");
        printf("%-70s \n","_______________________________________________________________");
        printf("Choose : ");
        scanf("%d",&Picked_Option);
        switch (Picked_Option){
        case 1:
            Add_Student(List_Student,List_Department,sizeof(List_Department) / sizeof(List_Department[0]));
            break;
        case 2:
            Update_Student(List_Student,List_Department);
            break;
        case 3:
            int ID ;
            printf("Before going to delete student let me have the number of the student .");
            printf("Choose Id :");
            scanf("%d",&ID);
            int resultat = getStudientById(List_Student , ID);
            if(resultat==-1){
                printf("-----------------\nInvalid ID\n-----------------");
                break;
            }
            Delete_Student(List_Student ,ID);
            break;
        case 4:
            DisplayStudent(List_Student);
            break;
        case 5:
            DisplayDepartementAvg(List_Student ,List_Department,sizeof(List_Department) / sizeof(List_Department[0]));
            break;
        case 6:
            HELL:
            int Option_Statictics =0 ; 
            printf("Statistics------------------------------------------\n");
            printf("\t1.Show the total number of students enrolled.\n");
            printf("\t2.Show the number of students in each department.\n");
            printf("\t3.Entre average and get all student above it.\n");
            printf("\t4.show top 3 hight note in all university.\n");
            printf("\t5.show number of student get note hight then 10 in eatch dep.\n");
            printf("\t6.Quit Statictics.\n");
            printf("----------------------------------------------------\nChoose : ");
            scanf("%d",&Option_Statictics);
                
                if(Option_Statictics==1){
                    printf("----------------------------------------------------\n");
                    printf("total number of students enrolled : %d\n",List_Counter);
                    printf("----------------------------------------------------\n");
                    goto HELL ;
                }else if(Option_Statictics==2){
                    DisplayDepartementCount(List_Student ,List_Department,sizeof(List_Department) / sizeof(List_Department[0]));
                    goto HELL ;
                }
                else if(Option_Statictics==3){
                    float Average_Note;
                    int Count_Students = 0;
                    printf("Entre the average :");
                    scanf("%f",&Average_Note);
                    printf("\n----------------------------------------------------------------------------\n");
                    printf("%-2s %-10s %-15s %-20s %-20s %-15s %-5s\n","|","Id","First Name","Last Name","Department","Note","|") ;
                    printf("----------------------------------------------------------------------------\n");
                    for (size_t i = 0; i < List_Counter; i++)
                    {
                        if(List_Student[i].Note>Average_Note){
                            printf("%-2s %-10d %-15s %-20s %-20s %-15.2f %-2s\n","|",List_Student[i].Id,List_Student[i].Firstame,List_Student[i].LastName,List_Student[i].Department.NameD,List_Student[i].Note,"|") ;
                            printf("----------------------------------------------------------------------------\n");
                            Count_Students++;
                        }
                        
                    }
                    if(List_Counter==0)
                    {
                        printf("%-2s %-20s %-41s %-2s\n","|","","None of the student ","|") ;
                        printf("-------------------------------------------------------------------\n\n");
                    }
                    goto HELL ;
                } 
                else if(Option_Statictics==4){
                    SortAndGet_TopTree(List_Student);
                    goto HELL ;
                }  
                else if(Option_Statictics==5) {
                    printf("\nNot read yet\n");
                    goto HELL ;
                } 
                else if(Option_Statictics==6) 
                    break;
                else 
                    goto HELL ;       
                break;
        case 7:
            BACK_TO_MENU:
            int Option_Search =0 ; 
            printf("Search------------------------------------------\n");
            printf("\t1.Search for a student by name.\n");
            printf("\t2.View the list of students enrolled in a specific department.\n");
            printf("\t3.Quit Statictics.\n");
            printf("----------------------------------------------------\nChoose : ");
            scanf("%d",&Option_Search);
            if(Option_Search==1){
                char Name_Search[255] ;
                printf("Name : ");
                scanf("%s",Name_Search);
                Search_StudentByName(List_Student ,Name_Search);
                goto BACK_TO_MENU;

            }else if(Option_Search==2){
                int ID_Picked = -1;
                int len_Dep = sizeof(List_Department) / sizeof(List_Department[0]); 
                printf("\nDepartment :\n");
                for (size_t i = 0; i < List_Dep_Conter ; i++)
                {
                    printf("\t %d-%s.\n",i+1,List_Department[i].NameD);
                }
                InvalidDep:
                printf("choose : ");
                scanf("%d",&ID_Picked);
                if(ID_Picked<=0 || len_Dep<ID_Picked){
                    printf("\n---------------\n");
                    printf("\nInvalid number\n");
                    printf("\n---------------\n");
                    goto BACK_TO_MENU;
                }
                Gest_StudentByDepartement(List_Student ,ID_Picked);
                goto BACK_TO_MENU;
            }
            break;
        case 8:
            BACK_TO_MENU_Sort:
            int Option_Sort =0 ; 
            printf("Sort------------------------------------------\n");
            printf("\t1.Alphabetical sorting of students by name (A to Z). \n");
            printf("\t2.Sorting of students by general average, from highest to lowest or vice versa..\n");
            printf("\t3.Sorting of students by their success status (those with an average greater than or equal to 10/20).\n");
            printf("\t4.Quit Statictics.\n");
            printf("----------------------------------------------------\nChoose : ");
            scanf("%d",&Option_Sort);
            if(Option_Sort==1){
                SortACS(List_Student);
                goto BACK_TO_MENU_Sort;
            }else if(Option_Sort==2){
                SortACSByAvg(List_Student);
                goto BACK_TO_MENU_Sort;
            }
            else if(Option_Sort==3){
                goto BACK_TO_MENU_Sort;
            }
            else if(Option_Sort==4)
                break;
            else goto BACK_TO_MENU_Sort;
            break;
        default:
            break;
        }
    }while(Picked_Option!=9);
    printf("\n---------------\n");
    printf("Good Bye");
    printf("\n---------------\n");

}
