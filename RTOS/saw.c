#include <lpc214x.h>
#include <stdint.h>

// Delay function: software delay in milliseconds
void delay_ms(uint16_t j)
{
    uint16_t x, i;
    for (i = 0; i < j; i++) {
        for (x = 0; x < 6000; x++);  // loop to generate ~1ms delay @ 60MHz
    }
}

int main(void)
{
    uint16_t value;

    PINSEL1 = 0x00080000;  // Configure P0.25 as DAC output (DACOUT)

    while (1)  // Infinite loop
    {
        value = 0;  // Start ramp from 0

        // Ramp value from 0 to 1023 (10-bit DAC resolution)
        while (value != 1023)
        {
            DACR = ( (1 << 16) | (value << 6) );  // Update DAC output
            value++;  // Increment DAC value (increases voltage)

            // Add a delay here if you want to slow down the ramp speed
            // delay_ms(1);
        }

        // Once it reaches 1023, it resets and ramps again (loops forever)
    }
}
