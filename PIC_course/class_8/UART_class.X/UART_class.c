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

void init();               
unsigned char Button_state; 

void main()
{
  init();   

  while(1)
  {
      Button_state = PORTB;   // Read the state of PORTB (4 switches are connected)

      switch(Button_state)
      {
          case 0xE0:          // If button 1 is pressed (0b11100000), send 'A'
              TXREG = 'A';    // Send 'A' through UART
              __delay_ms(100); // Add delay to stabilize the communication
              break;

          case 0xD0:          // If button 2 is pressed (0b11010000), send 'B'
              TXREG = 'B';    // Send 'B' through UART
              __delay_ms(100);
              break;

          case 0xB0:          // If button 3 is pressed (0b10110000), send 'C'
              TXREG = 'C';    // Send 'C' through UART
              __delay_ms(100);
              break;

          case 0x70:          // If button 4 is pressed (0b01110000), send 'D'
              TXREG = 'D';    // Send 'D' through UART
              __delay_ms(100);
              break;
      }  
  }
}    

void init()
{
    TRISB = 0xF0;  // Set PORTB upper nibble as input for buttons (RB4-RB7 as inputs)
    PORTB = 0x00;  // Clear PORTB
    
    OPTION_REG &= 0x7F;  // Enable PORTB internal pull-ups (bit 7 of OPTION_REG)

    TRISC = 0xC0;  // Set TX (RC6) as output and RX (RC7) as input
    TXSTA = 0x20;  // Enable transmitter (TX) and asynchronous mode
    RCSTA = 0x90;  // Enable receiver (RX) and serial port
    SPBRG = 0x09;  // Set baud rate to 9600 for 6MHz crystal
}
