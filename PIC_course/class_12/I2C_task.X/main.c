
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (EEPROM protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "I2C_EEPROM.h"  // Include the custom EEPROM library

#define _XTAL_FREQ 16000000

void main(void) {
    
    I2C_Master_Init(100000);

    // Write Operations
    EEPROM_Write(0x0023, 'A');  // Write 'A' (0x41) to address 0x0023
    __delay_ms(10);             // Wait for EEPROM write cycle
    EEPROM_Write(0x0028, 'B');  // Write 'B' (0x42) to address 0x0028
    __delay_ms(10);             // Wait for EEPROM write cycle
    EEPROM_Write(0x0036, 'C');  // Write 'C' (0x43) to address 0x0036
    __delay_ms(10);             // Wait for EEPROM write cycle

    // Set PORTD as output for displaying data
    TRISD = 0x00;               // Configure PORTD as output

    // Read and Display Operations
    PORTD = EEPROM_Read(0x0023);  // Read from address 0x0023 (should be 'A') and display on PORTD
    __delay_ms(1000);             // Delay to observe the result on LEDs
    
    PORTD = EEPROM_Read(0x0028);  // Read from address 0x0028 (should be 'B') and display on PORTD
    __delay_ms(1000);             // Delay to observe the result on LEDs

    PORTD = EEPROM_Read(0x0036);  // Read from address 0x0036 (should be 'C') and display on PORTD
    __delay_ms(1000);             // Delay to observe the result on LEDs

    while (1);  // Infinite loop to prevent program from terminating
}

