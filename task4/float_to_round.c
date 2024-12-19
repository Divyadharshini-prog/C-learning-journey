#include <stdio.h>

int main() {
    float num;
    printf("Enter a number : ",num);
    scanf("%f",&num);
    float rounded = (float)((int)(num * 10 + 0.5)) / 10; // Manual rounding
    printf("%.1f\n", rounded); // Outputs 67.1
    return 0;
}
