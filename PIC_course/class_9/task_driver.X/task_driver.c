/*
 * File:   task_driver.c
 * Author: D E L L
 *
 * Created on October 5, 2024, 9:57 PM
 */


// Configuration bits for PIC16F877A
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (EEPROM protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "task_bsp.h"  //  internal pull-up configuration

#define _XTAL_FREQ 6000000  

unsigned char value;

void main(void) {
    // Initialize I/O
    TRISC = 0x00;   // Configure RC2 and RC7 as output
    PORTC = 0x00;   // Clear PORTC output
    TRISB = 0xF0;   // Configure RB4, RB5, RB6, RB7 as input (1111 0000)
    PORTB = 0x00;   // Clear PORTB
    
    // Enable internal pull-up for PORTB using BSP function
    enable_internal_pullup();
    while (1) {
        value = PORTB & 0xF0;  // Read upper nibble of PORTB

        // Switch-case to control PORTC based on PORTB input
        switch (value) {
            case 0xE0: 
                PORTC = 0x80;  // RC2 is 0, RC7 is 1
                break;
            case 0xD0: 
                PORTC = 0x04;  // RC2 is 1, RC7 is 0
                break;
            case 0xB0: 
                PORTC = 0x00;  // RC2 is 0, RC7 is 0
                break;
            case 0x70: 
                PORTC = 0x84;  // RC2 is 1, RC7 is 1
                break;
            case 0xF0: 
                PORTC = 0x00;  // Default case, no output
                break;
            default:
                PORTC = 0x00;  // Default case for any unexpected input
                break;
        }
    }
}
