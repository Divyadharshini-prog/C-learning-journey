/*
 * File:   task_interrupt.c
 * Author: D E L L
 *
 * Created on October 7, 2024, 11:34 PM
 */


// PIC16F877A Configuration Bit Settings
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Disable
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000  // Define crystal frequency for delay

unsigned char value;  // Variable to store the value of PORTB

// Main program function
void main() {
    // Port B configuration - RB0 as input for external interrupt
    TRISB = 0x01;  // RB0/INT (bit 0) as input, rest as output (0000 0001)
    PORTB = 0x00;  // Clear PORTB
    
    // Port D configuration - Output for LED control
    TRISD = 0x00;  
    PORTD = 0x00;  // Clear PORTD
    
    // Port C configuration - Output for blinking LED
    TRISC = 0x00;  
    PORTC = 0x00;  // Clear PORTC
    
    // External interrupt configuration
    INTCON = 0x90;  // Enable Global Interrupt (GIE) and INT External Interrupt (INTE)
    // GIE = 1 (Global Interrupt Enable), INTE = 1 (External Interrupt on RB0/INT enabled)

    // External interrupt will be triggered on rising edge (1 -> 0 transition) by default

    // Main loop
    while (1) {
        // Regular LED blinking on Port C
        PORTC = ~PORTC;  // Toggle Port C
        __delay_ms(500);  // Delay for 500ms

        // LED on Port C will blink normally until the external interrupt on RB0/INT occurs
    }
}

// Interrupt Service Routine (ISR)
void __interrupt() ISR() {
    // Check if the interrupt is caused by RB0/INT (INTF flag)
    if (INTCON & 0x02) {  
        // Toggle the LED on Port D
        PORTD = ~PORTD;  // Toggle Port D

        // Turn off the LED on Port C during the interrupt handling
        PORTC = 0x00;  // Ensure Port C LED is OFF during interrupt

        // Clear the INTF flag to acknowledge the external interrupt on RB0/INT
        INTCON &= ~(0x02);  // Clear bit 1 (INTF)

        // A delay for visual feedback of interrupt handling (optional)
        __delay_ms(5000);  // Delay for 5 seconds
    }
}

