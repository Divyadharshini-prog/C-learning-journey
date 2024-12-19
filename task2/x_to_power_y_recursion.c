#include <stdio.h>
double power(int x, int y) {
    if (y == 0)
        return 1.0;
    else if (y > 0)
        return x * power(x, y - 1);
    else
        return 1.0 / power(x, -y);
}
int main() {
    int x, y;
    printf("Enter the base: ");
    scanf("%d", &x);
    printf("Enter the power: ");
    scanf("%d", &y);
    printf("%d^%d = %.1f\n", x, y, power(x, y));
    return 0;
}