/*
 * File:   ADC_PWM_DYNAMIC.c
 * Author: D E L L
 *
 * Created on September 4, 2024, 12:27 AM
 */

// PIC16F877A Configuration Bit Settings

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 6000000
#define CALIBRATION_VALUE_AN2   337   // Calibrate for AN2 (0-337)
#define NUMBER_OF_BIT           1023  // ADC result range 0-1023
#define PWM_MAX_DUTY            255   // Maximum PWM duty cycle value (8-bit resolution)

void init();
void lcd_com(unsigned char);
void lcd_data(unsigned char);
void lcd_output_raw(unsigned int);
void lcd_output_cal(unsigned int);
void read_adc_channel(unsigned char channel);
void update_pwm_duty(unsigned int adc_value);

unsigned int adc_low, adc_high;
unsigned int result_ch0, result_ch2;
unsigned char msg_ch0[10] = {"Ch0: "};  // Display message for channel 0
unsigned char msg_ch2[10] = {"Ch1: "};  // Display message for channel 1

void main() {
    int i;
    init();      
    lcd_com(0x80);  // Set cursor to first row
    for (i = 0; i < 5; i++) {
        lcd_data(msg_ch0[i]);  // Print "Ch0: "
    }
    
    lcd_com(0xC0);  // Set cursor to second row
    for (i = 0; i < 5; i++) {
        lcd_data(msg_ch2[i]);  // Print "Ch1: "
    }

    while (1) {
        // Read ADC value for AN0 (Ch0)
        read_adc_channel(0);  // Read from AN0
        result_ch0 = (adc_high << 8) | adc_low;  // Combine high and low bits
        lcd_com(0x85);  // Move to display position for Ch0
        lcd_output_raw(result_ch0);  // Display raw value for Ch0 (0-1023)

        // Read ADC value for AN2 (Ch1)
        read_adc_channel(2);  // Read from AN2
        result_ch2 = (adc_high << 8) | adc_low;  // Combine high and low bits
        
        result_ch2 = ((float)result_ch2 * CALIBRATION_VALUE_AN2 + NUMBER_OF_BIT / 2) / NUMBER_OF_BIT;  // Scale to 0-337
        
        lcd_com(0xC5);  // Move to display position for Ch1
        lcd_output_cal(result_ch2);  // Display scaled value for Ch1 (0-337)

        // Update PWM duty cycle based on the value from ADC channel 0
        update_pwm_duty(result_ch0);  // Dynamically adjust PWM

        __delay_ms(100);  // Delay for stability
    }
}

// Function to select and read from the specified ADC channel (AN0 or AN2)
void read_adc_channel(unsigned char channel) {
    if (channel == 0) {
        ADCON0 = 0x81;  // Select AN0 (Channel 0) and turn ADC on
    } else if (channel == 2) {
        ADCON0 = 0x91;  // Select AN2 (Channel 1) and turn ADC on
    }
    ADCON0 |= 0x04;  // Start ADC conversion
    while (ADCON0 & 0x04);  // Wait for conversion to complete
    adc_high = ADRESH;  // Read high byte
    adc_low = ADRESL;   // Read low byte
}

// Function to output the raw ADC value (0-1023) for channel 0
void lcd_output_raw(unsigned int i) {
    unsigned char k[5];
    k[0] = (i / 1000) % 10; // Thousands place
    k[1] = (i / 100) % 10;  // Hundreds place
    k[2] = (i / 10) % 10;   // Tens place
    k[3] = i % 10;          // Ones place

    // Display each digit
    lcd_data(0x30 + k[0]); // Display thousands digit
    lcd_data(0x30 + k[1]); // Display hundreds digit
    lcd_data(0x30 + k[2]); // Display tens digit
    lcd_data(0x30 + k[3]); // Display ones digit
}

// Function to output the calibrated ADC value (0-337) for channel 1
void lcd_output_cal(unsigned int i) {
    unsigned char k[3];
    k[0] = (i / 100) % 10;  // Hundreds place
    k[1] = (i / 10) % 10;   // Tens place
    k[2] = i % 10;          // Ones place

    // Display each digit
    lcd_data(0x30 + k[0]); // Display hundreds digit
    lcd_data(0x30 + k[1]); // Display tens digit
    lcd_data(0x30 + k[2]); // Display ones digit
}

// Update PWM duty cycle based on ADC value
void update_pwm_duty(unsigned int adc_value) {
    unsigned int duty_cycle;

    // Scale ADC result (0-1023) to PWM duty cycle (0-255)
    duty_cycle = (adc_value * PWM_MAX_DUTY) / NUMBER_OF_BIT;

    // Set the new duty cycle value to CCP1 (PWM output on RC2)
    CCPR1L = duty_cycle >> 2;         // Load upper 8 bits of duty cycle
}

// LCD initialization and control functions
void init() {
    
    TRISA = 0x05;  // Configure AN0 and AN2 as input
    TRISC = 0x00;  // Port C as output (for LCD control)
    TRISD = 0x00;  // Port D as output (for LCD data)

    // ADC setup
    ADCON0 = 0x81;  // ADC on, select AN0 initially
    ADCON1 = 0x8E;  // Configure AN0 and AN2 as analog, others as digital

    // PWM setup
    CCP1CON = 0x0C; // Set CCP1 in PWM mode
    T2CON = 0x06;   // Enable Timer2, prescaler = 16
    PR2 = 0x5E;     // Set PWM period for 1kHz frequency
    CCPR1L = 0x00;  // Start with 0% duty cycle
    

    // LCD initialization sequence
    lcd_com(0x30);
    __delay_ms(100);
    lcd_com(0x30);
    __delay_ms(100);
    lcd_com(0x30);
    __delay_ms(100);
    lcd_com(0x38);  // Set LCD to 8-bit mode, 2-line display
    __delay_ms(100);
    lcd_com(0x06);  // Set entry mode: move cursor right
    __delay_ms(100);
    lcd_com(0x0C);  // Display on, cursor off
    __delay_ms(100);
    lcd_com(0x01);  // Clear display
    __delay_ms(100);
}

void lcd_com(unsigned char i) {
    PORTC &= ~0x08;  // RS = 0 (command mode)
    PORTD = i;       // Send command to LCD
    PORTC |= 0x01;   // Enable pulse
    PORTC &= ~0x01;  // Disable pulse
    __delay_ms(100);
}

void lcd_data(unsigned char i) {
    PORTC |= 0x08;   // RS = 1 (data mode)
    PORTD = i;       // Send data to LCD
    PORTC |= 0x01;   // Enable pulse
    PORTC &= ~0x01;  // Disable pulse
    __delay_ms(100);
}
