/*
 * File:   class4_class1pgm.c
 * Author: D E L L
 *
 * Created on July 20, 2024, 12:13 AM
 */

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000

void Lcd_command(unsigned char);
void Lcd_data(unsigned char);
void delay(unsigned int);
void Lcd_output(unsigned int);
void keyscan();
void init();
unsigned char array[30] = {"SET SPD:    rpm"};
unsigned char x, m, n, value;
unsigned int d4, d3, d2, d1, j, i;

void main() 
{
    init();
    while (1) 
    {
        keyscan();
    }
}

void init()
{
    TRISC = 0x00;  // Configure Port C as output for LCD control
    TRISB = 0xF0;  // RB7 to RB4 input (switches), RB3 to RB0 output (control)
    TRISD = 0x00;  // Port D as output for LCD data
    PORTB = 0x00;  // Clear PORTB
    OPTION_REG &= 0x7F;  // Pull-ups enabled

    // Initialize the LCD
    Lcd_command(0x38);  // Function set: 8-bit/2-line
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
    j=0;
}

void keyscan() 
{
    value = PORTB & 0xF0;  // Read the higher nibble for the key press

    switch (value)
    {
        case 0xE0:  // Display the text and speed
            Lcd_command(0x80);  // First LCD position
            for (x = 0; x < 8; x++) 
            {
                Lcd_data(array[x]);
            }
            Lcd_command(0x8C);
            for (x = 12; x < 15; x++)
            {
                Lcd_data(array[x]);
            }
            Lcd_command(0x88);
            Lcd_output(j);
            break;

        case 0xD0:  // Increment the numbers
            j++;
            if (j > 5000) 
            {
                j = 5000;
            }
            Lcd_command(0x88);
            Lcd_output(j);
            break;

        case 0xB0:  // Decrement the numbers
            j--;
            if (j < 1) 
            {
                j = 1;
            }
            Lcd_command(0x88);
            Lcd_output(j);
            break;

        case 0x70:  // Reset
            j = 0;
            Lcd_command(0x88);
            Lcd_output(j);
            break;
    }
}

void Lcd_command(unsigned char i)
{
    PORTC &= ~0x08;  // RS = 0 for command
    PORTD = i;       // Put the command on PORTD
    PORTC |= 0x01;   // EN = 1 to latch data
    PORTC &= ~0x01;  // EN = 0
    __delay_ms(100);   // Allow time for the command to execute
}

void Lcd_data(unsigned char i) {
    PORTC |= 0x08;   // RS = 1 for data
    PORTD = i;       // Put the data on PORTD
    PORTC |= 0x01;   // EN = 1 to latch data
    PORTC &= ~0x01;  // EN = 0
    __delay_ms(100);   // Allow time for the data to be written
}

void Lcd_output(unsigned int i) {
    d4 = (unsigned char) (i / 1000);
    d3 = (unsigned char) ((i - (d4 * 1000)) / 100);
    d2 = (unsigned char) ((i - (d4 * 1000) - (d3 * 100)) / 10);
    d1 = (unsigned char) (i - (d4 * 1000) - (d3 * 100) - (d2 * 10));
    
    Lcd_data(0x30 + d4);
    Lcd_data(0x30 + d3);
    Lcd_data(0x30 + d2);
    Lcd_data(0x30 + d1);
}









