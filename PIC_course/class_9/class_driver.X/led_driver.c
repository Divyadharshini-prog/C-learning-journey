/*
 * File:   led_driver.c
 * Author: D E L L
 *
 * Created on October 3, 2024, 10:04 PM
 */


#include <xc.h>
#include"led_driver.h"

void led_off()
{
    PORTC =0x00; // Clear all bits of PORTC to turn off LEDs
}

void led_on()
{
    PORTC =0xFF; // Set all bits of PORTC to high (1) to turn on LEDs

}

void led_init()
{
    TRISC = 0x00;  // Set all pins of PORTC as output by clearing the TRISC register
}
