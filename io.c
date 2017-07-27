#include <types.h>

uchar inb(uint port) {
  uchar result;
  asm("inb %w1, %b0" : "=a" (result) : "Nd" (port) );
  return result;
}

ushort inw(uint port) {
  uchar result;
  asm("inw %w1, %w0" : "=a" (result) : "Nd" (port) );
  return result;
}

ushort inl(uint port) {
	uint32_t result;
	asm("inl %w1, %0" : "=a" (result) : "Nd" (port) );
	return result;
}

void outb(uchar value, uint port) {
	asm("outb %b0, %w1" : : "a" (value), "Nd" (port) );
}

void outw(ushort value, int port) {
	asm("outw %w0, %w1" : : "a" (value), "Nd" (port) );
}

void outl(uint value, int port) {
	asm("outl %0, %w1" : : "a" (value), "Nd" (port) );
}

void iowait() {
  outb(0, 0x80);
}