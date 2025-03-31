/*
 * File:   class_code.c
 * Author: D E L L
 *
 * Created on July 2, 2024, 10:55 PM
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
#define _XTAL_FREQ 6000000 //6Mhz frequency
unsigned char value;
void main(void) {
    TRISC = 0X00;    //configure RC2 and RC7 as output
    PORTC = 0X00;   // output as 0 so 0000 0000
    TRISB = 0XF0;    //RB4, RB5,RB6, RB7 as input 1111 0000
    PORTB = 0X00;
    while(1)
    {
        value = PORTB; 
        switch (value)
        {
            case 0xE0: PORTC = 0x80;  //1000 0000 rc2 is 0 rc7 s 1
            break;
            case 0xD0: PORTC = 0x04; //0000 0100 rc2 is 1 rc7 s 0
            break;
            case 0xB0: PORTC = 0x00;//0000 0000 rc2 is 0 rc7 s 0
            break;
            case 0x70: PORTC = 0x84; //1000 0100 rc2 is 1 rc7 s 1
            break;
            case 0xF0: PORTC = 0x00; //0000 0000 default 
            break;
                    
        }
    }
}
