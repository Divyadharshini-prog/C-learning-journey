#include <stdio.h>
#include "sum.h" // Include the header file

int main() {
    int num1, num2, result;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Call the sum function
    result = sum(num1, num2);

    // Print the result
    printf("Sum of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
