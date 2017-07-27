#include <types.h>
#include <video.h>
#include <time.h>

void k_main() {
    k_clear_screen();
    k_puts("Starting kernel...\n");
    k_puts("Kernel started!\n");
    while (1) {
        timer_handler();
    }
}
