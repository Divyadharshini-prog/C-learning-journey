#include <stdio.h>
#include <math.h>
int main() {
    float num;
    printf("Enter a number : ",num);
    scanf("%f",&num);
    printf("%f", round(num));
    //float rounded = (float)((int)(num * 10 + 0.5)) / 10; // Manual rounding
    //printf("%.1f\n", rounded); 
    return 0;
}

