/*
 * File:   task_interrupt_timer_1.c
 * Author: D E L L
 *
 * Created on October 22, 2024, 11:09 PM
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

unsigned int val = 0;


void main() {
    
    TRISB = 0x00;  // Configure PORTB as output (all pins of PORTB set to output)

    // Timer1 Configuration
    // TMR1 register is the 16-bit Timer1 counter. We clear it initially.
    TMR1H = 0x00;  // Clear Timer1 high byte
    TMR1L = 0x00;  // Clear Timer1 low byte

    // T1CON register controls Timer1 configuration.
    // We set the clock source to the internal clock (Fosc/4) using TMR1CS = 0.
    T1CON = 0x01;  // Timer1 is ON, 1:1 prescaler, internal clock (TMR1CS = 0)
    
    // Set PORTB initially to a known state (RB0 = 1)
    PORTB = 0x01;  // Set RB0 high (for example, if connected to an LED)

    // Enable Timer1 (TMR1ON bit in T1CON register)
    T1CON |= 0x01;  // TMR1ON = 1, start Timer1

    // Interrupt Configuration
    // TMR1IE enables the Timer1 interrupt in PIE1 register.
    PIE1 |= 0x01;   // Enable Timer1 interrupt (TMR1IE = 1)
    
    // PIR1 register contains the Timer1 interrupt flag (TMR1IF)
    PIR1 &= 0xFE;   // Clear Timer1 interrupt flag (TMR1IF = 0)

    // Enable Peripheral Interrupts and Global Interrupts
    // PEIE enables peripheral interrupts and GIE enables all interrupts.
    INTCON |= 0xC0;  // Set GIE (Global Interrupt Enable) and PEIE (Peripheral Interrupt Enable)
    while(1) {
        // Infinite loop, waiting for Timer1 interrupts
        // All processing is done in the ISR (Interrupt Service Routine)
    }
}

void __interrupt() ISR() {
    // Check if the Timer1 interrupt flag is set (TMR1IF = 1)
    if (PIR1 & 0x01) {
        // Increment the counter (val) on each Timer1 overflow
        val++;
        if (val == 15) {
            PORTB ^= 0x01;  // Toggle RB0 (connected to an LED or other output)
            val = 0;        // Reset the counter
        }

        // Clear the Timer1 interrupt flag (TMR1IF) to acknowledge the interrupt
        PIR1 &= 0xFE;  // Clear TMR1IF (Timer1 Interrupt Flag)
    }
}
