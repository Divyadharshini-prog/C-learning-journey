/*
 * File:   task1_pullup.c
 * Author: D E L L
 *
 * Created on July 3, 2024, 12:39 AM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>
#define _XTAL_FREQ 6000000 //6Mhz frequency
unsigned char value;
void main(void) {
    TRISD = 0X00;    //configure RD5 and RC3 as output
    PORTD = 0X00;   // output as 0 so 0000 0000
    TRISC = 0X0F;    //RC0,RC1,RC2,RC3 as input 0000 1111 
    PORTC = 0X00;
    while(1)
    {
        value = PORTC; 
        switch (value)
        {
            case 0x0E: PORTD = 0x08;  //1000 0000 rd5 is 0 rd3 is 1
            break;
            case 0x0D: PORTD = 0x00; //0000 0100 rd5 is 0 rd3 is 0
            break;
            case 0x0B: PORTD = 0x28;//0000 0000 rd5 is 1 rd3 is 1
            break;
            case 0x07: PORTD = 0x20; //1000 0100 rd5 is 1 rd3 is 0
            break;
            case 0x0F: PORTD = 0x00; //0000 0000 default 
            break;
        }          
        }
}