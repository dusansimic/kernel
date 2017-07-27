CC=gcc
CC_FLAGS=-m32 -I. -fno-stack-protector
ASM=nasm
ASM_FLAGS=-f elf32
LD=ld
LD_FLAGS=-m elf_i386 -T kernel.ld
E=@echo
Q=@
PROGRAM=kernel

CSRC=main.c video.c time.c string.c
COBJ=main.o video.o time.o string.o
ASMOBJ=boot.o

all: $(PROGRAM)

.asm.o:
	$(E) "  asm     " $@
	$(Q) $(ASM) $(ASM_FLAGS) $*.asm -o $@

.c.o:
	$(E) "  cc      " $@
	$(Q) $(CC) $(CC_FLAGS) -c $*.c

$(PROGRAM): $(COBJ)
	$(E) "  asm      boot.o"
	$(Q) $(ASM) $(ASM_FLAGS) boot.asm -o boot.o
	$(E) "  ld      " $@
	$(Q) $(LD) $(LD_FLAGS) -o $(PROGRAM) $(ASMOBJ) $(COBJ)

clean:
	$(E) "  clean"
	$(Q) rm -f *.o $(PROGRAM)
