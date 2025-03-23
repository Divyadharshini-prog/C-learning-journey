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

unsigned char pwmhigh20,pwmlow20; //declaration of variables
unsigned char pwmhigh60,pwmlow60;
unsigned char pwmhigh90,pwmlow90;

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
    TRISC =0xFB;   //1111 1011 RC2 as output and others as input
    CCP2CON=0x0C;  //According to datasheet CCP2CON register 11xx for pwm mode (0000 1100)
    T2CON=0X06;   //Timer ON (prescaler 16) 0000 0110
    PR2=0X2D; //Period declaration using formula  45 => 2D      
    pwmhigh20=0x04;  //8-bit data so directly configured as 0000 1001
    pwmlow20=0x00;  //0x02 shifted to 5:4 bit as 0x20
    pwmhigh60=0x1C;   
    pwmlow60=0x00;       
    pwmhigh90=0x2A;
    pwmlow90=0x00;

}
void pwmchange()
{
    CCPR2L=pwmhigh20;
    CCP2CON=(CCP2CON&0xCF)|pwmlow20; //0xCF mask value
    __delay_ms(3000); //3 seconds delay
    CCPR2L= pwmhigh60;
    CCP2CON=(CCP2CON&0xCF)|pwmlow60;
    __delay_ms(3000);
    CCPR2L= pwmhigh90;
    CCP2CON=(CCP2CON&0xCF)|pwmlow90;
    __delay_ms(3000);
}
