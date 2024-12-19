#include <stdio.h>
// #include <string.h>
int main() {
    char name[100]; 
    char dept[100]; 
    int rollno;     
    printf("Enter name: ");
    scanf("%s", &name); 
    printf("Enter department: ");
    scanf("%s", &dept); 
    printf("Enter roll number: ");
    scanf("%d", &rollno);

    printf("\"NAME \" : \"%s\"\n", name);
    printf("\"DEPT\" : \" %s\"\n", dept);
    printf("\"ROLLNO\" : \"%d\n", rollno);
    return 0;
}