#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (EEPROM protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include <xc.h>                
#include "I2C_EEPROM.h"        
#define _XTAL_FREQ 16000000    

void main(void) {
   
    I2C_Master_Init(100000); 
    
    unsigned int Address = 0x0020;    // Start address for EEPROM writes
    unsigned char Data = 0x04;        // Initial data to write to EEPROM
    
    EEPROM_Write(Address++, Data++);  // Write 0x04 at 0x0020, then increment both Address and Data
    EEPROM_Write(Address++, Data++);  // Write 0x05 at 0x0021, then increment both Address and Data
    EEPROM_Write(Address, Data);      // Write 0x06 at 0x0022 (Address incremented only once here)
    
    __delay_ms(10);                   // Wait tWR (10ms) for write completion

    Address = 0x0020;    // Reset Address to the first written location
    TRISD = 0x00;        // Set PORTD as output to display read data
    PORTD = EEPROM_Read(Address++);   // Read from EEPROM @ 0x0020 and display on PORTD (expected: 0x04)
    __delay_ms(1000);
    PORTD = EEPROM_Read(Address++);   // 0x05
    __delay_ms(1000);
    PORTD = EEPROM_Read(Address);   //0x06
    while(1)
    {
        
    }
    return;
}
