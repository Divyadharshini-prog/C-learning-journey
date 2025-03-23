/*
 * File:   class_1_code.c
 * Author: D E L L
 *
 * Created on June 25, 2024, 10:09 PM
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
#define _XTAL_FREQ 6000000  // SET 6MHz clock frequency

void main(void) {
 TRISC= 0XFB;  //Set RC2 as output and rest as input(1111 1011)
 while(1)
 {
     PORTC = 0X04;  //Set led as high (0000 0100)
     __delay_ms(1000);  //1 second =1000ms
     PORTC = 0X00; //Set led as low (0000 0000)
     __delay_ms(1000);  //1 second =1000ms
 }   
}
