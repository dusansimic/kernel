
#include <types.h>
#include <video.h>
#include <string.h>

uint timer_ticks = 0;
ulong freq = 200000000;

void timer_handler() {
    if (++timer_ticks % freq  == 0) {
        char string[100];
        k_puts("Seconds ");
        its(timer_ticks / freq, string);
        k_puts(string);
        k_putc("\n");
    }
}
