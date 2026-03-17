DIR = $(notdir $(CURDIR))

all:
	cd a; make
	cd b; make
	cd c; make
	cd d; make
	cd e; make

clean:
	rm -f *~
	cd a; make clean
	cd b; make clean
	cd c; make clean
	cd d; make clean
	cd e; make clean

tar: clean
	(cd ..; tar -cvzf $(DIR).tar.gz $(DIR))

.PHONY: all clean tar
