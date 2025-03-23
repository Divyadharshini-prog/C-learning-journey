/*
 * File:   class_code.c
 * Author: D E L L
 *
 * Created on July 10, 2024, 12:49 AM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

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

void init();
void Lcd_command(unsigned char);
void Lcd_data(unsigned char);
unsigned char x,n,m,i;
unsigned char ar[11]={"HELLO WORLD"};

void main()
{
init();
Lcd_command(0x80);
for(x=0; x<=10 ; x++)
{
Lcd_data(ar[x]);
}
while(1);
}

void init()
{
TRISC = 0X00;   //RC3 is Register select (RS),RC0 is Enable (EN)
TRISD = 0X00;    // Data pins from DB0 to DB7
Lcd_command(0x30);  //Set command for LCD 8-bit initialization
__delay_ms(100);
Lcd_command(0x30);   //Set command for LCD 8-bit initialization
__delay_ms(100);
Lcd_command(0x30);   //Set command for LCD 8-bit initialization
__delay_ms(100);
Lcd_command(0x38);   //No.of lines and display font (00 0011 1000)
__delay_ms(100);
Lcd_command(0x06);   //shift cursor right   ,if left (00 0000 0100)
__delay_ms(100);
Lcd_command(0x0C);   //display on cursor and blink off
__delay_ms(100);
Lcd_command(0x01);   //clear display
__delay_ms(100);
}
void Lcd_data(unsigned char i)
{
PORTC|=0X08; //RS=1 RC3
PORTD=i;  //data
PORTC|=0X01;//EN=1  RC0
PORTC&= ~0X01;  //EN=0 RC0
__delay_ms(100);
}

void Lcd_command(unsigned char i)     //RS= RC2 and EN= RC0 and datapins D0 to D7
{
PORTC&=~0X08;  //RS=0 RC3
PORTD=i;     //data
PORTC|=0X01;   //EN=1 RC0
PORTC&=~0X01;   //EN=0 RC0
__delay_ms(100);
}