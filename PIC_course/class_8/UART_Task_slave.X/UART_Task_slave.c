#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000  

void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_clear();
void lcd_print_characters(unsigned char type);
void init();  // Function to initialize peripherals

unsigned char Rx_buf;  // Variable to hold received data from master
unsigned char Tx_data;  // Variable to hold data to transmit back to master

unsigned char lcd_rx_str[] = "RX data: ";
unsigned char lcd_tx_str[] = "TX data: ";

void main() {
    init();  // Initialize the slave PIC peripherals
    lcd_init();  // Initialize LCD

    while (1) {
        // Check if data is received from master (RCIF bit in PIR1)
        if (PIR1 & 0x20) {
            Rx_buf = RCREG;  // Read received data from master

            // Determine the response to send back to master
            switch (Rx_buf) {
                case 'A':
                    Tx_data = 'a';  // Slave sends back 'a'
                    TXREG = Tx_data;
                    __delay_ms(50);  // Add delay for transmission
                    break;
                case 'B':
                    Tx_data = 'b';  // Slave sends back 'b'
                    TXREG = Tx_data;
                    __delay_ms(50);  // Add delay for transmission
                    break;
                case 'C':
                    Tx_data = 'c';  // Slave sends back 'c'
                    TXREG = Tx_data;
                    __delay_ms(50);  // Add delay for transmission
                    break;
                case 'D':
                    Tx_data = 'd';  // Slave sends back 'd'
                    TXREG = Tx_data;
                    __delay_ms(50);  // Add delay for transmission
                    break;
            }

            // Display "RX data: X" on the first line of the LCD
            lcd_cmd(0x80);  // Move cursor to first line
            lcd_print_characters(0);  // Print "RX data: "
            lcd_data(Rx_buf);  // Display the received data

            // Display "TX data: x" on the second line of the LCD
            lcd_cmd(0xC0);  // Move cursor to second line
            lcd_print_characters(1);  // Print "TX data: "
            lcd_data(Tx_data);  // Display the transmitted data
        }
    }
}

void init() {
    // Set PORTD as output for LCD
    TRISD = 0x00;
    OPTION_REG&= 0X7F;

    // UART setup
    TRISC = 0x80;        // Set RC6 as TX (output) and RC7 as RX (input)
    TXSTA = 0x20;        // Enable UART transmission
    RCSTA = 0x90;        // Enable UART reception
    SPBRG = 0x09;        // Set baud rate to 9600 for 6MHz crystal
}

void lcd_init() {
    lcd_cmd(0x38);  // 8-bit mode, 2-line display, 5x8 font
    lcd_cmd(0x0C);  // Display ON, cursor OFF
    lcd_cmd(0x06);  // Auto-increment cursor
    lcd_cmd(0x01);  // Clear display
    __delay_ms(2);   // Wait for the LCD to initialize
}

void lcd_cmd(unsigned char i)
{
    PORTC &= ~0X08;     // RS = 0
    PORTD = i;        // Data set to portD
    PORTC |= 0X01;    // EN = 1
    PORTC &= ~0X01;   // EN = 0
    __delay_ms(100);
}

void lcd_data(unsigned char i)
{
    PORTC |= 0X08;   // RS = 1
    PORTD = i;      // Data set to portD
    PORTC |= 0X01;   // EN = 1
    PORTC &= ~0X01;   // EN = 0
    __delay_ms(100);
}
void lcd_clear() {
    lcd_cmd(0x01);  // Clear LCD display
    __delay_ms(2);   // Wait for clear command to take effect
}

// Function to print fixed strings based on the type: 0 for RX, 1 for TX
void lcd_print_characters(unsigned char type) {
    unsigned char i;

    // Print the string for RX data (first line)
    if (type == 0) {
        for (i = 0; i < 9; i++) {  // 9 characters in "RX data: "
            lcd_data(lcd_rx_str[i]);  // Send each character of "RX data: "
        }
    }
    // Print the string for TX data (second line)
    else if (type == 1) {
        for (i = 0; i < 9; i++) {  // 9 characters in "TX data: "
            lcd_data(lcd_tx_str[i]);  // Send each character of "TX data: "
        }
    }
}
