/*
 * File:   SPI_class.c
 * Author: D E L L
 *
 * Created on December 27, 2024, 10:58 PM
 */
#pragma config FOSC = EXTRC   // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF     // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF    // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF    // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF      // Low-Voltage Programming Enable bit
#pragma config CPD = OFF      // Data EEPROM Memory Code Protection bit (Off)
#pragma config WRT = OFF      // Flash Program Memory Write Enable bits (Off)
#pragma config CP = OFF       // Flash Program Memory Code Protection bit (Off)

#include <xc.h>
#define _XTAL_FREQ 6000000

void SPI_slave();
unsigned char data;
void main(void)
{
    SPI_slave();
    TRISB= 0x00;
    PORTB = 0x00;
    while(1)
    {
        PORTB= data;
    }
}
void SPI_slave()
{
    SSPCON = 0x24;
    SSPSTAT = 0x00;
    TRISC = 0x18;
    ADCON1 = 0x04;
    TRISA = 0x20;
    PIE1 = 0x08;
    INTCON = 0xC0;
}

void __interrupt() ISR(void)
{
    if (PIR1 & 0x08)
    {
        data= SSPBUF;
        PIR1 &=~0x08;
    }
}