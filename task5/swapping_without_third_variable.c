#include<stdio.h>
int main()
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1,&num2);
    printf("Before swapping: a=%d , b=%d\n", num1,num2);
    //swapping without using a third variable
    num1 =num1+num2;
    num2 =num1-num2;
    num1 =num1-num2;
    //Print swapped numbers
    printf("After swapping: a=%d , b=%d\n",num1,num2);
    return 0;
}