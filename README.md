
## Project SAS

Introduction :
L'application a pour objectif de gérer les étudiants inscrits dans une université en fournissant des fonctionnalités telles que l'ajout, la modification, et la suppression d'étudiants, ainsi que le suivi de leur progression académique. Elle permettra également de consulter les résultats des étudiants et de générer des statistiques académiques.

Contexte du projet :
L’application comporte un menu principal qui permet de :


## Contexte du projet :

L’application comporte un menu principal qui permet de :

- Ajouter un étudiant ✅
    -
    Add_Student(Student List_Student[],Department List_Departement[],int len)
    check_Day_Validation(int day)
    check_Month_Validation(int month)
    ccheck_Year_Validation(int year)
    gestDepartementById(int Id , char* Dep,Department List_Departement[],int len)

- Modifier ou supprimer un étudiant ⭕
    -
    not yet
- Afficher les détails d'un étudiant ✅
    -
    DisplayStudent(Student List_Student[])
- Calculer la moyenne générale ✅
    -
    DisplayDepartementAvg(Student List_Student[],Department List_Departement[],int len)
    GetDepartementAvg(Student List_Student[],char name[])
- Statistiques ✅
    -
    include on main
- Rechercher un étudiant ✅
    -
    Search_StudentByName(Student List_Student[],char name_Student[])
    Gest_StudentByDepartement(Student List_Student[],int Id_Dep[])
- Trier un étudiant ⭕
    -
    not yet
