#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int day;
    int month;
    int year;
}DateTime;

typedef struct{
    int Id;
    char Firstame[255];
    char LastName[255];
    DateTime date;
    char Department[255];
    float Note;
}Student;

Student List_Student[200];

//Ajouter un étudiant :
//Modifier ou supprimer un étudiant :
//Afficher les détails d'un étudiant :
//Calculer la moyenne générale :
//Statistiques :
//Rechercher un étudiant par:
//Trier un étudiant par:

int main(){
    int Picked_Option ;
    do{
        printf("%-70s\n","____________________________________________________________________");
        printf("%-5s %-60s \n","","1. Add student");        
        printf("%-5s %-60s \n","","2. Update student");
        printf("%-5s %-60s \n","","3. Delete student");
        printf("%-5s %-60s \n","","4. View student details");
        printf("%-5s %-60s \n","","5. General average");
        printf("%-5s %-60s \n","","6. Search on student");
        printf("%-5s %-60s \n","","7. Sort student");
        printf("%-5s %-60s \n","","7. Exit");
        printf("%-70s \n","____________________________________________________________________");
        printf("Choose : ");
        scanf("%d",Picked_Option);
    }while(Picked_Option!=8);
   
    

    return 0 ;
}