// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000

void init(void);
void Lcd_command(unsigned char);
void Lcd_data(unsigned char);
void delay(unsigned int);
void Lcd_output(unsigned int);  // Modified to accept signed integers
unsigned char j, k[10], Equal, plus; // runtime array 
unsigned int num1, num2, sum, delaycount, m, n;

void main()
{
    init();
    num1 = 555;
    num2 = 123;
    Equal = '=';
    plus = '+';
    Lcd_command(0x80);   // select the lcd position
    Lcd_output(num1);
    Lcd_data(plus);
    Lcd_output(num2);
    Lcd_data(Equal);
    sum = num1 + num2;
    Lcd_output(sum);
    while (1);
}

void init(void)
{
    TRISC = 0X00;
    TRISD = 0X00;
    Lcd_command(0x38);
    __delay_ms(100);
    Lcd_command(0x38);
    __delay_ms(100);
    Lcd_command(0x38);
    __delay_ms(100);
    Lcd_command(0x38);
    __delay_ms(100);
    Lcd_command(0x06);
    __delay_ms(100);
    Lcd_command(0x0C);
    __delay_ms(100);
    Lcd_command(0x01);
    __delay_ms(100);
}

void Lcd_output(unsigned int i)
{
    unsigned char s, j = 1;
    m = i;
    while (m != 0)
    {
        s = m - ((m / 10) * 10);
        k[j] = s;
        j++;
        m = m / 10;
    }

    k[j] = '\0';
    j = j - 1;
    while (j != 0)
    {
        n = 0x30 + k[j];
        Lcd_data(n);
        j--;
    }
}

void Lcd_command(unsigned char i)
{
    PORTC &=~0X08;     // RS = 0
    PORTD = i;        // Data set to portD
    PORTC |= 0X01;    // EN = 1
    PORTC &=~0X01;   // EN = 0
    __delay_ms(100);
}

void Lcd_data(unsigned char i)
{
    PORTC |= 0X08;   // RS = 1
    PORTD = i;      
    PORTC |= 0X01;   // EN = 1
    PORTC &=~0X01;   // EN = 0
    __delay_ms(100);
}

void delay(unsigned int delaycount)
{
    while (--delaycount);
}
