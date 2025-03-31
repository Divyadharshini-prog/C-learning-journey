#include <stdio.h>
int main()
{
    int option = 0;
    while (1)
    {
        printf("=-=-=-=-=-=-=-=-= MAIN MENU =-=-=-=-=-=-=-=-=-=\n");
        printf("1  :  Create a list\n");
        printf("2  :  Display the list\n");
        printf("3  :  Add a node at the beginning\n");
        printf("4  :  Add a node at the end\n");
        printf("5  :  Add a node before a given node\n");
        printf("6  :  Add a node after a given node\n");
        printf("7  :  Delete a node from the beginning\n");
        printf("8  :  Delete a node from the end\n");
        printf("9  :  Delete a given node\n");
        printf("10 :  Delete a node after a given node\n");
        printf("11 :  Delete the entire list\n");
        printf("12 :  Sort the list\n");
        printf("13 :  EXIT\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        printf("Enter your option: ");
        if (scanf("%d", &option) != 1)
        {
            printf("\nInvalid input. Please enter a number between 1 and 13.\n\n");
        }
        if (option < 1 || option > 13)
        {
            printf("\nInvalid number... Please enter a number between 1 and 13.\n\n");
            //continue; 
        }
        if (option == 13)
        {
            break;
        }
    }
    return 0;
}
