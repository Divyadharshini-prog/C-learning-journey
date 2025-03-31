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
unsigned char Rx_buf;       

void main()
{
  init();   

  while(1)
  {
      if(PIR1 & 0x20)  // Check if data is available in the receiver buffer (RCIF bit in PIR1)
      {
          Rx_buf = RCREG;  // Read the received data from the receiver register

          switch(Rx_buf)
          {
              case 'A':           // If 'A' is received, turn ON LED on RD4, turn OFF LED on RD1
                  PORTD = 0x10;   // RD4 ON, RD1 OFF
                  break;

              case 'B':           // If 'B' is received, turn ON LED on RD1, turn OFF LED on RD4
                  PORTD = 0x02;   // RD4 OFF, RD1 ON
                  break;

              case 'C':           // If 'C' is received, turn ON both LEDs on RD4 and RD1
                  PORTD = 0x12;   // RD4 ON, RD1 ON
                  break;

              case 'D':           // If 'D' is received, turn OFF both LEDs on RD4 and RD1
                  PORTD = 0x00;   // RD4 OFF, RD1 OFF
                  break;

              default:            // In case of any other character, turn OFF both LEDs
                  PORTD = 0x00;
                  break;
          }
      }
  }
}

void init()
{
    TRISD = 0x00;  // Set PORTD as output (for controlling LEDs)
    PORTD = 0x00;  // Clear PORTD (turn off LEDs initially)

    TRISC = 0xC0;  // Set TX (RC6) as output and RX (RC7) as input
    TXSTA = 0x20;  // Enable transmitter (TX) and asynchronous mode
    RCSTA = 0x90;  // Enable receiver (RX) and serial port
    SPBRG = 0x09;  // Set baud rate to 9600 for 6MHz crystal
}
