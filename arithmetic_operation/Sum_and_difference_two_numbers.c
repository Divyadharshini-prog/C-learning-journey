#include <stdio.h>
#include <string.h>

int main()
{
    int num1,num2,sum,sub;
    float n1,n2,plus,minus;
    printf("");
    scanf("%d %d", &num1, &num2);
    printf("");
    scanf("%f %f", &n1 ,&n2);
    sum = num1 +num2 ;
    sub = num1 - num2;
    plus = n1 + n2;
    minus = n1 - n2;
    printf("%d %d",sum,sub);
	printf("\n%.1f %.1f",plus,minus);
    
    return 0;
}
