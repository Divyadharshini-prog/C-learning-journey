// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 6000000    // 6 MHz crystal frequency

// Keypad connections (Rows and Columns)
#define ROW1 0x01  // RB0 (Row 1)
#define ROW2 0x02  // RB1 (Row 2)
#define ROW3 0x04  // RB2 (Row 3)
#define ROW4 0x08  // RB3 (Row 4)

#define COL1 0x10  // RD4 (Column 1)
#define COL2 0x20  // RD5 (Column 2)
#define COL3 0x40  // RD6 (Column 3)

// LCD Control Pins
#define RS 0x08   // RC3
#define EN 0x01   // RC0

// Function declarations
void init();
void Lcd_command(unsigned char);
void Lcd_data(unsigned char);
void Lcd_set_cursor(unsigned char, unsigned char);
unsigned char get_key();
void debounce();

unsigned char cursor_position = 1;  // Track cursor position on LCD

void main() {
    unsigned char key;
    
    init();  // Initialize LCD and keypad

    Lcd_command(0x01);  // Clear display
    Lcd_set_cursor(1, 1);  // Set cursor to row 1, column 1

    while (1) {
        key = get_key();  // Get the key pressed on the keypad
        if (key != 'n') {  // If a valid key is detected
            Lcd_set_cursor(1, cursor_position);  // Set cursor position on LCD
            Lcd_data(key);  // Display key on LCD
            cursor_position++;  // Move cursor to next position
            
            if (cursor_position > 16)  // Reset cursor position if past 16 characters
                cursor_position = 1;

            debounce();  // Debounce the keypad
        }
    }
}

// Initialize LCD and keypad settings
void init() {
    TRISC = 0x00;  // Set PORTC as output for LCD
    TRISD = 0xF0;  // Upper nibble (RD4-RD6) for columns of keypad, lower nibble for LCD data
    TRISB = 0xF0;  // Set PORTB lower nibble as output (for keypad rows)

    Lcd_command(0x30);  // Initialize LCD in 8-bit mode
    __delay_ms(100);
    Lcd_command(0x30);  // Initialize again
    __delay_ms(100);
    Lcd_command(0x30);  // Initialize again
    __delay_ms(100);
    Lcd_command(0x38);  // Configure LCD: 2-line, 5x8 font
    __delay_ms(100);
    Lcd_command(0x06);  // Entry mode: Increment cursor, no display shift
    __delay_ms(100);
    Lcd_command(0x0C);  // Display ON, cursor OFF, blink OFF
    __delay_ms(100);
    Lcd_command(0x01);  // Clear display
    __delay_ms(100);
}

// Function to send commands to the LCD
void Lcd_command(unsigned char cmd) {
    PORTC &= ~RS;  // RS = 0 for command mode
    PORTD = cmd;   // Send command
    PORTC |= EN;   // Enable = 1
    PORTC &= ~EN;  // Enable = 0
    __delay_ms(100);  // Delay to allow command execution
}

// Function to send data to the LCD
void Lcd_data(unsigned char data) {
    PORTC |= RS;   // RS = 1 for data mode
    PORTD = data;  // Send data
    PORTC |= EN;   // Enable = 1
    PORTC &= ~EN;  // Enable = 0
    __delay_ms(100);  // Delay to allow data writing
}

// Function to set cursor position on LCD
void Lcd_set_cursor(unsigned char row, unsigned char column) {
    unsigned char pos;
    if (row == 1) {
        pos = 0x80 + (column - 1);  // First row, 0x80 + column offset
    } else if (row == 2) {
        pos = 0xC0 + (column - 1);  // Second row, 0xC0 + column offset
    }
    Lcd_command(pos);  // Set cursor position
}

// Function to scan the keypad and detect which key is pressed
unsigned char get_key() {
    // Scan Row 1
    PORTB = (PORTB & 0xF0) | ROW1;
    if (!(PORTD & COL1)) { debounce(); return '1'; }
    if (!(PORTD & COL2)) { debounce(); return '2'; }
    if (!(PORTD & COL3)) { debounce(); return '3'; }

    // Scan Row 2
    PORTB = (PORTB & 0xF0) | ROW2;
    if (!(PORTD & COL1)) { debounce(); return '4'; }
    if (!(PORTD & COL2)) { debounce(); return '5'; }
    if (!(PORTD & COL3)) { debounce(); return '6'; }

    // Scan Row 3
    PORTB = (PORTB & 0xF0) | ROW3;
    if (!(PORTD & COL1)) { debounce(); return '7'; }
    if (!(PORTD & COL2)) { debounce(); return '8'; }
    if (!(PORTD & COL3)) { debounce(); return '9'; }

    // Scan Row 4
    PORTB = (PORTB & 0xF0) | ROW4;
    if (!(PORTD & COL1)) { debounce(); return '*'; }
    if (!(PORTD & COL2)) { debounce(); return '0'; }
    if (!(PORTD & COL3)) { debounce(); return '#'; }

    return 'n';  // No valid key pressed
}

// Function to implement keypad debouncing
void debounce() {
    __delay_ms(20);  // Simple delay for debouncing
    while (!(PORTD & COL1) || !(PORTD & COL2) || !(PORTD & COL3));  // Wait for key release
    __delay_ms(20);  // Delay after key release
}
