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

void init(void);
void pwmchange(void);

// Variables for duty cycle settings
unsigned char pwmhigh20, pwmlow20; // 20% duty cycle
unsigned char pwmhigh60, pwmlow60; // 60% duty cycle
unsigned char pwmhigh90, pwmlow90; // 90% duty cycle

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
    TRISC = 0xFB;    // 1111 1011 RC2 as output and others as input
    CCP1CON = 0x0C;  // PWM mode for CCP1
    T2CON = 0x06;    // Timer2 ON, prescaler is 16
    PR2 = 0x2E;      // Period register, 46 decimal (0x2E in hex)

    // Directly assigned duty cycle values
    pwmhigh20 = 0x09;  
    pwmlow20 = 0x24;   

    pwmhigh60 = 0x1C;  
    pwmlow60 = 0x50;   

    pwmhigh90 = 0x2A;  
    pwmlow90 = 0x98;   
}

void pwmchange()
{
    // Set duty cycle to 20%
    CCPR1L = pwmhigh20;
    CCP1CON = (CCP1CON & 0xCF) | (pwmlow20); // Mask value 0xCF to clear bits 5:4
    __delay_ms(3000); // 3 seconds delay

    // Set duty cycle to 60%
    CCPR1L = pwmhigh60;
    CCP1CON = (CCP1CON & 0xCF) | (pwmlow60);
    __delay_ms(3000);

    // Set duty cycle to 90%
    CCPR1L = pwmhigh90;
    CCP1CON = (CCP1CON & 0xCF) | (pwmlow90);
    __delay_ms(3000);
}
