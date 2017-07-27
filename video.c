#include <types.h>
#include <video.h>
#include <string.h>

#define WHITE_TXT 0xF

const char *headvidmem = (char *) (0xB8000);
const uint VIDMEM_HEIGHT = 25;
const uint VIDMEM_WIDTH = 80;
const uint VIDMEM_DEPTH = 2;

int curline = 0;
int offset = 0;

void k_clear_screen() {
    char *vidmem = (char *) headvidmem;
    uint i;
    for ( i = 0; i < (VIDMEM_WIDTH * VIDMEM_HEIGHT); i++) {
        *vidmem++ = ' ';
        *vidmem++ = WHITE_TXT;
    }
}

void k_putc(char *character) {
    uint track = 0;
    char *vidmem = (char *) headvidmem;
    if (*character == '\n' && curline < VIDMEM_HEIGHT) {
        curline++;
        offset = 0;
    } else {
        vidmem += (curline * VIDMEM_WIDTH * VIDMEM_DEPTH + offset * VIDMEM_DEPTH);
        *vidmem++ = *character;
        *vidmem++ = WHITE_TXT;
        if (offset == VIDMEM_WIDTH && curline < VIDMEM_HEIGHT) {
            curline++;
            offset = 0;
        } else {
            offset++;
        }
    }
    if (*character == '\n')
        trackVidMem();
}

void k_puts(char *string) {
    trackVidMem();
    while (*string) {
        k_putc(string);
        string++;
    }
}

uint trackVidMem() {
    if (curline == (VIDMEM_HEIGHT - 1)) {
        char *vidmem = (char *) headvidmem;
        uint i;
        for (i = 1; i <= VIDMEM_HEIGHT; i++) {
            uint j;
            for (j = 0; j < VIDMEM_WIDTH; j++) {
                vidmem[(i - 1) * VIDMEM_WIDTH * VIDMEM_DEPTH + j * VIDMEM_DEPTH] = vidmem[i * VIDMEM_WIDTH * VIDMEM_DEPTH + j * VIDMEM_DEPTH];
            }
        }
        for (i = 0; i < VIDMEM_WIDTH; i++) {
            vidmem[(VIDMEM_HEIGHT - 1) * VIDMEM_WIDTH * VIDMEM_DEPTH + i * VIDMEM_DEPTH] = ' ';
        }
        curline--;
        offset = 0;

        return 0;
    }

    return 1;
}

#undef WHITE_TXT