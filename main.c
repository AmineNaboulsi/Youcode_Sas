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

void Add_Student(Student List_Student[],Department List_Departement[],int len){
    
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
    for (size_t i = 0; i < len; i++)
    {
        printf("\t %d-%s.\n",i+1,List_Departement[i].NameD);
    }
    InvalidDep:
    printf("choose : ");
    scanf("%d",&ID_Picked);
    if(ID_Picked<=0 || len<ID_Picked)
        goto InvalidDep;
    //Affect Vale to Department struct imbriquer
    List_Student[List_Counter].Department.IdDep = ID_Picked;
    gestDepartementById(ID_Picked ,&List_Student[List_Counter].Department.NameD,
                List_Departement,len);
                

    printf("\nEnter the student generate note :");
    scanf("%f",&List_Student[List_Counter].Note);

    //Increment List_Counter after adding student
    List_Counter++;
}

void gestDepartementById(int Id , char* Dep,Department List_Departement[],int len){
    for (size_t i = 0; i < len; i++)
    {
        if(List_Departement[i].IdDep == Id){
            strcpy(Dep ,List_Departement[i].NameD);
        }
     }
}
void DisplayStudent(Student List_Student[]){
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n","|","Id","Date","First Name","Last Name","Department","Note","|") ;
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < List_Counter; i++)
    {
        printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
        "|",List_Student[i].Id,
        List_Student[i].date.year ,List_Student[i].date.month , List_Student[i].date.day,
        "",List_Student[i].Firstame,List_Student[i].LastName,List_Student[i].Department.NameD,List_Student[i].Note,"|") ;
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
    if(List_Counter==0)
    {
        printf("%-2s %-20s %-41s %-2s\n","|","","Empty List","|") ;
        printf("--------------------------------------------------------------------------------------------\n\n");
    }
}


float GetDepartementAvg(Student List_Student[],char name[]){
    int Count_Student = 0;
    float Avg = 0;
     for (int ji = 0; ji < List_Counter; ji++)
        {
             if(strcasecmp(List_Student[ji].Department.NameD , name)==0){
                  Count_Student++;
                  Avg+=List_Student[ji].Note;
              }
        }
   if(Count_Student == 0)
      return 0.0 ;
   else 
      return Avg/=Count_Student;
}
int GetDepartementCount(Student List_Student[],char name[]){
    int Count_Student = 0;
     for (int ji = 0; ji < List_Counter; ji++)
        {
             if(strcasecmp(List_Student[ji].Department.NameD , name)==0){
                  Count_Student++;
              }
        }
      return Count_Student;
}

void DisplayDepartementAvg(Student List_Student[],Department List_Departement[],int len){
    //Display Table Departement Avg
    int Total_Abg = 0;
    float Note = 0.0;
    printf("\n---------------------------------\n");
    printf("%-2s %-15s %-20s %-2s\n","|","Departement","Avg","|") ;
    printf("---------------------------------\n");  
    for (size_t i = 0; i < len; i++)
    {
            float avg = GetDepartementAvg(List_Student , List_Departement[i].NameD);
             
            printf("%-2s %-15s %.2f %-2s\n","|",
                        List_Departement[i].NameD,
                        avg,
                        "|") ;
            
            if(avg>0){
                Note+=avg;
                Total_Abg++;
            } 
            printf("---------------------------------\n");
            /*printf("id :%d var :%s note : %f",List_Student[i].Department.IdDep,List_Student[i].Department.NameD,List_Student[i].Note );
            printf("---------------------------------\n");*/
    }
    printf("%-2s %-15s %.2f %-2s\n","|","All",Note/Total_Abg,"|") ;
    printf("---------------------------------\n");
            
}
void DisplayDepartementCount(Student List_Student[],Department List_Departement[],int len){
    //Display Table Departement Avg
    printf("\n---------------------------------\n");
    printf("%-2s %-15s %-10s %-2s\n","|","Departement","Number","|") ;
    printf("---------------------------------\n");  
    for (size_t i = 0; i < len; i++)
    {
            float avg = 0;
            printf("%-2s %-15s %10d %-2s\n","|",
                        List_Departement[i].NameD,
                        GetDepartementCount(List_Student , List_Departement[i].NameD),
                        "|") ;
            printf("---------------------------------\n");
            /*printf("id :%d var :%s note : %f",List_Student[i].Department.IdDep,List_Student[i].Department.NameD,List_Student[i].Note );
            printf("---------------------------------\n");*/
    }
}

void Fill_Department(Department List_Department[]) {
    // Fill Data
    char dep[12][255] = {"Biologie", "Mathematiques", "Informatique", "Chimie", "Physique", "Histoire", "Philosophie", "Litterature", "Gestion", "Economie", "Droit", "Geographie"};
    for (size_t i = 0; i < 12; i++)
    {
        List_Department[i].IdDep = i+1;
        strcpy(List_Department[i].NameD, dep[i]);
    }
}

void Search_StudentByName(Student List_Student[],char name_Student[]){
   int index_ = -1 ;
    for (int i = 0; i < List_Counter; i++)
    {
        if(strcasecmp(List_Student[i].LastName , name_Student)==0)
            index_ = i;
   }
    printf("list : %d\n",index_);
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n","|","Id","Date","First Name","Last Name","Department","Note","|") ;
    printf("-----------------------------------------------------------------------------------------------------\n");
    if(index_ == -1)
    {
        printf("%-2s %-20s %-41s %-2s\n","|","","Student Not found","|") ;
        printf("--------------------------------------------------------------------------------------------\n\n");
    }
    else {
              printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
        "|",List_Student[index_].Id,
        List_Student[index_].date.year ,List_Student[index_].date.month , List_Student[index_].date.day,
        "",List_Student[index_].Firstame,List_Student[index_].LastName,List_Student[index_].Department.NameD,List_Student[index_].Note,"|") ;
        printf("-----------------------------------------------------------------------------------------------------\n");
    
    }
}

void Gest_StudentByDepartement(Student List_Student[],int Id_Dep[]){
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n","|","Id","Date","First Name","Last Name","Department","Note","|") ;
    printf("-----------------------------------------------------------------------------------------------------\n");
    int find_ = -1 ;
    for (int index_ = 0; index_ < List_Counter; index_++)
    {
        if(List_Student[index_].Department.IdDep == Id_Dep)
        {
                 printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
                "|",List_Student[index_].Id,
                List_Student[index_].date.year ,List_Student[index_].date.month , List_Student[index_].date.day,
                "",List_Student[index_].Firstame,List_Student[index_].LastName,List_Student[index_].Department.NameD,List_Student[index_].Note,"|") ;
                printf("-----------------------------------------------------------------------------------------------------\n");
            find_ = 1;
        }
   }
    if(find_ != 1)
    {
        printf("%-2s %-20s %-41s %-2s\n","|","","Student Not found","|") ;
        printf("--------------------------------------------------------------------------------------------\n\n");
    }
   
}

void filldata(Student List_Student[]){
   List_Student[0].Id = 1;
   strcpy(List_Student[0].Firstame , "amine"); 
   strcpy(List_Student[0].LastName , "aaa");  
   List_Student[0].Note = 15.6 ;
   List_Student[0].Department.IdDep = 0;
   List_Student[0].date.day=5;List_Student[0].date.month=11;List_Student[0].date.year=2008;
   strcpy(List_Student[0].Department.NameD , "Biologie");   

   List_Student[1].Id = 2;
   strcpy(List_Student[1].Firstame , "mohamed"); 
   strcpy(List_Student[1].LastName , "yyyy");  
   List_Student[1].Note = 11.1 ;
   List_Student[1].Department.IdDep = 1;
   List_Student[1].date.day=19;List_Student[1].date.month=9;List_Student[1].date.year=2012;
   strcpy(List_Student[1].Department.NameD , "Informatique");  

   List_Student[2].Id = 3;
   strcpy(List_Student[2].Firstame , "ayman"); 
   strcpy(List_Student[2].LastName , "yyyy");  
   List_Student[2].Note = 17.4 ;
   List_Student[2].Department.IdDep = 1;
   List_Student[2].date.day=4;List_Student[2].date.month=10;List_Student[2].date.year=2001;
   strcpy(List_Student[2].Department.NameD , "Informatique");  

   List_Student[3].Id = 4;
   strcpy(List_Student[3].Firstame , "3isa"); 
   strcpy(List_Student[3].LastName , "motawali");  
   List_Student[3].Note = 18.5 ;
   List_Student[3].Department.IdDep = 3;
   List_Student[3].date.day=4;List_Student[3].date.month=10;List_Student[3].date.year=2001;
   strcpy(List_Student[3].Department.NameD , "Chimie"); 

   List_Student[4].Id = 5;
   strcpy(List_Student[4].Firstame , "sara"); 
   strcpy(List_Student[4].LastName , "motawali");  
   List_Student[4].Note = 10.6 ;
   List_Student[4].Department.IdDep = 4;
   List_Student[4].date.day=4;List_Student[4].date.month=10;List_Student[4].date.year=2001;
   strcpy(List_Student[4].Department.NameD , "Physique"); 

   List_Counter = 5; 
}
int main(){
    //Option picked
    int Picked_Option ;
    //Student List
    Student List_Student[List_Length];
    //Department List
    Department List_Department[12];
    //Fill dataset
    Fill_Department(List_Department);

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
            printf("\nNot read yet\n");
            break;
        case 3:
            printf("\nNot read yet\n");
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
            printf("\t4.Quit Statictics.\n");
            printf("----------------------------------------------------\nChoose : ");
            scanf("%d",&Option_Statictics);
                
                if(Option_Statictics==1){
                    printf("----------------------------------------------------\n");
                    printf("total number of students enrolled %d\n",List_Counter);
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
                else if(Option_Statictics==4) 
                    break;
                else 
                    goto HELL ;       
                break;
        case 7:
            BACK_TO_MENU:
            int Option_Search =0 ; 
            printf("Search------------------------------------------\n");
            printf("\t1.Search for a student by name..\n");
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
                for (size_t i = 0; i < len_Dep ; i++)
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
            printf("\nNot read yet\n");
            break;
        default:
            break;
        }
    }while(Picked_Option!=9);
    printf("\n---------------\n");
    printf("Good Bye");
    printf("\n---------------\n");

    return 0 ;
}