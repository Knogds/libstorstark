# libstorstark/Makefile

include ../makefile.conf

.PHONY: clean

BASE = .

OBJS = rcc.o helper.o

libstorstark.a : $(OBJS)
	ar cr $@ $^

clean :
	rm -f $(OBJS) libstorstark.a
