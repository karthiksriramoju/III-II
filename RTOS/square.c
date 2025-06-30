#include <lpc214x.h>
#include <stdint.h>
void delay_ms(uint16_t j) {
    uint16_t x, i;
    for (i = 0; i < j; i++) {
        for (x = 0; x < 6000; x++); // 1 ms delay
    }
}
int main(void) {
    uint16_t value;

    PINSEL1 = 0x00080000; // P0.25 as DAC output

    while (1) {
        // Increase from 0 to 1023
        for (value = 0; value < 1024; value++) {
            DACR = (1 << 16) | (value << 6);
            delay_ms(1); // Adjust speed
        }

        // Decrease from 1023 to 0
        for (value = 1023; value > 0; value--) {
            DACR = (1 << 16) | (value << 6);
            delay_ms(1);
        }
    }
}
