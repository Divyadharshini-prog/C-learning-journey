#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float convertBytesToFloat(unsigned int byte1, unsigned int byte2, unsigned int byte3) 
{
    if (byte1 < 0 || byte1 > 255 || byte2 < 0 || byte2 > 255 || byte3 < 0 || byte3 > 255) 
    {
        return 0; 
    }
    
    //char str[10] = "";
    char temp[10];
    
    snprintf(temp, sizeof(temp), "%u%u", byte1,byte2);
    
    int concatenatedValue = atoi(temp);

    int divisor;
    if (byte3 <= 9) {
        divisor = 10;
    }
    else if (byte3 <= 99) {
        divisor = 100;
    }
    else {
        divisor = 1000;
    }
    
    return concatenatedValue +(float)byte3 / divisor;
}//2380 + 255 / 1000 = 2380.255

int main() {
    unsigned int byte1 = 240, byte2 = 56, byte3 = 19;
    float result = convertBytesToFloat(byte1, byte2, byte3);
    printf("Converted value: %.3f\n", result);
    return 0;
}
