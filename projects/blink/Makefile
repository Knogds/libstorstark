# libstorstark/../projects/blink/Makefile

NAME = blink
BASE = ../../libstorstark
LIBS = $(BASE)/libstorstark.a

include ../../makefile.conf

.PHONY : all clean

all : $(NAME).bin

upload : $(NAME).bin
	st-flash write $^ 0x20000000

clean :
	rm -f *.elf *.map *.o *bin
