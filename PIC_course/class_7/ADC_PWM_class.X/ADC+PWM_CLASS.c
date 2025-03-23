/*
 * File:   ADC+PWM_CLASS.c
 * Author: D E L L
 *
 * Created on September 4, 2024, 12:27 AM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

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
void lcd_output_raw(unsigned int);
void lcd_output_cal(unsigned int);

unsigned int adc_low,adc_high;
unsigned int result;
unsigned int volt;
unsigned char msg_1[10]={"ADC RAW: "};
unsigned char msg_2[10]={"ADC cal: "};

void main()
{
    int i;
	init();
       lcd_com(0x80);
        for(i=0;i<9;i++)
        {
            lcd_data(msg_1[i]);
        }
         lcd_com(0xc0);
        for(i=0;i<9;i++)
        {
            lcd_data(msg_2[i]);
        }
	while(1)
	{
        result=0;
		ADCON0=0x81;
		ADCON0 |= 0x04;  //ADCON0 => 0x85;
		while(ADCON0 & 0x04);
		adc_high = ADRESH;// Read high byte
        adc_low = ADRESL;   // Read low byte
		
		result = (adc_high << 8) | (adc_low );  // Combine high and low ADC registers
		volt = ((float)result * CALIBRATION_VALUE ) / NUMBER_OF_BIT;
        lcd_output_raw(result);
        __delay_ms(100);
                
        CCPR1L= volt >> 2;  // Upper 8 bits of duty cycle
        CCP1CON = (CCP1CON & 0xCF) | ((volt & 0x03)<<4);  // Lower 2 bits of duty cycle
        lcd_com(0x80);
        lcd_output_cal(volt);	
	}	
}


void lcd_output_raw(unsigned int i)
{
    int j=1,s;
    unsigned int m;
    unsigned char k[5];
    m=i;
 while(m != 0)     
 {
     s=(m-((m/10)*10));
     k[j]=s;
     j++;
     m=m/10;
 }
    k[j]='\0';
    j--;
    if(k[4] != 0)
    {
         lcd_com(0x88);
         lcd_data(0x30 + k[4]);
         lcd_data(0x30 + k[3]);
         lcd_data(0x30 + k[2]); 
         lcd_data(0x30 + k[1]);     
         lcd_data(0x56); 
    }
    else if(k[3] != 0)
    {
         lcd_com(0x88);
         lcd_data(0x20);
         lcd_data(0x30 + k[3]);
         lcd_data(0x30 + k[2]); 
         lcd_data(0x30 + k[1]);     
        lcd_data(0x56);       
    }
       else if(k[2] != 0)
    {
         lcd_com(0x88);
         lcd_data(0x20);
         lcd_data(0x20);
         lcd_data(0x30 + k[2]); 
         lcd_data(0x30 + k[1]);    
         lcd_data(0x56); 
    }
    
      else if(k[1] != 0)
    {
       
         lcd_com(0x88);
         lcd_data(0x20);
        lcd_com(0x89);
         lcd_data(0x20);
        lcd_com(0x8A);
         lcd_data(0x20); 
        lcd_com(0x8B);
         lcd_data(0x30 + k[1]);
        lcd_com(0x8C);     
        lcd_data(0x56); 

    }
      else
      {
         lcd_com(0x88);
         lcd_data(0x20);
        lcd_com(0x89);
         lcd_data(0x20);
        lcd_com(0x8A);
         lcd_data(0x20); 
        lcd_com(0x8B);
        lcd_data(0x20); 
        lcd_com(0x8C);     
        lcd_data(0x20);
      }   
}

void lcd_output_cal(unsigned int i)
{
    int j=1,s;
    unsigned int m;
    unsigned char k[5];
    m=i;
 while(m != 0)     
 {
     s=(m-((m/10)*10));
     k[j]=s;
     j++;
     m=m/10;
 }
    k[j]='\0';
    j--;
     if(k[2] != 0)
    {
         lcd_com(0xCA);
         lcd_data(0x30 + k[2]); 
        lcd_com(0xCB);
         lcd_data(0x30 + k[1]);
         lcd_com(0xCC);    
         lcd_data(0x56); //V
    }
    
      else if(k[1] != 0)
    {
       
         lcd_com(0xCA);
         lcd_data(0x20); 
        lcd_com(0xCB);
         lcd_data(0x30 + k[1]);
         lcd_com(0xcC);    
         lcd_data(0x56); //V

    }
      else
      {
         lcd_com(0xCA);
         lcd_data(0x20); 
        lcd_com(0xCB);
         lcd_data(0x20);
         lcd_com(0xCC);    
         lcd_data(0x20); //V
      }  
}

void init()
{
	TRISA=0x01; //0000 0001
	TRISC = 0x00;  // Port C as output (for LCD control)
    TRISD = 0x00;  // Port D as output (for LCD data)
	ADCON0=0x81;
	ADCON1=0x8E;
    CCP1CON = 0x0C; //Sets in PWM mode
    T2CON = 0x06; //Timer2 on & pre scale 16
    PR2 = 0x5E; //PWM Period = 1kHz  
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
	PORTC&=~0x08;    //RS=>RC3=> 0
	PORTD=i;
	PORTC|=0x01;   //RC0 =1 
	PORTC&=~0x01;   //RC0 =0 
	__delay_ms(100);

}

void lcd_data(unsigned char i)
{
	PORTC|=0x08;    //RS=>RC3 => 1
	PORTD=i;
	PORTC|=0x01;   //RC0 =1 
	PORTC&=~0x01;   //RC0 =0 
	__delay_ms(100);

}


