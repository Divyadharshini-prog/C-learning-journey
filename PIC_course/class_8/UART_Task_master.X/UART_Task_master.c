#include <xc.h>
#define _XTAL_FREQ 6000000  

void init();               // Function to initialize peripherals
unsigned char Button_state; // Variable to hold the state of buttons
unsigned char Rx_data;      // Variable to store received data from Slave

void main() {
    init();  
    while (1) {
        // Read the button state from PORTB (RB4-RB7)
        Button_state = PORTB;  // Mask out lower 4 bits

        // Check which button is pressed and send appropriate data to slave
        switch (Button_state) {
            case 0xE0:  // Button 1 pressed (0b11100000)
                TXREG = 'A';  // Transmit 'A' to slave
                __delay_ms(50);  // Add delay to ensure UART transmission is complete
                break;
            case 0xD0:  // Button 2 pressed (0b11010000)
                TXREG = 'B';  // Transmit 'B' to slave
                __delay_ms(50);  // Add delay to ensure UART transmission is complete
                break;
            case 0xB0:  // Button 3 pressed (0b10110000)
                TXREG = 'C';  // Transmit 'C' to slave
                __delay_ms(50);  // Add delay to ensure UART transmission is complete
                break;
            case 0x70:  // Button 4 pressed (0b01110000)
                TXREG = 'D';  // Transmit 'D' to slave
                __delay_ms(50);  // Add delay to ensure UART transmission is complete
                break;
        }

        
        if (PIR1 & 0x20) {
            Rx_data = RCREG;  // Read received data
            

            // Update LEDs (RD0 and RD6) based on received data
            switch (Rx_data) {
                case 'a':
                    PORTD = 0x01;  // RD0 = 1, RD6 = 0
                    break;
                case 'b':
                    PORTD = 0x40;  // RD0 = 0, RD6 = 1
                    break;
                case 'c':
                    PORTD = 0x00;  // RD0 = 0, RD6 = 0
                    break;
                case 'd':
                    PORTD = 0x41;  // RD0 = 1, RD6 = 1
                    break;
                default:
                    PORTD = 0x00;
                    break;
            }
            __delay_ms(100);  // Delay to let the LED states be visible
        }
    }
}

void init() {
    // Set RB4-RB7 as inputs for switches
    TRISB = 0xF0;
    
    // Set RD0 and RD6 as outputs for LEDs
    TRISD = 0x00;
    
    // Clear PORTB and PORTD (initial state)
    PORTB = 0x00;
    PORTD = 0x00;

    // UART setup
    OPTION_REG &= 0x7F;  // Enable pull-ups
    TRISC = 0xC0;        // Set RC6 as TX (output) and RC7 as RX (input)
    TXSTA = 0x20;        // Enable UART transmission
    RCSTA = 0x90;        // Enable UART reception
    SPBRG = 0x09;        // Set baud rate to 9600 for 6MHz crystal
}
