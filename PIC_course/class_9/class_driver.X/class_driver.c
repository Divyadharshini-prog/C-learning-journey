/*
 * File:   class_driver.c
 * Author: D E L L
 *
 * Created on October 3, 2024, 9:45 PM
 */

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 6000000
#include <xc.h>
#include "led_driver.h"

void main()
{
    led_init();
    while(1)
    {
        led_on();   // Turn on all the LEDs connected to PORTC
        __delay_ms(1000);
        led_off();    // Turn off all the LEDs connected to PORTC
        __delay_ms(1000);

    }
}
