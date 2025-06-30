#include <LPC214x.h>  // Include LPC214x register definitions

// Delay function (software delay)
void delay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++) {
        for(j = 0; j < 7800; j++);  // Inner loop gives time delay
    }
}

int main() {
    PINSEL0 = 0x00000000;   // Configure P0.0 to P0.15 as GPIO
    IODIR0 = 0xFF;          // Set P0.0 to P0.7 as OUTPUT (8 bits)

    while(1) {
        IOSET0 = 0xFF;      // Set P0.0 to P0.7 HIGH (Turn ON LEDs)
        delay(100);         // Wait for some time
        
        IOCLR0 = 0xFF;      // Clear P0.0 to P0.7 LOW (Turn OFF LEDs)
        delay(100);         // Wait for some time
    }
}
