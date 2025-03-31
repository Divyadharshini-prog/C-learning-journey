/*
 * File:   Class5_pwm.c
 * Author: D E L L
 *
 * Created on July 29, 2024, 4:55 PM
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

void init(void); 
void pwmchange(void);

unsigned char pwmhigh10,pwmlow10; //declaration of variables
unsigned char pwmhigh50,pwmlow50;
unsigned char pwmhigh80,pwmlow80;

void main(void) 
{
init();
while(1)
{
    pwmchange();           
}
}
void init(void)
{
    TRISC=0xFB;   //1111 1011 RC2 as output and others as input
    CCP1CON=0x0C;  //According to datasheet CCP1CON register 11xx for pwm mode (0000 1100)
    T2CON=0X06;   //Timer ON (prescaler 16) 0000 0110
    PR2=0X5E;   //declaration of period register using formula
    pwmhigh10=0x09;  //8-bit data so directly configured as 0000 1001
    pwmlow10=0x20;  //0x02 shifted to 5:4 bit as 0x20
    pwmhigh50=0x2F;   
    pwmlow50=0x00;       
    pwmhigh80=0x4B;
    pwmlow80=0x00;
}
void pwmchange()
{
    CCPR1L=pwmhigh10;
    CCP1CON=(CCP1CON&0xCF)|pwmlow10; //0xCF mask value
    __delay_ms(3000); //3 seconds delay
    CCPR1L= pwmhigh50;
    CCP1CON=(CCP1CON&0xCF)|pwmlow50;
    __delay_ms(3000);
    CCPR1L= pwmhigh80;
    CCP1CON=(CCP1CON&0xCF)|pwmlow80;
    __delay_ms(3000);
}