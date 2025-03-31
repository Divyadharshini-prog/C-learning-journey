/*
 * File:   SPI_master.c
 * Author: D E L L
 *
 * Created on December 27, 2024, 11:47 PM
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
void SPI_master();
void SPI_write(unsigned char);

void main(void)
{
    SPI_master();
    unsigned char data=0;
    TRISB = 0x07;
    TRISD = 0x00;
    PORTD = 0x00;
    while(1)
    {
    if(RB0)
    {
        data++;
        __delay_ms(250);
    }
    if(RB1)
    {
        data--;
        __delay_ms(250);     
    }
    if(RB2)
    {
        SPI_write(data);
        __delay_ms(250);    
    }
    PORTD = data;       
}
}
void SPI_master()
{
    SSPCON = 0x30;     // Configure SPI as master, clock = FOSC/4
    SSPSTAT = 0x00;   // Configure for standard SPI operation
    TRISC = 0x10;   // Configure RC3 (SCK) as output, RC4 (SDI) as input, RC5 (SDO) as output    
}
void SPI_write(unsigned char data)
{
    SSPBUF = data;  // Load data into the SPI buffer to start transmission
    //while (!SSPSTATbits.BF);  // Wait until transmission is complete
}
