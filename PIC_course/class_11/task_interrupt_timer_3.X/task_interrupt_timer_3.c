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

unsigned int C = 0;  // Global counter variable

void main() {
    
    TRISB = 0x00;  // Set all PORTB pins as output (TRISB0 = 0 means output)
    PORTB = 0x00;  // Initialize PORTB to 0 (turn off all LEDs initially)

    //  Configure Timer1 to operate in Timer Mode 
    // Preload the value for 16-bit Timer1
    TMR1H = 0x3C;  // High byte of 15535 (0x3C1F)
    TMR1L = 0x1F;  // Low byte of 15535 (0x3C1F)

    // Timer1 in timer mode (internal clock)
    T1CON = 0x00;  // T1CKPS1 = 0, T1CKPS0 = 0 (prescaler 1:1), TMR1CS = 0 (timer mode)

    // Event1 = Turn LED ON (initial state of RB0)
    PORTB = 0x01;  // Set RB0 (LED ON)

    // Switch ON Timer1
    T1CON |= 0x01;  // TMR1ON = 1 (Start Timer1)

    // -- [[ Interrupts Configurations ]] --
    TMR1IF = 0x00;  // Clear Timer1 interrupt flag
    TMR1IE = 0x01;  // Enable Timer1 interrupt
    PEIE = 0x01;    // Enable peripheral interrupts
    GIE = 0x01;     // Enable global interrupts

    
    while (1) {
        
    }
}


void __interrupt() ISR() {
   
    if (TMR1IF) {
        C++;  // Increment the counter at every Timer1 overflow

        if (C == 20) {  // After 20 overflows (counts), toggle the LED
            PORTB = ~PORTB;  // Toggle RB0 (LED)
            C = 0;  // Reset the counter
        }

        // Preload the value back into Timer1 for the next overflow
        TMR1H = 0x3C;  // High byte of the preload value (15535)
        TMR1L = 0x1F;  // Low byte of the preload value (15535)

        TMR1IF = 0x00;  // Clear Timer1 interrupt flag
    }
}
