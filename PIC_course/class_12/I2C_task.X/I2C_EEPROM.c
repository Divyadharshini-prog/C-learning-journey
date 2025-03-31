/*
 * File:   I2C_EEPROM.c
 * Author: D E L L
 *
 * Created on November 9, 2024, 1:19 AM
 */


#include <xc.h>
#include "I2C_EEPROM.h"

#define _XTAL_FREQ 16000000
#define EEPROM_Address_R 0xA1  // EEPROM address for read
#define EEPROM_Address_W 0xA0  // EEPROM address for write

// Initialize I2C Master with specified baud rate
void I2C_Master_Init(const unsigned long baud) {
    SSPCON = 0b00101000;
    SSPCON2 = 0;
    SSPADD = (_XTAL_FREQ / (4 * baud)) - 1;
    SSPSTAT = 0;
    TRISC3 = 1;  // Set SCL as input
    TRISC4 = 1;  // Set SDA as input
}

void I2C_Master_Wait(void) {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

// Generate start condition on I2C bus
void I2C_Master_Start(void) {
    I2C_Master_Wait();
    SEN = 1;
}

// Generate repeated start condition on I2C bus
void I2C_Master_RepeatedStart(void) {
    I2C_Master_Wait();
    RSEN = 1;
}

// Generate stop condition on I2C bus
void I2C_Master_Stop(void) {
    I2C_Master_Wait();
    PEN = 1;
}

// Write byte to I2C bus and return ACK status
unsigned char I2C_Master_Write(unsigned char data) {
    I2C_Master_Wait();
    SSPBUF = data;
    while (!SSPIF);
    SSPIF = 0;
    return ACKSTAT;
}

// Read byte from I2C bus
unsigned char I2C_Read_Byte(void) {
    I2C_Master_Wait();
    RCEN = 1;  // Enable reception
    while (!SSPIF);
    SSPIF = 0;
    I2C_Master_Wait();
    return SSPBUF;
}

// Send ACK on I2C bus
void I2C_ACK(void) {
    ACKDT = 0;  // ACK
    I2C_Master_Wait();
    ACKEN = 1;
}

// Send NACK on I2C bus
void I2C_NACK(void) {
    ACKDT = 1;  // NACK
    I2C_Master_Wait();
    ACKEN = 1;
}


void EEPROM_Write(unsigned int add, unsigned char data) {
    I2C_Master_Start();
    while (I2C_Master_Write(EEPROM_Address_W)) {
        I2C_Master_RepeatedStart();
    }
    I2C_Master_Write(add >> 8);          // High byte of address
    I2C_Master_Write((unsigned char)add); // Low byte of address
    I2C_Master_Write(data);
    I2C_Master_Stop();
}

unsigned char EEPROM_Read(unsigned int add) {
    unsigned char data;
    I2C_Master_Start();
    while (I2C_Master_Write(EEPROM_Address_W)) {
        I2C_Master_RepeatedStart();
    }
    I2C_Master_Write(add >> 8);          // High byte of address
    I2C_Master_Write((unsigned char)add); // Low byte of address
    I2C_Master_RepeatedStart();
    I2C_Master_Write(EEPROM_Address_R);   // Set EEPROM to read mode
    data = I2C_Read_Byte();
    I2C_NACK();                           // Send NACK after receiving data
    I2C_Master_Stop();
    return data;
}

