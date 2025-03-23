# 1 "task5_pwm.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "task5_pwm.c" 2
# 14 "task5_pwm.c"
#pragma config FOSC = EXTRC
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF





# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\xc.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\xc8debug.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdlib.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdlib.h" 2 3





# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\features.h" 1 3
# 11 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdlib.h" 2 3
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 128 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 174 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 210 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);



double atof (const char *);


float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);





unsigned long __strtoxl(const char * s, char ** endptr, int base, char is_signed);
# 55 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdlib.h" 3
int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);




typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;




div_t div (int, int);
ldiv_t ldiv (long, long);




typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\xc8debug.h" 2 3







#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 23 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\xc.h" 2 3

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\builtins.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 1 3
# 26 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 133 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef short intptr_t;
# 164 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 179 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int32_t;
# 192 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef int32_t intmax_t;







typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 215 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uint32_t;
# 233 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef uint32_t uintmax_t;
# 27 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3

typedef int8_t int_fast8_t;




typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;




typedef uint8_t uint_fast8_t;




typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\builtins.h" 2 3



#pragma intrinsic(__nop)
extern void __nop(void);
# 19 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\builtins.h" 3
#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(uint32_t);
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\xc.h" 2 3




# 1 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic.h" 1 3




# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\htc.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\xc.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\htc.h" 2 3
# 6 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic.h" 2 3



extern unsigned char __osccal_val(void);




# 1 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic_chip_select.h" 1 3
# 39 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic_chip_select.h" 3
# 1 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 1 3
# 44 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\__at.h" 1 3
# 45 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 2 3







extern volatile unsigned char INDF __attribute__((address(0x000)));

__asm("INDF equ 00h");




extern volatile unsigned char TMR0 __attribute__((address(0x001)));

__asm("TMR0 equ 01h");




extern volatile unsigned char PCL __attribute__((address(0x002)));

__asm("PCL equ 02h");




extern volatile unsigned char STATUS __attribute__((address(0x003)));

__asm("STATUS equ 03h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned RP :2;
        unsigned IRP :1;
    };
    struct {
        unsigned :5;
        unsigned RP0 :1;
        unsigned RP1 :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0x003)));
# 159 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char FSR __attribute__((address(0x004)));

__asm("FSR equ 04h");




extern volatile unsigned char PORTGPA __attribute__((address(0x005)));

__asm("PORTGPA equ 05h");


extern volatile unsigned char PORTA __attribute__((address(0x005)));

__asm("PORTA equ 05h");


typedef union {
    struct {
        unsigned GPA0 :1;
        unsigned GPA1 :1;
        unsigned GPA2 :1;
        unsigned GPA3 :1;
        unsigned GPA4 :1;
        unsigned GPA5 :1;
        unsigned GPA6 :1;
        unsigned GPA7 :1;
    };
    struct {
        unsigned GPIO0 :1;
        unsigned GPIO1 :1;
        unsigned GPIO2 :1;
        unsigned GPIO3 :1;
        unsigned GPIO4 :1;
        unsigned GPIO5 :1;
        unsigned GPIO6 :1;
        unsigned GPIO7 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
} PORTGPAbits_t;
extern volatile PORTGPAbits_t PORTGPAbits __attribute__((address(0x005)));
# 331 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
typedef union {
    struct {
        unsigned GPA0 :1;
        unsigned GPA1 :1;
        unsigned GPA2 :1;
        unsigned GPA3 :1;
        unsigned GPA4 :1;
        unsigned GPA5 :1;
        unsigned GPA6 :1;
        unsigned GPA7 :1;
    };
    struct {
        unsigned GPIO0 :1;
        unsigned GPIO1 :1;
        unsigned GPIO2 :1;
        unsigned GPIO3 :1;
        unsigned GPIO4 :1;
        unsigned GPIO5 :1;
        unsigned GPIO6 :1;
        unsigned GPIO7 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
} PORTAbits_t;
extern volatile PORTAbits_t PORTAbits __attribute__((address(0x005)));
# 488 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PORTGPB __attribute__((address(0x006)));

__asm("PORTGPB equ 06h");


extern volatile unsigned char PORTB __attribute__((address(0x006)));

__asm("PORTB equ 06h");


typedef union {
    struct {
        unsigned GPB0 :1;
        unsigned GPB1 :1;
        unsigned GPB2 :1;
    };
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
    };
} PORTGPBbits_t;
extern volatile PORTGPBbits_t PORTGPBbits __attribute__((address(0x006)));
# 543 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
typedef union {
    struct {
        unsigned GPB0 :1;
        unsigned GPB1 :1;
        unsigned GPB2 :1;
    };
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
    };
} PORTBbits_t;
extern volatile PORTBbits_t PORTBbits __attribute__((address(0x006)));
# 590 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PIR1 __attribute__((address(0x007)));

__asm("PIR1 equ 07h");


typedef union {
    struct {
        unsigned TMR1IF :1;
        unsigned TMR2IF :1;
        unsigned :2;
        unsigned SSPIF :1;
        unsigned BCLIF :1;
        unsigned ADIF :1;
    };
} PIR1bits_t;
extern volatile PIR1bits_t PIR1bits __attribute__((address(0x007)));
# 635 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PIR2 __attribute__((address(0x008)));

__asm("PIR2 equ 08h");


typedef union {
    struct {
        unsigned DCERIF :1;
        unsigned VINIF :1;
        unsigned :2;
        unsigned OVIF :1;
        unsigned OCIF :1;
        unsigned :1;
        unsigned UVIF :1;
    };
} PIR2bits_t;
extern volatile PIR2bits_t PIR2bits __attribute__((address(0x008)));
# 681 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PCON __attribute__((address(0x009)));

__asm("PCON equ 09h");


typedef union {
    struct {
        unsigned :1;
        unsigned nPOR :1;
        unsigned nOT :1;
    };
} PCONbits_t;
extern volatile PCONbits_t PCONbits __attribute__((address(0x009)));
# 708 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PCLATH __attribute__((address(0x00A)));

__asm("PCLATH equ 0Ah");




extern volatile unsigned char INTCON __attribute__((address(0x00B)));

__asm("INTCON equ 0Bh");


typedef union {
    struct {
        unsigned IOCF :1;
        unsigned INTF :1;
        unsigned T0IF :1;
        unsigned IOCE :1;
        unsigned INTE :1;
        unsigned T0IE :1;
        unsigned PEIE :1;
        unsigned GIE :1;
    };
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __attribute__((address(0x00B)));
# 777 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned short TMR1 __attribute__((address(0x00C)));

__asm("TMR1 equ 0Ch");




extern volatile unsigned char TMR1L __attribute__((address(0x00C)));

__asm("TMR1L equ 0Ch");




extern volatile unsigned char TMR1H __attribute__((address(0x00D)));

__asm("TMR1H equ 0Dh");




extern volatile unsigned char T1CON __attribute__((address(0x00E)));

__asm("T1CON equ 0Eh");


typedef union {
    struct {
        unsigned TMR1ON :1;
        unsigned TMR1CS :1;
        unsigned :2;
        unsigned T1CKPS :2;
    };
    struct {
        unsigned :4;
        unsigned T1CKPS0 :1;
        unsigned T1CKPS1 :1;
    };
} T1CONbits_t;
extern volatile T1CONbits_t T1CONbits __attribute__((address(0x00E)));
# 846 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char TMR2 __attribute__((address(0x00F)));

__asm("TMR2 equ 0Fh");




extern volatile unsigned char T2CON __attribute__((address(0x010)));

__asm("T2CON equ 010h");


typedef union {
    struct {
        unsigned T2CKPS :2;
        unsigned TMR2ON :1;
    };
} T2CONbits_t;
extern volatile T2CONbits_t T2CONbits __attribute__((address(0x010)));
# 879 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PR2 __attribute__((address(0x011)));

__asm("PR2 equ 011h");


typedef union {
    struct {
        unsigned PR2 :8;
    };
} PR2bits_t;
extern volatile PR2bits_t PR2bits __attribute__((address(0x011)));
# 899 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PWMPHL __attribute__((address(0x013)));

__asm("PWMPHL equ 013h");


typedef union {
    struct {
        unsigned PWMPHL :8;
    };
} PWMPHLbits_t;
extern volatile PWMPHLbits_t PWMPHLbits __attribute__((address(0x013)));
# 919 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PWMPHH __attribute__((address(0x014)));

__asm("PWMPHH equ 014h");


typedef union {
    struct {
        unsigned PWMPHH :8;
    };
} PWMPHHbits_t;
extern volatile PWMPHHbits_t PWMPHHbits __attribute__((address(0x014)));
# 939 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PWMRL __attribute__((address(0x015)));

__asm("PWMRL equ 015h");


typedef union {
    struct {
        unsigned PWMRL :8;
    };
} PWMRLbits_t;
extern volatile PWMRLbits_t PWMRLbits __attribute__((address(0x015)));
# 959 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PWMRH __attribute__((address(0x016)));

__asm("PWMRH equ 016h");


typedef union {
    struct {
        unsigned PWMRH :8;
    };
} PWMRHbits_t;
extern volatile PWMRHbits_t PWMRHbits __attribute__((address(0x016)));
# 979 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OVCCON __attribute__((address(0x019)));

__asm("OVCCON equ 019h");


typedef union {
    struct {
        unsigned OVC0 :1;
        unsigned OVC1 :1;
        unsigned OVC2 :1;
        unsigned OVC3 :1;
        unsigned OVC4 :1;
        unsigned OVC5 :1;
        unsigned OVC6 :1;
        unsigned OVC7 :1;
    };
} OVCCONbits_t;
extern volatile OVCCONbits_t OVCCONbits __attribute__((address(0x019)));
# 1041 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OVFCON __attribute__((address(0x01A)));

__asm("OVFCON equ 01Ah");


typedef union {
    struct {
        unsigned OVF :5;
        unsigned :2;
        unsigned VOUTON :1;
    };
    struct {
        unsigned OVF0 :1;
        unsigned OVF1 :1;
        unsigned OVF2 :1;
        unsigned OVF3 :1;
        unsigned OVF4 :1;
    };
} OVFCONbits_t;
extern volatile OVFCONbits_t OVFCONbits __attribute__((address(0x01A)));
# 1100 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OSCTUNE __attribute__((address(0x01B)));

__asm("OSCTUNE equ 01Bh");


typedef union {
    struct {
        unsigned TUN0 :1;
        unsigned TUN1 :1;
        unsigned TUN2 :1;
        unsigned TUN3 :1;
        unsigned TUN4 :1;
    };
} OSCTUNEbits_t;
extern volatile OSCTUNEbits_t OSCTUNEbits __attribute__((address(0x01B)));
# 1144 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned short ADRES __attribute__((address(0x01C)));

__asm("ADRES equ 01Ch");




extern volatile unsigned char ADRESL __attribute__((address(0x01C)));

__asm("ADRESL equ 01Ch");


typedef union {
    struct {
        unsigned ADRESL :8;
    };
} ADRESLbits_t;
extern volatile ADRESLbits_t ADRESLbits __attribute__((address(0x01C)));
# 1171 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ADRESH __attribute__((address(0x01D)));

__asm("ADRESH equ 01Dh");


typedef union {
    struct {
        unsigned ADRESH :8;
    };
} ADRESHbits_t;
extern volatile ADRESHbits_t ADRESHbits __attribute__((address(0x01D)));
# 1191 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ADCON0 __attribute__((address(0x01E)));

__asm("ADCON0 equ 01Eh");


typedef union {
    struct {
        unsigned ADON :1;
        unsigned GO_nDONE :1;
        unsigned CHS :5;
    };
    struct {
        unsigned :2;
        unsigned CHS0 :1;
        unsigned CHS1 :1;
        unsigned CHS2 :1;
        unsigned CHS3 :1;
        unsigned CHS4 :1;
    };
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __attribute__((address(0x01E)));
# 1256 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ADCON1 __attribute__((address(0x01F)));

__asm("ADCON1 equ 01Fh");


typedef union {
    struct {
        unsigned :4;
        unsigned ADCS :3;
    };
    struct {
        unsigned :4;
        unsigned ADCS0 :1;
        unsigned ADCS1 :1;
        unsigned ADCS2 :1;
    };
} ADCON1bits_t;
extern volatile ADCON1bits_t ADCON1bits __attribute__((address(0x01F)));
# 1298 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OPTION_REG __attribute__((address(0x081)));

__asm("OPTION_REG equ 081h");


typedef union {
    struct {
        unsigned PS :3;
        unsigned PSA :1;
        unsigned T0SE :1;
        unsigned T0CS :1;
        unsigned INTEDG :1;
        unsigned nRAPUI :1;
    };
    struct {
        unsigned PS0 :1;
        unsigned PS1 :1;
        unsigned PS2 :1;
    };
} OPTION_REGbits_t;
extern volatile OPTION_REGbits_t OPTION_REGbits __attribute__((address(0x081)));
# 1368 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char TRISGPA __attribute__((address(0x085)));

__asm("TRISGPA equ 085h");


extern volatile unsigned char TRISA __attribute__((address(0x085)));

__asm("TRISA equ 085h");


typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
        unsigned TRISA5 :1;
        unsigned TRISA6 :1;
        unsigned TRISA7 :1;
    };
} TRISGPAbits_t;
extern volatile TRISGPAbits_t TRISGPAbits __attribute__((address(0x085)));
# 1433 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
        unsigned TRISA5 :1;
        unsigned TRISA6 :1;
        unsigned TRISA7 :1;
    };
} TRISAbits_t;
extern volatile TRISAbits_t TRISAbits __attribute__((address(0x085)));
# 1490 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char TRISGPB __attribute__((address(0x086)));

__asm("TRISGPB equ 086h");


extern volatile unsigned char TRISB __attribute__((address(0x086)));

__asm("TRISB equ 086h");


typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
    };
} TRISGPBbits_t;
extern volatile TRISGPBbits_t TRISGPBbits __attribute__((address(0x086)));
# 1525 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
    };
} TRISBbits_t;
extern volatile TRISBbits_t TRISBbits __attribute__((address(0x086)));
# 1552 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PIE1 __attribute__((address(0x087)));

__asm("PIE1 equ 087h");


typedef union {
    struct {
        unsigned TMR1IE :1;
        unsigned TMR2IE :1;
        unsigned :2;
        unsigned SSPIE :1;
        unsigned BCLIE :1;
        unsigned ADIE :1;
    };
} PIE1bits_t;
extern volatile PIE1bits_t PIE1bits __attribute__((address(0x087)));
# 1597 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PIE2 __attribute__((address(0x088)));

__asm("PIE2 equ 088h");


typedef union {
    struct {
        unsigned DCERIE :1;
        unsigned VINIE :1;
        unsigned :2;
        unsigned OVIE :1;
        unsigned OCIE :1;
        unsigned :1;
        unsigned UVIE :1;
    };
} PIE2bits_t;
extern volatile PIE2bits_t PIE2bits __attribute__((address(0x088)));
# 1643 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char APFCON __attribute__((address(0x089)));

__asm("APFCON equ 089h");


typedef union {
    struct {
        unsigned CLKSEL :1;
    };
} APFCONbits_t;
extern volatile APFCONbits_t APFCONbits __attribute__((address(0x089)));
# 1663 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char VINLVL __attribute__((address(0x090)));

__asm("VINLVL equ 090h");


typedef union {
    struct {
        unsigned UVLO :6;
        unsigned :1;
        unsigned UVLOEN :1;
    };
    struct {
        unsigned UVLO0 :1;
        unsigned UVLO1 :1;
        unsigned UVLO2 :1;
        unsigned UVLO3 :1;
        unsigned UVLO4 :1;
        unsigned UVLO5 :1;
    };
} VINLVLbits_t;
extern volatile VINLVLbits_t VINLVLbits __attribute__((address(0x090)));
# 1728 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OCCON __attribute__((address(0x091)));

__asm("OCCON equ 091h");


typedef union {
    struct {
        unsigned OOC :5;
        unsigned OCLEB :2;
        unsigned OCEN :1;
    };
    struct {
        unsigned OOC0 :1;
        unsigned OOC1 :1;
        unsigned OOC2 :1;
        unsigned OOC3 :1;
        unsigned OOC4 :1;
        unsigned OCLEB0 :1;
        unsigned OCLEB1 :1;
    };
} OCCONbits_t;
extern volatile OCCONbits_t OCCONbits __attribute__((address(0x091)));
# 1804 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char CSGSCON __attribute__((address(0x093)));

__asm("CSGSCON equ 093h");


typedef union {
    struct {
        unsigned CSGS :4;
    };
    struct {
        unsigned CSGS0 :1;
        unsigned CSGS1 :1;
        unsigned CSGS2 :1;
        unsigned CSGS3 :1;
    };
} CSGSCONbits_t;
extern volatile CSGSCONbits_t CSGSCONbits __attribute__((address(0x093)));
# 1850 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char CSDGCON __attribute__((address(0x095)));

__asm("CSDGCON equ 095h");


typedef union {
    struct {
        unsigned CSDG :3;
        unsigned :4;
        unsigned CSDGEN :1;
    };
    struct {
        unsigned CSDG0 :1;
        unsigned CSDG1 :1;
        unsigned CSDG2 :1;
    };
} CSDGCONbits_t;
extern volatile CSDGCONbits_t CSDGCONbits __attribute__((address(0x095)));
# 1897 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char VZCCON __attribute__((address(0x097)));

__asm("VZCCON equ 097h");


typedef union {
    struct {
        unsigned VZC0 :1;
        unsigned VZC1 :1;
        unsigned VZC2 :1;
        unsigned VZC3 :1;
        unsigned VZC4 :1;
        unsigned VZC5 :1;
        unsigned VZC6 :1;
        unsigned VZC7 :1;
    };
} VZCCONbits_t;
extern volatile VZCCONbits_t VZCCONbits __attribute__((address(0x097)));
# 1959 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char CMPZCON __attribute__((address(0x098)));

__asm("CMPZCON equ 098h");


typedef union {
    struct {
        unsigned CMPZG :4;
        unsigned CMPZF :4;
    };
    struct {
        unsigned CMPZG0 :1;
        unsigned CMPZG1 :1;
        unsigned CMPZG2 :1;
        unsigned CMPZG3 :1;
        unsigned CMPZF0 :1;
        unsigned CMPZF1 :1;
        unsigned CMPZF2 :1;
        unsigned CMPZF3 :1;
    };
} CMPZCONbits_t;
extern volatile CMPZCONbits_t CMPZCONbits __attribute__((address(0x098)));
# 2035 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OUVCON __attribute__((address(0x099)));

__asm("OUVCON equ 099h");


typedef union {
    struct {
        unsigned OUV0 :1;
        unsigned OUV1 :1;
        unsigned OUV2 :1;
        unsigned OUV3 :1;
        unsigned OUV4 :1;
        unsigned OUV5 :1;
        unsigned OUV6 :1;
        unsigned OUV7 :1;
    };
} OUVCONbits_t;
extern volatile OUVCONbits_t OUVCONbits __attribute__((address(0x099)));
# 2097 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OOVCON __attribute__((address(0x09A)));

__asm("OOVCON equ 09Ah");


typedef union {
    struct {
        unsigned OOV0 :1;
        unsigned OOV1 :1;
        unsigned OOV2 :1;
        unsigned OOV3 :1;
        unsigned OOV4 :1;
        unsigned OOV5 :1;
        unsigned OOV6 :1;
        unsigned OOV7 :1;
    };
} OOVCONbits_t;
extern volatile OOVCONbits_t OOVCONbits __attribute__((address(0x09A)));
# 2159 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char DEADCON __attribute__((address(0x09B)));

__asm("DEADCON equ 09Bh");


typedef union {
    struct {
        unsigned LDLY :4;
        unsigned HDLY :4;
    };
    struct {
        unsigned LDLY0 :1;
        unsigned LDLY1 :1;
        unsigned LDLY2 :1;
        unsigned LDLY3 :1;
        unsigned HDLY0 :1;
        unsigned HDLY1 :1;
        unsigned HDLY2 :1;
        unsigned HDLY3 :1;
    };
} DEADCONbits_t;
extern volatile DEADCONbits_t DEADCONbits __attribute__((address(0x09B)));
# 2235 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SLPCRCON __attribute__((address(0x09C)));

__asm("SLPCRCON equ 09Ch");


typedef union {
    struct {
        unsigned SLPS :4;
        unsigned SLPG :4;
    };
    struct {
        unsigned SLPS0 :1;
        unsigned SLPS1 :1;
        unsigned SLPS2 :1;
        unsigned SLPS3 :1;
        unsigned SLPG0 :1;
        unsigned SLPG1 :1;
        unsigned SLPG2 :1;
        unsigned SLPG3 :1;
    };
} SLPCRCONbits_t;
extern volatile SLPCRCONbits_t SLPCRCONbits __attribute__((address(0x09C)));
# 2311 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SLVGNCON __attribute__((address(0x09D)));

__asm("SLVGNCON equ 09Dh");


typedef union {
    struct {
        unsigned SLVGN :5;
    };
    struct {
        unsigned SLVGN0 :1;
        unsigned SLVGN1 :1;
        unsigned SLVGN2 :1;
        unsigned SLVGN3 :1;
        unsigned SLVGN4 :1;
    };
} SLVGNCONbits_t;
extern volatile SLVGNCONbits_t SLVGNCONbits __attribute__((address(0x09D)));
# 2363 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char RELEFF __attribute__((address(0x09E)));

__asm("RELEFF equ 09Eh");


typedef union {
    struct {
        unsigned RE :7;
        unsigned MSDONE :1;
    };
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
        unsigned RE4 :1;
        unsigned RE5 :1;
        unsigned RE6 :1;
    };
} RELEFFbits_t;
extern volatile RELEFFbits_t RELEFFbits __attribute__((address(0x09E)));
# 2433 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char WPUGPA __attribute__((address(0x105)));

__asm("WPUGPA equ 0105h");


typedef union {
    struct {
        unsigned WPUGPA0 :1;
        unsigned WPUGPA1 :1;
        unsigned WPUGPA2 :1;
        unsigned WPUGPA3 :1;
        unsigned :1;
        unsigned WPUGPA5 :1;
    };
    struct {
        unsigned WPUA0 :1;
        unsigned WPUA1 :1;
        unsigned WPUA2 :1;
        unsigned WPUA3 :1;
        unsigned :1;
        unsigned WPUA5 :1;
    };
} WPUGPAbits_t;
extern volatile WPUGPAbits_t WPUGPAbits __attribute__((address(0x105)));
# 2511 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char WPUGPB __attribute__((address(0x106)));

__asm("WPUGPB equ 0106h");


typedef union {
    struct {
        unsigned :1;
        unsigned WPUGPB1 :1;
        unsigned WPUGPB2 :1;
    };
    struct {
        unsigned :1;
        unsigned WPUB1 :1;
        unsigned WPUB2 :1;
    };
} WPUGPBbits_t;
extern volatile WPUGPBbits_t WPUGPBbits __attribute__((address(0x106)));
# 2553 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PE1 __attribute__((address(0x107)));

__asm("PE1 equ 0107h");


typedef union {
    struct {
        unsigned OVTEE :1;
        unsigned UVTEE :1;
        unsigned PUEN :1;
        unsigned PDEN :1;
        unsigned LDLYBY :1;
        unsigned HDLYBY :1;
        unsigned DVRSTR :1;
        unsigned DECON :1;
    };
} PE1bits_t;
extern volatile PE1bits_t PE1bits __attribute__((address(0x107)));
# 2615 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char BUFFCON __attribute__((address(0x108)));

__asm("BUFFCON equ 0108h");


typedef union {
    struct {
        unsigned ASEL :5;
        unsigned MLTPH :3;
    };
    struct {
        unsigned ASEL0 :1;
        unsigned ASEL1 :1;
        unsigned ASEL2 :1;
        unsigned ASEL3 :1;
        unsigned ASEL4 :1;
        unsigned MLTPH0 :1;
        unsigned MLTPH1 :1;
        unsigned MLTPH2 :1;
    };
} BUFFCONbits_t;
extern volatile BUFFCONbits_t BUFFCONbits __attribute__((address(0x108)));
# 2691 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ABECON __attribute__((address(0x109)));

__asm("ABECON equ 0109h");


typedef union {
    struct {
        unsigned PATHEN :1;
        unsigned RECIREN :1;
        unsigned TMPSEN :1;
        unsigned CRTMEN :1;
        unsigned SLCPBY :1;
        unsigned MEASEN :1;
        unsigned UVDCEN :1;
        unsigned OVDCEN :1;
    };
} ABECONbits_t;
extern volatile ABECONbits_t ABECONbits __attribute__((address(0x109)));
# 2753 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPADD __attribute__((address(0x110)));

__asm("SSPADD equ 0110h");


typedef union {
    struct {
        unsigned ADD :8;
    };
} SSPADDbits_t;
extern volatile SSPADDbits_t SSPADDbits __attribute__((address(0x110)));
# 2773 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPBUF __attribute__((address(0x111)));

__asm("SSPBUF equ 0111h");


typedef union {
    struct {
        unsigned SSPBUF :8;
    };
} SSPBUFbits_t;
extern volatile SSPBUFbits_t SSPBUFbits __attribute__((address(0x111)));
# 2793 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPCON1 __attribute__((address(0x112)));

__asm("SSPCON1 equ 0112h");


typedef union {
    struct {
        unsigned SSPM :4;
        unsigned CKP :1;
        unsigned SSPEN :1;
        unsigned SSPOV :1;
        unsigned WCOL :1;
    };
    struct {
        unsigned SSPM0 :1;
        unsigned SSPM1 :1;
        unsigned SSPM2 :1;
        unsigned SSPM3 :1;
    };
} SSPCON1bits_t;
extern volatile SSPCON1bits_t SSPCON1bits __attribute__((address(0x112)));
# 2863 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPCON2 __attribute__((address(0x113)));

__asm("SSPCON2 equ 0113h");


typedef union {
    struct {
        unsigned SEN :1;
        unsigned RSEN :1;
        unsigned PEN :1;
        unsigned RCEN :1;
        unsigned ACKEN :1;
        unsigned ACKDT :1;
        unsigned ACKSTAT :1;
        unsigned GCEN :1;
    };
} SSPCON2bits_t;
extern volatile SSPCON2bits_t SSPCON2bits __attribute__((address(0x113)));
# 2925 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPCON3 __attribute__((address(0x114)));

__asm("SSPCON3 equ 0114h");


typedef union {
    struct {
        unsigned DHEN :1;
        unsigned AHEN :1;
        unsigned SBCDE :1;
        unsigned SDAHT :1;
        unsigned BOEN :1;
        unsigned SCIE :1;
        unsigned PCIE :1;
        unsigned ACKTIM :1;
    };
} SSPCON3bits_t;
extern volatile SSPCON3bits_t SSPCON3bits __attribute__((address(0x114)));
# 2987 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPMSK __attribute__((address(0x115)));

__asm("SSPMSK equ 0115h");


typedef union {
    struct {
        unsigned MSK :8;
    };
} SSPMSKbits_t;
extern volatile SSPMSKbits_t SSPMSKbits __attribute__((address(0x115)));
# 3007 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPSTAT __attribute__((address(0x116)));

__asm("SSPSTAT equ 0116h");


typedef union {
    struct {
        unsigned BF :1;
        unsigned UA :1;
        unsigned R_nW :1;
        unsigned S :1;
        unsigned P :1;
        unsigned D_nA :1;
        unsigned CKE :1;
        unsigned SMP :1;
    };
} SSPSTATbits_t;
extern volatile SSPSTATbits_t SSPSTATbits __attribute__((address(0x116)));
# 3069 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPADD2 __attribute__((address(0x117)));

__asm("SSPADD2 equ 0117h");


typedef union {
    struct {
        unsigned ADD2 :8;
    };
} SSPADD2bits_t;
extern volatile SSPADD2bits_t SSPADD2bits __attribute__((address(0x117)));
# 3089 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char SSPMSK2 __attribute__((address(0x118)));

__asm("SSPMSK2 equ 0118h");


typedef union {
    struct {
        unsigned MSK2 :8;
    };
} SSPMSK2bits_t;
extern volatile SSPMSK2bits_t SSPMSK2bits __attribute__((address(0x118)));
# 3109 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char IOCA __attribute__((address(0x185)));

__asm("IOCA equ 0185h");


typedef union {
    struct {
        unsigned IOCA0 :1;
        unsigned IOCA1 :1;
        unsigned IOCA2 :1;
        unsigned IOCA3 :1;
        unsigned IOCA4 :1;
        unsigned IOCA5 :1;
        unsigned IOCA6 :1;
        unsigned IOCA7 :1;
    };
} IOCAbits_t;
extern volatile IOCAbits_t IOCAbits __attribute__((address(0x185)));
# 3171 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char IOCB __attribute__((address(0x186)));

__asm("IOCB equ 0186h");


typedef union {
    struct {
        unsigned IOCB0 :1;
        unsigned IOCB1 :1;
        unsigned IOCB2 :1;
    };
} IOCBbits_t;
extern volatile IOCBbits_t IOCBbits __attribute__((address(0x186)));
# 3203 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ANSELA __attribute__((address(0x187)));

__asm("ANSELA equ 0187h");


typedef union {
    struct {
        unsigned ANSA0 :1;
        unsigned ANSA1 :1;
        unsigned ANSA2 :1;
        unsigned ANSA3 :1;
    };
} ANSELAbits_t;
extern volatile ANSELAbits_t ANSELAbits __attribute__((address(0x187)));
# 3241 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ANSELB __attribute__((address(0x188)));

__asm("ANSELB equ 0188h");


typedef union {
    struct {
        unsigned :1;
        unsigned ANSB1 :1;
        unsigned ANSB2 :1;
    };
} ANSELBbits_t;
extern volatile ANSELBbits_t ANSELBbits __attribute__((address(0x188)));
# 3268 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PMCON1 __attribute__((address(0x190)));

__asm("PMCON1 equ 0190h");


typedef union {
    struct {
        unsigned RD :1;
        unsigned WR :1;
        unsigned WREN :1;
        unsigned :3;
        unsigned CALSEL :1;
    };
} PMCON1bits_t;
extern volatile PMCON1bits_t PMCON1bits __attribute__((address(0x190)));
# 3307 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PMCON2 __attribute__((address(0x191)));

__asm("PMCON2 equ 0191h");


typedef union {
    struct {
        unsigned PMCON2 :8;
    };
} PMCON2bits_t;
extern volatile PMCON2bits_t PMCON2bits __attribute__((address(0x191)));
# 3327 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned short PMADR __attribute__((address(0x192)));

__asm("PMADR equ 0192h");




extern volatile unsigned char PMADRL __attribute__((address(0x192)));

__asm("PMADRL equ 0192h");


typedef union {
    struct {
        unsigned PMADRL :8;
    };
    struct {
        unsigned PMADRL0 :1;
        unsigned PMADRL1 :1;
        unsigned PMADRL2 :1;
        unsigned PMADRL3 :1;
        unsigned PMADRL4 :1;
        unsigned PMADRL5 :1;
        unsigned PMADRL6 :1;
        unsigned PMADRL7 :1;
    };
} PMADRLbits_t;
extern volatile PMADRLbits_t PMADRLbits __attribute__((address(0x192)));
# 3404 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PMADRH __attribute__((address(0x193)));

__asm("PMADRH equ 0193h");


typedef union {
    struct {
        unsigned PMADRH :4;
    };
    struct {
        unsigned PMADRH0 :1;
        unsigned PMADRH1 :1;
        unsigned PMADRH2 :1;
        unsigned PMADRH3 :1;
    };
} PMADRHbits_t;
extern volatile PMADRHbits_t PMADRHbits __attribute__((address(0x193)));
# 3450 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned short PMDAT __attribute__((address(0x194)));

__asm("PMDAT equ 0194h");




extern volatile unsigned char PMDATL __attribute__((address(0x194)));

__asm("PMDATL equ 0194h");


typedef union {
    struct {
        unsigned PMDATL :8;
    };
    struct {
        unsigned PMDATL0 :1;
        unsigned PMDATL1 :1;
        unsigned PMDATL2 :1;
        unsigned PMDATL3 :1;
        unsigned PMDATL4 :1;
        unsigned PMDATL5 :1;
        unsigned PMDATL6 :1;
        unsigned PMDATL7 :1;
    };
} PMDATLbits_t;
extern volatile PMDATLbits_t PMDATLbits __attribute__((address(0x194)));
# 3527 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char PMDATH __attribute__((address(0x195)));

__asm("PMDATH equ 0195h");


typedef union {
    struct {
        unsigned PMDATH :6;
    };
    struct {
        unsigned PMDATH0 :1;
        unsigned PMDATH1 :1;
        unsigned PMDATH2 :1;
        unsigned PMDATH3 :1;
        unsigned PMDATH4 :1;
        unsigned PMDATH5 :1;
        unsigned PMDATH6 :1;
        unsigned PMDATH7 :1;
    };
} PMDATHbits_t;
extern volatile PMDATHbits_t PMDATHbits __attribute__((address(0x195)));
# 3597 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char OSCCAL __attribute__((address(0x198)));

__asm("OSCCAL equ 0198h");


typedef union {
    struct {
        unsigned FCALT0 :1;
        unsigned FCALT1 :1;
        unsigned FCALT2 :1;
        unsigned FCALT3 :1;
        unsigned FCALT4 :1;
        unsigned FCALT5 :1;
        unsigned FCALT6 :1;
    };
} OSCCALbits_t;
extern volatile OSCCALbits_t OSCCALbits __attribute__((address(0x198)));
# 3653 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char DOVCAL __attribute__((address(0x199)));

__asm("DOVCAL equ 0199h");


typedef union {
    struct {
        unsigned DOVT0 :1;
        unsigned DOVT1 :1;
        unsigned DOVT2 :1;
        unsigned DOVT3 :1;
    };
} DOVCALbits_t;
extern volatile DOVCALbits_t DOVCALbits __attribute__((address(0x199)));
# 3691 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char TTACAL __attribute__((address(0x19A)));

__asm("TTACAL equ 019Ah");


typedef union {
    struct {
        unsigned TTA0 :1;
        unsigned TTA1 :1;
        unsigned TTA2 :1;
        unsigned TTA3 :1;
    };
} TTACALbits_t;
extern volatile TTACALbits_t TTACALbits __attribute__((address(0x19A)));
# 3729 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char BGRCAL __attribute__((address(0x19B)));

__asm("BGRCAL equ 019Bh");


typedef union {
    struct {
        unsigned BGRT0 :1;
        unsigned BGRT1 :1;
        unsigned BGRT2 :1;
        unsigned BGRT3 :1;
    };
} BGRCALbits_t;
extern volatile BGRCALbits_t BGRCALbits __attribute__((address(0x19B)));
# 3767 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char VROCAL __attribute__((address(0x19C)));

__asm("VROCAL equ 019Ch");


typedef union {
    struct {
        unsigned VROT0 :1;
        unsigned VROT1 :1;
        unsigned VROT2 :1;
        unsigned VROT3 :1;
    };
} VROCALbits_t;
extern volatile VROCALbits_t VROCALbits __attribute__((address(0x19C)));
# 3805 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ZROCAL __attribute__((address(0x19D)));

__asm("ZROCAL equ 019Dh");


typedef union {
    struct {
        unsigned ZROT0 :1;
        unsigned ZROT1 :1;
        unsigned ZROT2 :1;
        unsigned ZROT3 :1;
    };
} ZROCALbits_t;
extern volatile ZROCALbits_t ZROCALbits __attribute__((address(0x19D)));
# 3843 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile unsigned char ATSTCON __attribute__((address(0x19F)));

__asm("ATSTCON equ 019Fh");


typedef union {
    struct {
        unsigned DRVDIS :1;
        unsigned BNCHEN :1;
        unsigned LODIS :1;
        unsigned HIDIS :1;
    };
} ATSTCONbits_t;
extern volatile ATSTCONbits_t ATSTCONbits __attribute__((address(0x19F)));
# 3891 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\proc\\mcp19110.h" 3
extern volatile __bit ACKDT __attribute__((address(0x89D)));


extern volatile __bit ACKEN __attribute__((address(0x89C)));


extern volatile __bit ACKSTAT __attribute__((address(0x89E)));


extern volatile __bit ACKTIM __attribute__((address(0x8A7)));


extern volatile __bit ADCS0 __attribute__((address(0xFC)));


extern volatile __bit ADCS1 __attribute__((address(0xFD)));


extern volatile __bit ADCS2 __attribute__((address(0xFE)));


extern volatile __bit ADIE __attribute__((address(0x43E)));


extern volatile __bit ADIF __attribute__((address(0x3E)));


extern volatile __bit ADON __attribute__((address(0xF0)));


extern volatile __bit AHEN __attribute__((address(0x8A1)));


extern volatile __bit ANSA0 __attribute__((address(0xC38)));


extern volatile __bit ANSA1 __attribute__((address(0xC39)));


extern volatile __bit ANSA2 __attribute__((address(0xC3A)));


extern volatile __bit ANSA3 __attribute__((address(0xC3B)));


extern volatile __bit ANSB1 __attribute__((address(0xC41)));


extern volatile __bit ANSB2 __attribute__((address(0xC42)));


extern volatile __bit ASEL0 __attribute__((address(0x840)));


extern volatile __bit ASEL1 __attribute__((address(0x841)));


extern volatile __bit ASEL2 __attribute__((address(0x842)));


extern volatile __bit ASEL3 __attribute__((address(0x843)));


extern volatile __bit ASEL4 __attribute__((address(0x844)));


extern volatile __bit BCLIE __attribute__((address(0x43D)));


extern volatile __bit BCLIF __attribute__((address(0x3D)));


extern volatile __bit BF __attribute__((address(0x8B0)));


extern volatile __bit BGRT0 __attribute__((address(0xCD8)));


extern volatile __bit BGRT1 __attribute__((address(0xCD9)));


extern volatile __bit BGRT2 __attribute__((address(0xCDA)));


extern volatile __bit BGRT3 __attribute__((address(0xCDB)));


extern volatile __bit BNCHEN __attribute__((address(0xCF9)));


extern volatile __bit BOEN __attribute__((address(0x8A4)));


extern volatile __bit CALSEL __attribute__((address(0xC86)));


extern volatile __bit CARRY __attribute__((address(0x18)));


extern volatile __bit CHS0 __attribute__((address(0xF2)));


extern volatile __bit CHS1 __attribute__((address(0xF3)));


extern volatile __bit CHS2 __attribute__((address(0xF4)));


extern volatile __bit CHS3 __attribute__((address(0xF5)));


extern volatile __bit CHS4 __attribute__((address(0xF6)));


extern volatile __bit CKE __attribute__((address(0x8B6)));


extern volatile __bit CKP __attribute__((address(0x894)));


extern volatile __bit CLKSEL __attribute__((address(0x448)));


extern volatile __bit CMPZF0 __attribute__((address(0x4C4)));


extern volatile __bit CMPZF1 __attribute__((address(0x4C5)));


extern volatile __bit CMPZF2 __attribute__((address(0x4C6)));


extern volatile __bit CMPZF3 __attribute__((address(0x4C7)));


extern volatile __bit CMPZG0 __attribute__((address(0x4C0)));


extern volatile __bit CMPZG1 __attribute__((address(0x4C1)));


extern volatile __bit CMPZG2 __attribute__((address(0x4C2)));


extern volatile __bit CMPZG3 __attribute__((address(0x4C3)));


extern volatile __bit CRTMEN __attribute__((address(0x84B)));


extern volatile __bit CSDG0 __attribute__((address(0x4A8)));


extern volatile __bit CSDG1 __attribute__((address(0x4A9)));


extern volatile __bit CSDG2 __attribute__((address(0x4AA)));


extern volatile __bit CSDGEN __attribute__((address(0x4AF)));


extern volatile __bit CSGS0 __attribute__((address(0x498)));


extern volatile __bit CSGS1 __attribute__((address(0x499)));


extern volatile __bit CSGS2 __attribute__((address(0x49A)));


extern volatile __bit CSGS3 __attribute__((address(0x49B)));


extern volatile __bit DC __attribute__((address(0x19)));


extern volatile __bit DCERIE __attribute__((address(0x440)));


extern volatile __bit DCERIF __attribute__((address(0x40)));


extern volatile __bit DECON __attribute__((address(0x83F)));


extern volatile __bit DHEN __attribute__((address(0x8A0)));


extern volatile __bit DOVT0 __attribute__((address(0xCC8)));


extern volatile __bit DOVT1 __attribute__((address(0xCC9)));


extern volatile __bit DOVT2 __attribute__((address(0xCCA)));


extern volatile __bit DOVT3 __attribute__((address(0xCCB)));


extern volatile __bit DRVDIS __attribute__((address(0xCF8)));


extern volatile __bit DVRSTR __attribute__((address(0x83E)));


extern volatile __bit D_nA __attribute__((address(0x8B5)));


extern volatile __bit FCALT0 __attribute__((address(0xCC0)));


extern volatile __bit FCALT1 __attribute__((address(0xCC1)));


extern volatile __bit FCALT2 __attribute__((address(0xCC2)));


extern volatile __bit FCALT3 __attribute__((address(0xCC3)));


extern volatile __bit FCALT4 __attribute__((address(0xCC4)));


extern volatile __bit FCALT5 __attribute__((address(0xCC5)));


extern volatile __bit FCALT6 __attribute__((address(0xCC6)));


extern volatile __bit GCEN __attribute__((address(0x89F)));


extern volatile __bit GIE __attribute__((address(0x5F)));


extern volatile __bit GO_nDONE __attribute__((address(0xF1)));


extern volatile __bit GPA0 __attribute__((address(0x28)));


extern volatile __bit GPA1 __attribute__((address(0x29)));


extern volatile __bit GPA2 __attribute__((address(0x2A)));


extern volatile __bit GPA3 __attribute__((address(0x2B)));


extern volatile __bit GPA4 __attribute__((address(0x2C)));


extern volatile __bit GPA5 __attribute__((address(0x2D)));


extern volatile __bit GPA6 __attribute__((address(0x2E)));


extern volatile __bit GPA7 __attribute__((address(0x2F)));


extern volatile __bit GPB0 __attribute__((address(0x30)));


extern volatile __bit GPB1 __attribute__((address(0x31)));


extern volatile __bit GPB2 __attribute__((address(0x32)));


extern volatile __bit GPIO0 __attribute__((address(0x28)));


extern volatile __bit GPIO1 __attribute__((address(0x29)));


extern volatile __bit GPIO2 __attribute__((address(0x2A)));


extern volatile __bit GPIO3 __attribute__((address(0x2B)));


extern volatile __bit GPIO4 __attribute__((address(0x2C)));


extern volatile __bit GPIO5 __attribute__((address(0x2D)));


extern volatile __bit GPIO6 __attribute__((address(0x2E)));


extern volatile __bit GPIO7 __attribute__((address(0x2F)));


extern volatile __bit HDLY0 __attribute__((address(0x4DC)));


extern volatile __bit HDLY1 __attribute__((address(0x4DD)));


extern volatile __bit HDLY2 __attribute__((address(0x4DE)));


extern volatile __bit HDLY3 __attribute__((address(0x4DF)));


extern volatile __bit HDLYBY __attribute__((address(0x83D)));


extern volatile __bit HIDIS __attribute__((address(0xCFB)));


extern volatile __bit INTE __attribute__((address(0x5C)));


extern volatile __bit INTEDG __attribute__((address(0x40E)));


extern volatile __bit INTF __attribute__((address(0x59)));


extern volatile __bit IOCA0 __attribute__((address(0xC28)));


extern volatile __bit IOCA1 __attribute__((address(0xC29)));


extern volatile __bit IOCA2 __attribute__((address(0xC2A)));


extern volatile __bit IOCA3 __attribute__((address(0xC2B)));


extern volatile __bit IOCA4 __attribute__((address(0xC2C)));


extern volatile __bit IOCA5 __attribute__((address(0xC2D)));


extern volatile __bit IOCA6 __attribute__((address(0xC2E)));


extern volatile __bit IOCA7 __attribute__((address(0xC2F)));


extern volatile __bit IOCB0 __attribute__((address(0xC30)));


extern volatile __bit IOCB1 __attribute__((address(0xC31)));


extern volatile __bit IOCB2 __attribute__((address(0xC32)));


extern volatile __bit IOCE __attribute__((address(0x5B)));


extern volatile __bit IOCF __attribute__((address(0x58)));


extern volatile __bit IRP __attribute__((address(0x1F)));


extern volatile __bit LDLY0 __attribute__((address(0x4D8)));


extern volatile __bit LDLY1 __attribute__((address(0x4D9)));


extern volatile __bit LDLY2 __attribute__((address(0x4DA)));


extern volatile __bit LDLY3 __attribute__((address(0x4DB)));


extern volatile __bit LDLYBY __attribute__((address(0x83C)));


extern volatile __bit LODIS __attribute__((address(0xCFA)));


extern volatile __bit MEASEN __attribute__((address(0x84D)));


extern volatile __bit MLTPH0 __attribute__((address(0x845)));


extern volatile __bit MLTPH1 __attribute__((address(0x846)));


extern volatile __bit MLTPH2 __attribute__((address(0x847)));


extern volatile __bit MSDONE __attribute__((address(0x4F7)));


extern volatile __bit OCEN __attribute__((address(0x48F)));


extern volatile __bit OCIE __attribute__((address(0x445)));


extern volatile __bit OCIF __attribute__((address(0x45)));


extern volatile __bit OCLEB0 __attribute__((address(0x48D)));


extern volatile __bit OCLEB1 __attribute__((address(0x48E)));


extern volatile __bit OOC0 __attribute__((address(0x488)));


extern volatile __bit OOC1 __attribute__((address(0x489)));


extern volatile __bit OOC2 __attribute__((address(0x48A)));


extern volatile __bit OOC3 __attribute__((address(0x48B)));


extern volatile __bit OOC4 __attribute__((address(0x48C)));


extern volatile __bit OOV0 __attribute__((address(0x4D0)));


extern volatile __bit OOV1 __attribute__((address(0x4D1)));


extern volatile __bit OOV2 __attribute__((address(0x4D2)));


extern volatile __bit OOV3 __attribute__((address(0x4D3)));


extern volatile __bit OOV4 __attribute__((address(0x4D4)));


extern volatile __bit OOV5 __attribute__((address(0x4D5)));


extern volatile __bit OOV6 __attribute__((address(0x4D6)));


extern volatile __bit OOV7 __attribute__((address(0x4D7)));


extern volatile __bit OUV0 __attribute__((address(0x4C8)));


extern volatile __bit OUV1 __attribute__((address(0x4C9)));


extern volatile __bit OUV2 __attribute__((address(0x4CA)));


extern volatile __bit OUV3 __attribute__((address(0x4CB)));


extern volatile __bit OUV4 __attribute__((address(0x4CC)));


extern volatile __bit OUV5 __attribute__((address(0x4CD)));


extern volatile __bit OUV6 __attribute__((address(0x4CE)));


extern volatile __bit OUV7 __attribute__((address(0x4CF)));


extern volatile __bit OVC0 __attribute__((address(0xC8)));


extern volatile __bit OVC1 __attribute__((address(0xC9)));


extern volatile __bit OVC2 __attribute__((address(0xCA)));


extern volatile __bit OVC3 __attribute__((address(0xCB)));


extern volatile __bit OVC4 __attribute__((address(0xCC)));


extern volatile __bit OVC5 __attribute__((address(0xCD)));


extern volatile __bit OVC6 __attribute__((address(0xCE)));


extern volatile __bit OVC7 __attribute__((address(0xCF)));


extern volatile __bit OVDCEN __attribute__((address(0x84F)));


extern volatile __bit OVF0 __attribute__((address(0xD0)));


extern volatile __bit OVF1 __attribute__((address(0xD1)));


extern volatile __bit OVF2 __attribute__((address(0xD2)));


extern volatile __bit OVF3 __attribute__((address(0xD3)));


extern volatile __bit OVF4 __attribute__((address(0xD4)));


extern volatile __bit OVIE __attribute__((address(0x444)));


extern volatile __bit OVIF __attribute__((address(0x44)));


extern volatile __bit OVTEE __attribute__((address(0x838)));


extern volatile __bit PATHEN __attribute__((address(0x848)));


extern volatile __bit PCIE __attribute__((address(0x8A6)));


extern volatile __bit PDEN __attribute__((address(0x83B)));


extern volatile __bit PEIE __attribute__((address(0x5E)));


extern volatile __bit PEN __attribute__((address(0x89A)));


extern volatile __bit PMADRH0 __attribute__((address(0xC98)));


extern volatile __bit PMADRH1 __attribute__((address(0xC99)));


extern volatile __bit PMADRH2 __attribute__((address(0xC9A)));


extern volatile __bit PMADRH3 __attribute__((address(0xC9B)));


extern volatile __bit PMADRL0 __attribute__((address(0xC90)));


extern volatile __bit PMADRL1 __attribute__((address(0xC91)));


extern volatile __bit PMADRL2 __attribute__((address(0xC92)));


extern volatile __bit PMADRL3 __attribute__((address(0xC93)));


extern volatile __bit PMADRL4 __attribute__((address(0xC94)));


extern volatile __bit PMADRL5 __attribute__((address(0xC95)));


extern volatile __bit PMADRL6 __attribute__((address(0xC96)));


extern volatile __bit PMADRL7 __attribute__((address(0xC97)));


extern volatile __bit PMDATH0 __attribute__((address(0xCA8)));


extern volatile __bit PMDATH1 __attribute__((address(0xCA9)));


extern volatile __bit PMDATH2 __attribute__((address(0xCAA)));


extern volatile __bit PMDATH3 __attribute__((address(0xCAB)));


extern volatile __bit PMDATH4 __attribute__((address(0xCAC)));


extern volatile __bit PMDATH5 __attribute__((address(0xCAD)));


extern volatile __bit PMDATH6 __attribute__((address(0xCAE)));


extern volatile __bit PMDATH7 __attribute__((address(0xCAF)));


extern volatile __bit PMDATL0 __attribute__((address(0xCA0)));


extern volatile __bit PMDATL1 __attribute__((address(0xCA1)));


extern volatile __bit PMDATL2 __attribute__((address(0xCA2)));


extern volatile __bit PMDATL3 __attribute__((address(0xCA3)));


extern volatile __bit PMDATL4 __attribute__((address(0xCA4)));


extern volatile __bit PMDATL5 __attribute__((address(0xCA5)));


extern volatile __bit PMDATL6 __attribute__((address(0xCA6)));


extern volatile __bit PMDATL7 __attribute__((address(0xCA7)));


extern volatile __bit PS0 __attribute__((address(0x408)));


extern volatile __bit PS1 __attribute__((address(0x409)));


extern volatile __bit PS2 __attribute__((address(0x40A)));


extern volatile __bit PSA __attribute__((address(0x40B)));


extern volatile __bit PUEN __attribute__((address(0x83A)));


extern volatile __bit RA0 __attribute__((address(0x28)));


extern volatile __bit RA1 __attribute__((address(0x29)));


extern volatile __bit RA2 __attribute__((address(0x2A)));


extern volatile __bit RA3 __attribute__((address(0x2B)));


extern volatile __bit RA4 __attribute__((address(0x2C)));


extern volatile __bit RA5 __attribute__((address(0x2D)));


extern volatile __bit RA6 __attribute__((address(0x2E)));


extern volatile __bit RA7 __attribute__((address(0x2F)));


extern volatile __bit RB0 __attribute__((address(0x30)));


extern volatile __bit RB1 __attribute__((address(0x31)));


extern volatile __bit RB2 __attribute__((address(0x32)));


extern volatile __bit RCEN __attribute__((address(0x89B)));


extern volatile __bit RD __attribute__((address(0xC80)));


extern volatile __bit RE0 __attribute__((address(0x4F0)));


extern volatile __bit RE1 __attribute__((address(0x4F1)));


extern volatile __bit RE2 __attribute__((address(0x4F2)));


extern volatile __bit RE3 __attribute__((address(0x4F3)));


extern volatile __bit RE4 __attribute__((address(0x4F4)));


extern volatile __bit RE5 __attribute__((address(0x4F5)));


extern volatile __bit RE6 __attribute__((address(0x4F6)));


extern volatile __bit RECIREN __attribute__((address(0x849)));


extern volatile __bit RP0 __attribute__((address(0x1D)));


extern volatile __bit RP1 __attribute__((address(0x1E)));


extern volatile __bit RSEN __attribute__((address(0x899)));


extern volatile __bit R_nW __attribute__((address(0x8B2)));


extern volatile __bit SBCDE __attribute__((address(0x8A2)));


extern volatile __bit SCIE __attribute__((address(0x8A5)));


extern volatile __bit SDAHT __attribute__((address(0x8A3)));


extern volatile __bit SEN __attribute__((address(0x898)));


extern volatile __bit SLCPBY __attribute__((address(0x84C)));


extern volatile __bit SLPG0 __attribute__((address(0x4E4)));


extern volatile __bit SLPG1 __attribute__((address(0x4E5)));


extern volatile __bit SLPG2 __attribute__((address(0x4E6)));


extern volatile __bit SLPG3 __attribute__((address(0x4E7)));


extern volatile __bit SLPS0 __attribute__((address(0x4E0)));


extern volatile __bit SLPS1 __attribute__((address(0x4E1)));


extern volatile __bit SLPS2 __attribute__((address(0x4E2)));


extern volatile __bit SLPS3 __attribute__((address(0x4E3)));


extern volatile __bit SLVGN0 __attribute__((address(0x4E8)));


extern volatile __bit SLVGN1 __attribute__((address(0x4E9)));


extern volatile __bit SLVGN2 __attribute__((address(0x4EA)));


extern volatile __bit SLVGN3 __attribute__((address(0x4EB)));


extern volatile __bit SLVGN4 __attribute__((address(0x4EC)));


extern volatile __bit SMP __attribute__((address(0x8B7)));


extern volatile __bit SSPEN __attribute__((address(0x895)));


extern volatile __bit SSPIE __attribute__((address(0x43C)));


extern volatile __bit SSPIF __attribute__((address(0x3C)));


extern volatile __bit SSPM0 __attribute__((address(0x890)));


extern volatile __bit SSPM1 __attribute__((address(0x891)));


extern volatile __bit SSPM2 __attribute__((address(0x892)));


extern volatile __bit SSPM3 __attribute__((address(0x893)));


extern volatile __bit SSPOV __attribute__((address(0x896)));


extern volatile __bit T0CS __attribute__((address(0x40D)));


extern volatile __bit T0IE __attribute__((address(0x5D)));


extern volatile __bit T0IF __attribute__((address(0x5A)));


extern volatile __bit T0SE __attribute__((address(0x40C)));


extern volatile __bit T1CKPS0 __attribute__((address(0x74)));


extern volatile __bit T1CKPS1 __attribute__((address(0x75)));


extern volatile __bit TMPSEN __attribute__((address(0x84A)));


extern volatile __bit TMR1CS __attribute__((address(0x71)));


extern volatile __bit TMR1IE __attribute__((address(0x438)));


extern volatile __bit TMR1IF __attribute__((address(0x38)));


extern volatile __bit TMR1ON __attribute__((address(0x70)));


extern volatile __bit TMR2IE __attribute__((address(0x439)));


extern volatile __bit TMR2IF __attribute__((address(0x39)));


extern volatile __bit TMR2ON __attribute__((address(0x82)));


extern volatile __bit TRISA0 __attribute__((address(0x428)));


extern volatile __bit TRISA1 __attribute__((address(0x429)));


extern volatile __bit TRISA2 __attribute__((address(0x42A)));


extern volatile __bit TRISA3 __attribute__((address(0x42B)));


extern volatile __bit TRISA4 __attribute__((address(0x42C)));


extern volatile __bit TRISA5 __attribute__((address(0x42D)));


extern volatile __bit TRISA6 __attribute__((address(0x42E)));


extern volatile __bit TRISA7 __attribute__((address(0x42F)));


extern volatile __bit TRISB0 __attribute__((address(0x430)));


extern volatile __bit TRISB1 __attribute__((address(0x431)));


extern volatile __bit TRISB2 __attribute__((address(0x432)));


extern volatile __bit TTA0 __attribute__((address(0xCD0)));


extern volatile __bit TTA1 __attribute__((address(0xCD1)));


extern volatile __bit TTA2 __attribute__((address(0xCD2)));


extern volatile __bit TTA3 __attribute__((address(0xCD3)));


extern volatile __bit TUN0 __attribute__((address(0xD8)));


extern volatile __bit TUN1 __attribute__((address(0xD9)));


extern volatile __bit TUN2 __attribute__((address(0xDA)));


extern volatile __bit TUN3 __attribute__((address(0xDB)));


extern volatile __bit TUN4 __attribute__((address(0xDC)));


extern volatile __bit UA __attribute__((address(0x8B1)));


extern volatile __bit UVDCEN __attribute__((address(0x84E)));


extern volatile __bit UVIE __attribute__((address(0x447)));


extern volatile __bit UVIF __attribute__((address(0x47)));


extern volatile __bit UVLO0 __attribute__((address(0x480)));


extern volatile __bit UVLO1 __attribute__((address(0x481)));


extern volatile __bit UVLO2 __attribute__((address(0x482)));


extern volatile __bit UVLO3 __attribute__((address(0x483)));


extern volatile __bit UVLO4 __attribute__((address(0x484)));


extern volatile __bit UVLO5 __attribute__((address(0x485)));


extern volatile __bit UVLOEN __attribute__((address(0x487)));


extern volatile __bit UVTEE __attribute__((address(0x839)));


extern volatile __bit VINIE __attribute__((address(0x441)));


extern volatile __bit VINIF __attribute__((address(0x41)));


extern volatile __bit VOUTON __attribute__((address(0xD7)));


extern volatile __bit VROT0 __attribute__((address(0xCE0)));


extern volatile __bit VROT1 __attribute__((address(0xCE1)));


extern volatile __bit VROT2 __attribute__((address(0xCE2)));


extern volatile __bit VROT3 __attribute__((address(0xCE3)));


extern volatile __bit VZC0 __attribute__((address(0x4B8)));


extern volatile __bit VZC1 __attribute__((address(0x4B9)));


extern volatile __bit VZC2 __attribute__((address(0x4BA)));


extern volatile __bit VZC3 __attribute__((address(0x4BB)));


extern volatile __bit VZC4 __attribute__((address(0x4BC)));


extern volatile __bit VZC5 __attribute__((address(0x4BD)));


extern volatile __bit VZC6 __attribute__((address(0x4BE)));


extern volatile __bit VZC7 __attribute__((address(0x4BF)));


extern volatile __bit WCOL __attribute__((address(0x897)));


extern volatile __bit WPUA0 __attribute__((address(0x828)));


extern volatile __bit WPUA1 __attribute__((address(0x829)));


extern volatile __bit WPUA2 __attribute__((address(0x82A)));


extern volatile __bit WPUA3 __attribute__((address(0x82B)));


extern volatile __bit WPUA5 __attribute__((address(0x82D)));


extern volatile __bit WPUB1 __attribute__((address(0x831)));


extern volatile __bit WPUB2 __attribute__((address(0x832)));


extern volatile __bit WPUGPA0 __attribute__((address(0x828)));


extern volatile __bit WPUGPA1 __attribute__((address(0x829)));


extern volatile __bit WPUGPA2 __attribute__((address(0x82A)));


extern volatile __bit WPUGPA3 __attribute__((address(0x82B)));


extern volatile __bit WPUGPA5 __attribute__((address(0x82D)));


extern volatile __bit WPUGPB1 __attribute__((address(0x831)));


extern volatile __bit WPUGPB2 __attribute__((address(0x832)));


extern volatile __bit WR __attribute__((address(0xC81)));


extern volatile __bit WREN __attribute__((address(0xC82)));


extern volatile __bit ZERO __attribute__((address(0x1A)));


extern volatile __bit ZROT0 __attribute__((address(0xCE8)));


extern volatile __bit ZROT1 __attribute__((address(0xCE9)));


extern volatile __bit ZROT2 __attribute__((address(0xCEA)));


extern volatile __bit ZROT3 __attribute__((address(0xCEB)));


extern volatile __bit nOT __attribute__((address(0x4A)));


extern volatile __bit nPD __attribute__((address(0x1B)));


extern volatile __bit nPOR __attribute__((address(0x49)));


extern volatile __bit nRAPUI __attribute__((address(0x40F)));


extern volatile __bit nTO __attribute__((address(0x1C)));
# 40 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic_chip_select.h" 2 3
# 14 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic.h" 2 3
# 76 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic.h" 3
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\eeprom_routines.h" 1 3
# 84 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic.h" 2 3
# 118 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/MCPxxxx_DFP/1.7.176/xc8\\pic\\include\\pic.h" 3
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;
# 28 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\xc.h" 2 3
# 26 "task5_pwm.c" 2



void init(void);
void pwmchange(void);

unsigned char pwmhigh20,pwmlow20;
unsigned char pwmhigh60,pwmlow60;
unsigned char pwmhigh90,pwmlow90;

void main(void)
{
init();
while(1)
{
    pwmchange();
}
}
void init(void)
{
    TRISC =0xFB;
    CCP2CON=0x0C;
    T2CON=0X06;
    PR2=0X2D;
    pwmhigh20=0x04;
    pwmlow20=0x00;
    pwmhigh60=0x1C;
    pwmlow60=0x00;
    pwmhigh90=0x2A;
    pwmlow90=0x00;

}
void pwmchange()
{
    CCPR2L=pwmhigh20;
    CCP2CON=(CCP2CON&0xCF)|pwmlow20;
    _delay((unsigned long)((3000)*(6000000/4000.0)));
    CCPR2L= pwmhigh60;
    CCP2CON=(CCP2CON&0xCF)|pwmlow60;
    _delay((unsigned long)((3000)*(6000000/4000.0)));
    CCPR2L= pwmhigh90;
    CCP2CON=(CCP2CON&0xCF)|pwmlow90;
    _delay((unsigned long)((3000)*(6000000/4000.0)));
}
