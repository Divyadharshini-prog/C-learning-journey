/*
 * File:   class_interrupt_timer.c
 * Author: D E L L
 *
 * Created on October 21, 2024, 11:27 PM
 */


// PIC16F877A Configuration Bit Settings

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000  

void main() {
    // LED configuration
    // Setting TRISC and TRISD as 0x00 configures PORTC and PORTD as output ports.
    TRISC = 0x00;  // Set PORTC as output (for thread mode LED)
    TRISD = 0x00;  // Set PORTD as output (for handler mode LED)
    
    // Clear PORTC and PORTD to turn off any connected LEDs initially
    PORTC = 0x00;  // Ensure that PORTC LEDs are off
    PORTD = 0x00;  // Ensure that PORTD LEDs are off

    // Timer1 configuration
    // T1CON controls Timer1 settings. Setting T1CON = 0x01 enables Timer1 with a 1:1 prescaler
    // This means that Timer1 increments with every instruction clock cycle.
    T1CON = 0x11;  // Enable Timer1 with 1:2 prescaler

    // Timer1 interrupt configuration
    // INTCON |= 0xC0 enables Global Interrupt Enable (GIE) and Peripheral Interrupt Enable (PEIE).
    // This allows interrupts to be triggered.
    INTCON |= 0xC0;  // Enable Global Interrupt (GIE) and Peripheral Interrupt Enable (PEIE)

    // Enable Timer1 interrupt
    // PIE1 |= 0x01 enables the Timer1 interrupt (TMR1IE) so that an interrupt is triggered when Timer1 overflows.
    PIE1 |= 0x01;    // Enable Timer1 interrupt (TMR1IE)

    // Clear the Timer1 interrupt flag
    // PIR1 &= 0xFE clears the Timer1 interrupt flag (TMR1IF) to ensure the interrupt flag is not set when the program starts.
    PIR1 &= 0xFE;    // Clear Timer1 interrupt flag (TMR1IF)

    // Main loop (Thread mode LED toggling)
    while(1) {
        // Toggle PORTC (connected to thread mode LED on RC1)
        PORTC = ~PORTC;  // Invert the value of PORTC, toggling the thread mode LED
        
        // Add a delay of 500 milliseconds (0.5 seconds)
        __delay_ms(500);  // Delay for 500 ms, causing the thread mode LED to blink at 1 Hz
    }
}

// Interrupt Service Routine (ISR)
void __interrupt() ISR() {
    // Check if the Timer1 interrupt flag (TMR1IF) is set
    if (PIR1 & 0x01) {
        // Toggle PORTD (connected to handler mode LED on RD0)
        PORTD = ~PORTD;  // Invert the value of PORTD, toggling the handler mode LED

        // Clear the Timer1 interrupt flag (TMR1IF) so the interrupt can occur again
        PIR1 &= 0xFE;  // Clear TMR1IF (Timer1 Interrupt Flag)
    }
}

