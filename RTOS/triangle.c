#include <lpc214x.h>
#include <stdint.h>

void delay_ms(uint16_t j)
{
    uint16_t x, i;
    for (i = 0; i < j; i++) {
        for (x = 0; x < 6000; x++);
    }
}

int main (void)
{
    uint16_t value;

    PINSEL1 = 0x00080000; // Set P0.25 as DAC output

    while (1)
    {
        value = 0;

        // Ramp up
        while (value != 1023)
        {
            DACR = ( (1 << 16) | (value << 6) );
            value++;
            delay_ms(1); // slow the ramp
        }

        // Ramp down
        while (value != 0)
        {
            DACR = ( (1 << 16) | (value << 6) );
            value--;
            delay_ms(1);
        }
    }
}
