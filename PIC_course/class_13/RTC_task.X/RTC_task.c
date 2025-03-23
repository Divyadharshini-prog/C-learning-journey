// PIC16F877A Configuration Bit Settings

#pragma config FOSC = HS     // Oscillator Selection bits (High Speed Crystal)
#pragma config WDTE = OFF    // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON    // Power-up Timer Enable bit
#pragma config BOREN = ON    // Brown-out Reset Enable bit
#pragma config LVP = OFF     // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF     // Data EEPROM Memory Code Protection bit
#pragma config WRT = OFF     // Flash Program Memory Write Enable bits
#pragma config CP = OFF      // Flash Program Memory Code Protection bit

#include <xc.h>
#define _XTAL_FREQ 20000000  // 20 MHz Oscillator Frequency
#define RS RC2
#define EN RC1

// Function Prototypes
void init(void);
void i2c_init(const unsigned long);
void i2c_write(unsigned char);
int i2c_read(int);
void i2c_start(void);
void i2c_wait(void);
void i2c_stop(void);
void lcd_command(unsigned char);
void lcd_data(unsigned char);
int bcd_2_dec(int);
int dec_2_bcd(int);
void settime(void);
void update(void);

// Global Variables
char msg1[5] = {"TIME:"};
char msg2[5] = {"DATE:"};
int sec = 55, min = 59, hour = 11, date = 19, month = 11, year = 24; // Start with 19/11/2024
char am_pm = 1;  // 1 for PM, 0 for AM
char sec1, sec2, min1, min2, hour1, hour2, date1, date2, month1, month2, year1, year2;

#define RTC_ADDRESS_W 0xD0  // RTC I2C Write Address
#define RTC_ADDRESS_R 0xD1  // RTC I2C Read Address

void main() {
    init();
    i2c_init(100);  // Initialize I2C with 100 kHz
    settime();      // Set initial time and date to RTC

    while (1) {
        update();   // Update time and date
        sec1 = sec / 10;
        sec2 = sec % 10;
        min1 = min / 10;
        min2 = min % 10;
        hour1 = hour / 10;
        hour2 = hour % 10;
        date1 = date / 10;
        date2 = date % 10;
        month1 = month / 10;
        month2 = month % 10;
        year1 = year / 10;
        year2 = year % 10;

        // Display time on LCD
        lcd_command(0x80);
        for (int i = 0; i < 5; i++) lcd_data(msg1[i]);
        lcd_data(hour1 + '0');
        lcd_data(hour2 + '0');
        lcd_data(':');
        lcd_data(min1 + '0');
        lcd_data(min2 + '0');
        lcd_data(':');
        lcd_data(sec1 + '0');
        lcd_data(sec2 + '0');
        lcd_data(' ');
        lcd_data(am_pm ? 'P' : 'A');
        lcd_data('M');

        // Display date on LCD
        lcd_command(0xC0);
        for (int i = 0; i < 5; i++) lcd_data(msg2[i]);
        lcd_data(date1 + '0');
        lcd_data(date2 + '0');
        lcd_data('/');
        lcd_data(month1 + '0');
        lcd_data(month2 + '0');
        lcd_data('/');
        lcd_data(year1 + '0');
        lcd_data(year2 + '0');

        __delay_ms(500);
    }
}

void init(void) {
    TRISD = 0x00;  // PORTD as output for LCD
    TRISC = 0x18;  // RC3 (SCL) and RC4 (SDA) as input for I2C
    PORTD = 0x00;  // Clear PORTD
    lcd_command(0x38);  // Initialize LCD
    __delay_ms(5);
    lcd_command(0x0C);
    __delay_ms(5);
    lcd_command(0x06);
    __delay_ms(5);
    lcd_command(0x01);
    __delay_ms(5);
}

void lcd_command(unsigned char cmd) {
    RS = 0;        // Command mode
    PORTD = cmd;   // Send command to PORTD
    EN = 1;        // Enable pulse
    __delay_ms(1);
    EN = 0;
    __delay_ms(5);
}

void lcd_data(unsigned char data) {
    RS = 1;        // Data mode
    PORTD = data;  // Send data to PORTD
    EN = 1;        // Enable pulse
    __delay_ms(1);
    EN = 0;
    __delay_ms(5);
}

void i2c_init(const unsigned long freq_k) {
    SSPCON = 0x28;  // Enable I2C Master mode
    SSPSTAT = 0x00; // Clear status
    SSPADD = (_XTAL_FREQ / (4 * freq_k * 100)) - 1;  // Set baud rate
}

void i2c_wait(void) {
    while (SSPCON2 & 0x1F || SSPSTAT & 0x04);  // Wait until I2C is idle
}

void i2c_start(void) {
    i2c_wait();
    SEN = 1;  // Initiate start condition
}

void i2c_stop(void) {
    i2c_wait();
    PEN = 1;  // Initiate stop condition
}

void i2c_write(unsigned char data) {
    i2c_wait();
    SSPBUF = data;  // Load data into buffer
}

int i2c_read(int ack) {
    int value;
    i2c_wait();
    RCEN = 1;         // Enable reception
    i2c_wait();
    value = SSPBUF;   // Read received data
    i2c_wait();
    ACKDT = ack ? 0 : 1;  // 0 = ACK, 1 = NACK
    ACKEN = 1;        // Send ACK/NACK
    return value;
}

int dec_2_bcd(int val) {
    return ((val / 10) << 4) + (val % 10);
}

int bcd_2_dec(int val) {
    return ((val >> 4) * 10) + (val & 0x0F);
}

void settime(void) {
    i2c_start();
    i2c_write(RTC_ADDRESS_W);
    i2c_write(0x00);  // Set pointer to register 0x00
    i2c_write(dec_2_bcd(sec));
    i2c_write(dec_2_bcd(min));
    i2c_write(0x40 | dec_2_bcd(hour));  // 12-hour mode, PM
    i2c_write(1);                       // Day (ignored)
    i2c_write(dec_2_bcd(date));
    i2c_write(dec_2_bcd(month));
    i2c_write(dec_2_bcd(year));
    i2c_stop();
}

void update(void) {
    i2c_start();
    i2c_write(RTC_ADDRESS_W);
    i2c_write(0x00);  // Set pointer to register 0x00
    i2c_stop();

    i2c_start();
    i2c_write(RTC_ADDRESS_R);
    sec = bcd_2_dec(i2c_read(1));
    min = bcd_2_dec(i2c_read(1));
    hour = bcd_2_dec(i2c_read(1) & 0x1F);  // Mask to keep hour
    am_pm = (i2c_read(1) & 0x20) ? 1 : 0;  // PM bit
    date = bcd_2_dec(i2c_read(1));
    month = bcd_2_dec(i2c_read(1));
    year = bcd_2_dec(i2c_read(0));
    i2c_stop();

    // Handle transition from PM to AM and increment date
    if (hour == 12 && min == 0 && sec == 0) {
        if (am_pm) {  // PM to AM transition
            am_pm = 0;
            date++;
            if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) {
                date = 1;
                month++;
            } else if (month == 2 && ((year % 4 == 0 && date > 29) || (year % 4 != 0 && date > 28))) {
                date = 1;
                month++;
            } else if (date > 31) {
                date = 1;
                if (++month > 12) {
                    month = 1;
                    year++;
                }
            }
        } else {
            am_pm = 1;  // Switch to PM
        }
    }
}
