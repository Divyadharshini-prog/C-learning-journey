/*
 * File:   memory_mapping_task.c
 * Author: D E L L
 *
 * Created on October 8, 2024, 11:41 PM
 */


// PIC16F877A Configuration Bit Settings
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (EEPROM protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#define _XTAL_FREQ 6000000  // 6 MHz frequency for delays

// Memory-mapped address for OPTION_REG, TRISC, and PORTC registers
#define OPTION_REG_ADDR 0x81
#define TRISC_ADDR      0x87
#define PORTC_ADDR      0x07

// Function to enable internal pull-up for PORTB by modifying OPTION_REG
void enable_internal_pullup() {
     unsigned char* option_reg = (unsigned char*) OPTION_REG_ADDR;  // Map memory to OPTION_REG
    *option_reg &= ~(1 << 7);  // Clear bit 7 of OPTION_REG to enable internal pull-up
}

// Function to set TRISC register using memory-mapped access
void set_trisc(unsigned char value) {
     unsigned char* trisc_reg = (unsigned char*) TRISC_ADDR;  // Map memory to TRISC register
    *trisc_reg = value;  // Set the value of TRISC register
}

// Function to set PORTC register using memory-mapped access
void set_portc(unsigned char value) {
     unsigned char* portc_reg = (unsigned char*) PORTC_ADDR;  // Map memory to PORTC register
    *portc_reg = value;  // Set the value of PORTC register
}

unsigned char value;

void main(void) {
    // Initialize I/O
    set_trisc(0x00);   // Set TRISC via memory-mapped access (RC2 and RC7 as output)
    set_portc(0x00);   // Clear PORTC via memory-mapped access (all outputs cleared)

    TRISB = 0xF0;      // Configure RB4, RB5, RB6, RB7 as input (1111 0000)
    PORTB = 0x00;      // Clear PORTB
    
    // Enable internal pull-up for PORTB using BSP function
    enable_internal_pullup();

    while (1) {
        value = PORTB & 0xF0;  // Read upper nibble of PORTB

        // Switch-case to control PORTC based on PORTB input
        switch (value) {
            case 0xE0: 
                set_portc(0x80);  // RC2 is 0, RC7 is 1 via memory-mapped access
                break;
            case 0xD0: 
                set_portc(0x04);  // RC2 is 1, RC7 is 0 via memory-mapped access
                break;
            case 0xB0: 
                set_portc(0x00);  // RC2 is 0, RC7 is 0 via memory-mapped access
                break;
            case 0x70: 
                set_portc(0x84);  // RC2 is 1, RC7 is 1 via memory-mapped access
                break;
            case 0xF0: 
                set_portc(0x00);  // Default case, no output via memory-mapped access
                break;
            default:
                set_portc(0x00);  // Default case for any unexpected input via memory-mapped access
                break;
        }
    }
}

