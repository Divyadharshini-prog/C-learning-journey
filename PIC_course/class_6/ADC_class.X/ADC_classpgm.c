/*
 * File:   ADC_classpgm.c
 * Author: D E L L
 *
 * Created on September 1, 2024, 3:38 PM
 */

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000

#include <stdint.h>
#define CALIBRATION_VALUE   48
#define NUMBER_OF_BIT       1023

void init();
void lcd_com(unsigned char);
void lcd_data(unsigned char);
void lcd_output(unsigned int);

unsigned int adc_low, adc_high;
unsigned int result;
unsigned char volt;
unsigned char msg_1[10] = {"ADC raw: "};
unsigned char msg_2[10] = {"ADC cal: "};

void main() {
    int i;
    init();
    lcd_com(0x80);
    for(i = 0; i < 9; i++) 
    {
        lcd_data(msg_1[i]);
    }
    lcd_com(0xc0);
    for(i = 0; i < 9 ; i++)
    {
        lcd_data(msg_2[i]);
    }
    while(1) 
    {
        ADCON0 = 0x81;
        ADCON0 |= 0x04;   // Start conversion
        while (ADCON0 & 0x04); // Wait for conversion to complete
        adc_high = ADRESH;
        adc_low = ADRESL;
        result = (adc_high << 8) | adc_low; // Combine the high and low bytes
        volt = (result * CALIBRATION_VALUE) / NUMBER_OF_BIT; // Calibrate the ADC value
        
        lcd_com(0x89);  // Position cursor after "ADC raw: "
        lcd_output(result);  // Display raw ADC value
        
        lcd_com(0xc9);  // Position cursor after "ADC cal: "
        lcd_output(volt);  // Display calibrated value
        lcd_data('V');  // Display 'V' after the calibrated value
        
        __delay_ms(100);
    }
}

void lcd_output(unsigned int i) 
{
    unsigned char s, j = 0;
    unsigned int m;
    unsigned char k[5];
    
    m = i;
    if (m == 0)
    {
        lcd_data('0');
        return;
    }

    while (m != 0) 
    {
        s = (m % 10);
        k[j++] = s + '0';  // Store each digit as a character
        m = m / 10;
    }
    
    
    for (j--; j != 0xFF; j--)
    {  // Loop backwards through the array to display the number
        lcd_data(k[j]);
    }
}

void init()
{
    TRISA= 0x01;  //0000 0001
    TRISC=0x00;
    TRISD= 0x00;
    ADCON0 = 0x81;
    ADCON1 = 0x8E;
    lcd_com(0x30);
    __delay_ms(100);
    lcd_com(0x30);
    __delay_ms(100);
    lcd_com(0x30);
    __delay_ms(100);
    lcd_com(0x38);
    __delay_ms(100);
    lcd_com(0x06);
    __delay_ms(100);
    lcd_com(0x0C);
    __delay_ms(100);
    lcd_com(0x01);
    __delay_ms(100);
}

void lcd_com(unsigned char i) 
{
    PORTC &= ~0x08;
    PORTD = i;
    PORTC |= 0x01;      // EN = 1
    PORTC &= ~0x01;     // EN = 0
    __delay_ms(100);
}

void lcd_data(unsigned char i) 
{
    PORTC |= 0x08;      // RS = 1
    PORTD = i;      
    PORTC |= 0x01;      // EN = 1
    PORTC &= ~0x01;     // EN = 0
    __delay_ms(100);
}

