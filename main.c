#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
int List_Dep_Conter = 12;

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
    {
        printf("\t( Invalid Year format *) \n");
        goto InvalidYear;
    }
        

    //Month validation
    InvalidMonth:
    printf("\tMonth : ");
    scanf("%d",&List_Student[List_Counter].date.month);
    if(check_Month_Validation(List_Student[List_Counter].date.month)==0)
    {
        printf("\t( Invalid month format *) \n");
        goto InvalidMonth;
    }

    //Day validation
    InvalidDay:
    printf("\tDay : ");
    scanf("%d",&List_Student[List_Counter].date.day);
    if(check_Day_Validation(List_Student[List_Counter].date.day)==0)
     {
        printf("\t( Invalid day format *)\n");
        goto InvalidDay;
    }  
    
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

        InvalidYear:
        printf("\tYear : ");
        scanf("%d",&List_Student[resultat].date.year);
        if(check_Year_Validation(List_Student[resultat].date.year)==0)
          {
                printf("\t( Invalid year format *) \n");
                goto InvalidYear;
          }
        InvalidMonth:
        printf("\tMonth : ");
        scanf("%d",&List_Student[resultat].date.month);
        if(check_Month_Validation(List_Student[resultat].date.month)==0)
        {
            printf("\t( Invalid month format *) \n");
            goto InvalidMonth;
        }
        InvalidDay:
        printf("\tDay : ");
        scanf("%d",&List_Student[resultat].date.day);
        if(check_Day_Validation(List_Student[resultat].date.day)==0)
        {
            printf("\t( Invalid day format *)\n");
            goto InvalidDay;
        }  
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
        InvalidNote:
        printf("\nnew note : ");
        scanf("%f",&List_Student[resultat].Note);
        if(List_Student[resultat].Note<0 || List_Student[resultat].Note>20){
            printf("require Note between 0 and 20"); 
            goto InvalidNote;
        }
        goto Menu_Update_AfterCheck;  
    }
    else if(OptionMenu_Selected==6){}
    else 
        goto Menu_Update_AfterCheck; 
}

//Search By ID student and return id if not return -1
int getStudientById(Student List_Student[] ,int Student_id){
    for (size_t i = 0; i < List_Counter; i++)
    {
        if(List_Student[i].Id == Student_id)
            return i;
    }
    return -1;
}

//Delele student 
void Delete_Student(Student List_Student[], int ID){
    for (size_t i = 0; i < List_Counter; i++)
    {
         if(List_Student[i].Id == ID){
            for (size_t d = i; d < List_Counter-1; d++)
            {
                List_Student[d] = List_Student[d+1];
            } 
            List_Counter--;
            break;   
        } 
    }
    printf("\n---------------------\n");
    printf("Deleted Successfully");
    printf("\n---------------------\n");
}

//using pointer i take the dep with postion and fill it  
void gestDepartementById(int Id , char* Dep,Department List_Departement[],int len){
    for (size_t i = 0; i < List_Dep_Conter; i++)
    {
        if(List_Departement[i].IdDep == Id){
            strcpy(Dep ,List_Departement[i].NameD);
        }
     }
}

//Display all student
void DisplayStudent(Student List_Student[]){
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n","|","Id","Date","Last Name","First Name","Department","Note","|") ;
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < List_Counter; i++)
    {
        printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
        "|",List_Student[i].Id,
        List_Student[i].date.year ,List_Student[i].date.month , List_Student[i].date.day,
        "",List_Student[i].LastName,List_Student[i].Firstame,List_Student[i].Department.NameD,List_Student[i].Note,"|") ;
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
    if(List_Counter==0)
    {
        printf("%-2s %-20s %-41s %-2s\n","|","","Empty List","|") ;
        printf("--------------------------------------------------------------------------------------------\n\n");
    }
}

//Display avrage for a single Departement and return avg 
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

//Display numbrer count student for eatch Departement and return number 
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

//Display average student for eatch Departement
void DisplayDepartementAvg(Student List_Student[],Department List_Departement[],int len){
    //Display Table Departement Avg
    int Total_Abg = 0;
    float Note = 0.0;
    printf("\n---------------------------------\n");
    printf("%-2s %-15s %-20s %-2s\n","|","Departement","Avg","|") ;
    printf("---------------------------------\n");  
    for (size_t i = 0; i < List_Dep_Conter; i++)
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

//Display data number for eatch Departement
void DisplayDepartementCount(Student List_Student[],Department List_Departement[],int len){
    //Display Table Departement Avg
    printf("\n---------------------------------\n");
    printf("%-2s %-15s %-10s %-2s\n","|","Departement","Number","|") ;
    printf("---------------------------------\n");  
    for (size_t i = 0; i < List_Dep_Conter; i++)
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

//Fill Departement Name on list
void Fill_Department(Department List_Department[] , int List_Dep_Conter) {
    // Fill Data
    char dep[12][255] = {"Biologie", "Mathematiques", "Informatique", "Chimie", "Physique", "Histoire", "Philosophie", "Litterature", "Gestion", "Economie", "Droit", "Geographie"};
    for (size_t i = 0; i < List_Dep_Conter; i++)
    {
        List_Department[i].IdDep = i+1;
        strcpy(List_Department[i].NameD, dep[i]);
    }
}

//Display student data search by name
void Search_StudentByName(Student List_Student[],char name_Student[]){
   int index_ = -1 ;
    for (int i = 0; i < List_Counter; i++)
    {
        if(strcasecmp(List_Student[i].LastName , name_Student)==0){
            index_ = i;
            break;
        }
            
   }
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

//Display student data search by departement id
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

//Fill a test data for students
void filldata(Student List_Student[]){
   List_Student[0].Id = 1;
   strcpy(List_Student[0].Firstame , "mohamed"); 
   strcpy(List_Student[0].LastName , "ddd");  
   List_Student[0].Note = 15.6 ;
   List_Student[0].Department.IdDep = 1;
   List_Student[0].date.day=5;List_Student[0].date.month=11;List_Student[0].date.year=2008;
   strcpy(List_Student[0].Department.NameD , "Biologie");   

   List_Student[1].Id = 2;
   strcpy(List_Student[1].Firstame , "hamza"); 
   strcpy(List_Student[1].LastName , "bbb");  
   List_Student[1].Note = 11.1 ;
   List_Student[1].Department.IdDep = 3;
   List_Student[1].date.day=19;List_Student[1].date.month=9;List_Student[1].date.year=2012;
   strcpy(List_Student[1].Department.NameD , "Informatique");  

   List_Student[2].Id = 3;
   strcpy(List_Student[2].Firstame , "ayman"); 
   strcpy(List_Student[2].LastName , "motawali");  
   List_Student[2].Note = 17.4 ;
   List_Student[2].Department.IdDep = 3;
   List_Student[2].date.day=4;List_Student[2].date.month=10;List_Student[2].date.year=2001;
   strcpy(List_Student[2].Department.NameD , "Informatique");  

   List_Student[3].Id = 4;
   strcpy(List_Student[3].Firstame , "zakaria"); 
   strcpy(List_Student[3].LastName , "ccc");  
   List_Student[3].Note = 18.5 ;
   List_Student[3].Department.IdDep = 4;
   List_Student[3].date.day=4;List_Student[3].date.month=10;List_Student[3].date.year=2001;
   strcpy(List_Student[3].Department.NameD , "Chimie"); 

   List_Student[4].Id = 5;
   strcpy(List_Student[4].Firstame , "sara"); 
   strcpy(List_Student[4].LastName , "motawali");  
   List_Student[4].Note = 10.6 ;
   List_Student[4].Department.IdDep = 5;
   List_Student[4].date.day=4;List_Student[4].date.month=10;List_Student[4].date.year=2001;
   strcpy(List_Student[4].Department.NameD , "Physique"); 

    List_Student[5].Id = 6;
   strcpy(List_Student[5].Firstame , "rayan"); 
   strcpy(List_Student[5].LastName , "motawali");  
   List_Student[5].Note = 13.75 ;
   List_Student[5].Department.IdDep = 5;
   List_Student[5].date.day=4;List_Student[5].date.month=10;List_Student[5].date.year=2001;
   strcpy(List_Student[5].Department.NameD , "Physique"); 

   Id_Counter = 7;
   List_Counter = 6; 
}

//Make char lower case
int ToLowerCase(char First_C){
    if(First_C>=65 && First_C<=90)
        return (int)First_C + 32 ;
    else    
        return (int)First_C;
}

//compare between tw string char by char using pointure in case two  char assame 
//i increase the adress pointure to new char and i can acees to the new char 
//in heap the arry string are the odeer one after one
int CustumsStrcaseComp(char* fisrtChar, char* secondChar) {
    while (1) {
        if (ToLowerCase(*fisrtChar) != ToLowerCase(*secondChar)) {
            return ToLowerCase(*fisrtChar) - ToLowerCase(*secondChar);
        }
        fisrtChar++;
        secondChar++;
    }
    return ToLowerCase(*fisrtChar) - ToLowerCase(*secondChar);
}

//Sort Student 
void SortACS(Student List_Student[]) {
    for (size_t i = 0; i < List_Counter - 1; i++) {
        for (size_t p = 0; p < List_Counter - i - 1; p++) {
            if (CustumsStrcaseComp(List_Student[p].LastName , List_Student[p+1].LastName) > 0) {
                Student temp = List_Student[p];
                List_Student[p] = List_Student[p + 1];
                List_Student[p + 1] = temp;
            }
            /*if (ToLowerCase(List_Student[p].LastName[0]) > ToLowerCase(List_Student[p + 1].LastName[0])) {
                Student temp = List_Student[p];
                List_Student[p] = List_Student[p + 1];
                List_Student[p + 1] = temp;
            }*/
            
        }
    }

    // sorted list A Z
    printf("\n-----Sort Filter by ( A , Z )-----\n");
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n", "|", "Id", "Date", "First Name", "Last Name", "Department", "Note", "|");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (size_t i = 0; i < List_Counter; i++) {
        printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
               "|", List_Student[i].Id,
               List_Student[i].date.year, List_Student[i].date.month, List_Student[i].date.day,
               "", List_Student[i].Firstame, List_Student[i].LastName, List_Student[i].Department.NameD, List_Student[i].Note, "|");
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
}

//Sort Student NOTE highest to lowest
void SortACSByAvg(Student List_Student[]) {
    for (size_t i = 0; i < List_Counter - 1; i++) {
        for (size_t p = i; p < List_Counter - 1; p++) {
            if (List_Student[i].Note < List_Student[p+1].Note) {
                //swap
                Student small_Note = List_Student[i];
                List_Student[i] = List_Student[p + 1];
                List_Student[p + 1] = small_Note;
            }
        }
    }

    // sorted list A Z
    printf("\n-----Sort Filter from highest to lowest -----\n");
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n", "|", "Id", "Date", "First Name", "Last Name", "Department", "Note", "|");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (size_t i = 0; i < List_Counter; i++) {
        printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
               "|", List_Student[i].Id,
               List_Student[i].date.year, List_Student[i].date.month, List_Student[i].date.day,
               "", List_Student[i].Firstame, List_Student[i].LastName, List_Student[i].Department.NameD, List_Student[i].Note, "|");
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
}

//Sort Student in same time get the top tree 
void SortAndGet_TopTree(Student List_Student[]) {
    printf("\n-----Sort Filter for top 3 -----\n");
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("%-2s %10s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n", "|","Rank", "Id", "Date", "First Name", "Last Name", "Department", "Note", "|");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    int Top_First_Value = 0;
    for (size_t i = 0; i < List_Counter - 1; i++) {
        for (size_t p = i; p < List_Counter - 1; p++) {
            if (List_Student[i].Note < List_Student[p+1].Note) {
                //swap
                Student small_Note = List_Student[i];
                List_Student[i] = List_Student[p + 1];
                List_Student[p + 1] = small_Note;
            }
        }
        if(Top_First_Value<3){
            char Rank[25] ;
            if(Top_First_Value ==0)  strcpy(Rank , "🥇" );
            else if(Top_First_Value ==1) strcpy(Rank , "🥈" );
            else if(Top_First_Value ==2) strcpy(Rank , "🥉" );
                 printf("%-2s %10s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
               "|", Rank, List_Student[Top_First_Value].Id,
               List_Student[Top_First_Value].date.year, List_Student[Top_First_Value].date.month, List_Student[Top_First_Value].date.day,
               "", List_Student[Top_First_Value].Firstame, List_Student[Top_First_Value].LastName, List_Student[Top_First_Value].Department.NameD, List_Student[Top_First_Value].Note, "|");
            printf("---------------------------------------------------------------------------------------------------------------\n");
        }else break;
        Top_First_Value++;
    }
}

//Sort with note highest then 10 
void SortValidStudents(Student List_Student[]) {
    printf("\n-----Sort Filter for top 3 -----\n");
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("%-2s %-10s %-14s %-15s %-20s %-20s %-15s %-5s\n", "|", "Id", "Date", "First Name", "Last Name", "Department", "Note", "|");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    int Count_studantFailed = 0;
    for (size_t i = 0; i < List_Counter ; i++) {
        for (size_t p = i; p < List_Counter; p++) {
            if (List_Student[i].Note < List_Student[p+1].Note) {
               
                //swap
                Student small_Note = List_Student[i];
                List_Student[i] = List_Student[p + 1];
                List_Student[p + 1] = small_Note;
                
            }
        }
        if(List_Student[i].Note < 10){
            Count_studantFailed++;
        }
            
    }
    for (size_t i = 0; i < List_Counter -Count_studantFailed ; i++)
    {
         printf("%-2s %-10d %d/%d/%d %-5s %-15s %-20s %-20s %-15.2f %-2s\n",
               "|", List_Student[i].Id,
               List_Student[i].date.year, List_Student[i].date.month, List_Student[i].date.day,
               "", List_Student[i].Firstame, List_Student[i].LastName, List_Student[i].Department.NameD, List_Student[i].Note, "|");
            printf("---------------------------------------------------------------------------------------------------------------\n");
        
    }
    
}

//display eatch departement with number of note bigger then 10
void DisplayDepartementByAvgHight(Student List_Student[],Department List_Departement[]){
    printf("\n---------------------------------\n");
    printf("%-2s %-15s %-10s %-2s\n","|","Departement","Number > 10","|") ;
    printf("---------------------------------\n");  
    int Count_OnDep = 0 ;
    for (size_t i = 0; i < List_Dep_Conter; i++)
    {       Count_OnDep = 0;
            float avg = 0;
            for (size_t r = 0;  r < List_Counter;  r++)
            {
                if(List_Student[r].Department.IdDep == List_Departement[i].IdDep
                    && List_Student[r].Note > 10)
                    Count_OnDep++;
            }
            printf("%-2s %-15s %10d %-2s\n","|",
                        List_Departement[i].NameD,
                        Count_OnDep,
                        "|") ;
                printf("---------------------------------\n");
            
    }
}

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
            printf("Before going to delete student let me have the number of the student .\n");
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
                    DisplayDepartementByAvgHight(List_Student , List_Department);
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
                //int len_Dep = sizeof(List_Department) / sizeof(List_Department[0]); 
                printf("\nDepartment :\n");
                for (size_t i = 0; i < List_Dep_Conter ; i++)
                {
                    printf("\t %d-%s.\n",i+1,List_Department[i].NameD);
                }
                InvalidDep:
                printf("choose : ");
                scanf("%d",&ID_Picked);
                if(ID_Picked<=0 || List_Dep_Conter<ID_Picked){
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
                SortValidStudents(List_Student);
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


//Main function
int main(){
    
    MainList_Options();
    
    return 0 ;
}