#include "header.h"

void Delete_Student(Student List_Student[], int ID){
    for (int i = 0; i < List_Counter; i++)
    {
         if(List_Student[i].Id == ID){
            for (int d = i; d < List_Counter-1; d++)
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
