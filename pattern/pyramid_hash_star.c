#include <stdio.h>

int main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);

    for (int i = 1; i<=num; i++) 
    {
        for (int j=1; j<i; j++){
            printf("# ");
        }
        printf("*\n");
    }
    
    return 0;
}


/* Sample output:

enter the number:7
*  
# *
# # *
# # # *
# # # # *
# # # # # *
# # # # # # *
The above code has the pattern of hash and at the end of the row it has star.
*/
