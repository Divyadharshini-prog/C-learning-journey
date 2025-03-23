/*
 * File:   task_interrupt_timer_2.c
 * Author: D E L L
 *
 * Created on October 23, 2024, 10:24 PM
 */

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
void main()
{
   
    TRISB = 0x00;     // Configure all PORTB as output (0x00)
    PORTB = 0x01;     // Initialize PORTB to 0x01 (set RB0 to high)

    T1CON = 0x10;     // Timer1 control: 0x10 (Prescaler 1:2, Fosc/4 as the clock source)

    // Load Timer1 with initial count for 500ms delay (hex values)
    TMR1H = 0x0B;     // High byte (0x0B corresponds to 3036 for 500ms)
    TMR1L = 0xDC;     // Low byte (0xDC corresponds to 3036 for 500ms)

    // Enable Timer1
    TMR1ON = 0x01;    // Start Timer1 (TMR1ON bit in T1CON register set to 1)

    // Interrupt Configuration
    TMR1IF = 0x00;    // Clear the Timer1 interrupt flag (0x00)
    TMR1IE = 0x01;    // Enable Timer1 interrupt (0x01)
    PEIE = 0x01;      // Enable peripheral interrupts (0x01)
    GIE = 0x01;       // Enable global interrupts (0x01)

    while(1)
    {
        
    }
}

void __interrupt() ISR()
{
    
    if (TMR1IF == 0x01)     // If Timer1 interrupt occurs (0x01)
    {
        PORTB = ~PORTB;     // Toggle PORTB (connected to an LED)

        TMR1IF = 0x00;      // Clear the Timer1 interrupt flag (0x00)
        
        // Reload Timer1 with the value for 500ms delay 
        TMR1H = 0x0B;       // Load high byte (0x0B)
        TMR1L = 0xDC;       // Load low byte (0xDC)
    }
}
