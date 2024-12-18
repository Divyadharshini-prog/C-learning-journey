#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    printf("Number: ");
    scanf("%s",str);

    char result_str[2000];
    strcpy(result_str, str);
    strcat(result_str, "0");

    printf("x * 10 =%s\n", result_str);
    return 0;
}