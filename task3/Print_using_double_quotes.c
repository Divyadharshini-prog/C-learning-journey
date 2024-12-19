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

    printf("\"NAME \" : \"%s\"\n", name);   // to print the output with double quotes use \" name \"
    printf("\"DEPT\" : \" %s\"\n", dept);
    printf("\"ROLLNO\" : \"%d\"n", rollno);
    return 0;
}


/* To run this code use cmd: gcc Print_using_double_quotes.c -o Print_using_double_quotes.exe
cmd : gcc Print_using_double_quotes.c -o Print_using_double_quotes.exe
cmd : .\Print_using_double_quotes.exe 
*/
/* sample Input:
Enter name: Divya
Enter department: ECE
Enter roll number: 2021007
Output:
"NAME " : "Divya"
"DEPT" : " ECE"
"ROLLNO" : "2021007"
*/
