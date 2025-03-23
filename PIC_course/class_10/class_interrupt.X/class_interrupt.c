/*
 * File:   class_interrupt.c
 * Author: D E L L
 *
 * Created on October 6, 2024, 5:57 PM
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
    // Port B configuration - Upper nibble (RB4-RB7) as input, lower nibble as output
    TRISB = 0xF0;  
    PORTB = 0xF0;  // Clear PORTB
    
    // Port D configuration - Output for LED control
    TRISD = 0x00;  
    PORTD = 0x00;  // Clear PORTD
    
    // Port C configuration - Output for blinking LED
    TRISC = 0x00;  
    PORTC = 0x00;  // Clear PORTC
    
    // Enable internal pull-ups by clearing the RBPU bit in OPTION_REG
    OPTION_REG &= 0x7F;  // Clear bit 7 (RBPU = 0)
    
    // Interrupt setup
    INTCON = 0x88;  // Enable Global Interrupt (GIE) and RB Port Change Interrupt (RBIE)

    // Main loop
    while (1) {
        // Regular LED blinking on Port C
        PORTC = ~PORTC;  // Toggle Port C
        __delay_ms(500);  // Delay for 500ms

        // During normal operation, LED on Port C blinks until switch is pressed
    }
}

// Interrupt Service Routine (ISR)
void __interrupt() ISR() 
{
    // Check if the interrupt is caused by a change on PORTB (RBIF flag)
    if (INTCON & 0x01) 
    {  
        value = PORTB & 0xF0;  // Read the upper nibble of PORTB to check the switch status

        // If the value is 0xE0 (switch pressed), toggle the LED on Port D
        if (value == 0xE0) 
        {
            PORTD = ~PORTD;  // Toggle Port D

            // Turn off the LED on Port C during the interrupt handling
            PORTC = 0x00;  // Ensure Port C LED is OFF during interrupt
        }
        
        // Clear the RBIF flag to acknowledge the interrupt
        INTCON &= ~(0x01);  // Clear bit 0 (RBIF)

        // A delay for visual feedback of interrupt handling (optional)
        __delay_ms(5000);  // Delay for 5 seconds
    }
}






