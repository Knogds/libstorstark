# libstorstark/../Makefile

SUBDIRS = libstorstark projects
MAKEOPTS = -C

.PHONY: clean all

all:
	for dir in $(SUBDIRS); do \
          $(MAKE) $(MAKEOPTS) $$dir; \
        done

clean:
	for dir in $(SUBDIRS); do \
          $(MAKE) $(MAKEOPTS) $$dir clean; \
        done
