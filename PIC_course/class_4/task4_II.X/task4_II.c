/*
 * File:   Task3_pgm.c
 * Author: D E L L
 *
 * Created on July 10, 2024, 11:31 PM
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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000

void init(void);
void Lcd_command(unsigned char);
void Lcd_data(unsigned char);
void Lcd_output(unsigned int);
void keyscan(void);
void display_status(void);

unsigned char array[16] = "BATT VOLT: ";
unsigned char x, value;
unsigned int battery_voltage = 175; // Initial voltage is 17.5 (represented as 175)

void main()
{
    init();
    while (1)
    {
        keyscan();
    }
}

void init(void)
{
    TRISC = 0X00;
    TRISD = 0X00;
    TRISB = 0XF0;   // RB7 to RB4 input and RB3 to RB0 as output
    PORTB = 0X00;
    OPTION_REG &= 0X7F;
    Lcd_command(0x38);
    __delay_ms(10);
    Lcd_command(0x38);
    __delay_ms(10);
    Lcd_command(0x38);
    __delay_ms(10);
    Lcd_command(0x38);
    __delay_ms(10);
    Lcd_command(0x06);
    __delay_ms(10);
    Lcd_command(0x0C);
    __delay_ms(10);
    Lcd_command(0x01);
    __delay_ms(10);
}

void keyscan(void)
{
    value = PORTB & 0xF0;
    switch (value)
    {
        case 0xE0: // Display initial voltage and status
            Lcd_command(0x80);  // First LCD position
            for (x = 0; x < 10; x++)
            {
                Lcd_data(array[x]);
            }
            Lcd_output(battery_voltage);
            display_status();
            break;

        case 0xD0: // Increment voltage
            if (battery_voltage < 205) // Max is 20.5V
            {
                battery_voltage++;
            }
            Lcd_command(0x80);  // First LCD position
            for (x = 0; x < 10; x++)
            {
                Lcd_data(array[x]);
            }
            Lcd_output(battery_voltage);
            display_status();
            break;

        case 0xB0: // Decrement voltage
            if (battery_voltage > 155) // Min is 15.5V
            {
                battery_voltage--;
            }
            Lcd_command(0x80);  // First LCD position
            for (x = 0; x < 10; x++)
            {
                Lcd_data(array[x]);
            }
            Lcd_output(battery_voltage);
            display_status();
            break;

        case 0x70: // Reset to 15.5V
            battery_voltage = 155;
            Lcd_command(0x80);  // First LCD position
            for (x = 0; x < 10; x++)
            {
                Lcd_data(array[x]);
            }
            Lcd_output(battery_voltage);
            display_status();
            break;
    }
}

void Lcd_command(unsigned char i)
{
    PORTC &= ~0X08;     // RS = 0
    PORTD = i;          // Data set to portD
    PORTC |= 0X01;      // EN = 1
    PORTC &= ~0X01;     // EN = 0
    __delay_ms(50);
}

void Lcd_data(unsigned char i)
{
    PORTC |= 0X08;      // RS = 1
    PORTD = i;      
    PORTC |= 0X01;      // EN = 1
    PORTC &= ~0X01;     // EN = 0
    __delay_ms(50);
}

void Lcd_output(unsigned int voltage)
{
    unsigned char tens = voltage / 10;   // Tens digit
    unsigned char tenths = voltage % 10; // Tenths digit
    unsigned char hundreds = tens / 10;  // Hundreds digit (should always be 1 for 15.5 to 22.5)
    
    tens = tens % 10;                    // Correct tens after extracting hundreds

    Lcd_data(0x30 + hundreds); // Display hundreds digit
    Lcd_data(0x30 + tens);     // Display tens digit
    Lcd_data('.');             // Display decimal point
    Lcd_data(0x30 + tenths);   // Display tenths digit
    
}

void display_status(void)
{
    Lcd_command(0xC0); // Move to second line
    for (x = 0; x < 14; x++)
    {
        Lcd_data(' ');  // Print spaces to clear previous message
    }
    
    Lcd_command(0xC0); // Reset to second line start after clearing
    if (battery_voltage < 175) // 155 to 175
    {
        for (x = 0; x < 12; x++)
        {
            Lcd_data("BATTERY LOW  '\0'"[x]);
        }
    }
    else if (battery_voltage <= 195) // 176 to 195
    {
        for (x = 0; x < 14; x++)
        {
            Lcd_data("BATTERY NORMAL '\0'"[x]);
        }
    }
    else // 196 to 205
    {
        for (x = 0; x < 12; x++)
        {
            Lcd_data("BATTERY HIGH  '\0'"[x]);
        }
    }
}
