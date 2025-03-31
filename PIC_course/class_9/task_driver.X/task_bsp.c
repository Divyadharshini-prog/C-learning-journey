
#include "task_bsp.h" 

// Memory-mapped address for OPTION_REG register
#define OPTION_REG_ADDR 0x81

// Function to enable internal pull-up for PORTB
void enable_internal_pullup() 
{
    unsigned char* option_reg = (unsigned char*) OPTION_REG_ADDR;  // Map memory to OPTION_REG
    *option_reg &= ~(1 << 7);  // Clear bit 7 of OPTION_REG to enable internal pull-up
}
