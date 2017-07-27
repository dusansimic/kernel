uchar inb(uint port);
ushort inw(uint port);
ushort inl(uint port);
void outb(uchar value, uint port);
void outw(ushort value, int port);
void outl(uint value, int port);
void iowait();