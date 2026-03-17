CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -O -fPIC
LFLAGS = -Wall -std=c99 -pedantic -O
LIB =
HEAD =

.SUFFIXES: .c .o .x

all: parent.x child.x

parent.x: parent.o $(LIB)
	$(CC) $(LFLAGS) -o $@ $^

child.x: child.o $(LIB)
	$(CC) $(LFLAGS) -o $@ $^

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $<

.PHONY: run clean tar help

run: all
	./parent.x ./child.x

clean:
	rm -f *.o *.x *~

tar: clean
	(cd ..; tar -cvzf Cwiczenie2.tar.gz $(notdir $(CURDIR)))

help:
	@echo "Możliwe cele:"
	@echo "  make all   - kompilacja obu programów"
	@echo "  make run   - kompilacja i uruchomienie"
	@echo "  make clean - usuwanie plików obiektowych i wykonywalnych"
	@echo "  make tar   - archiwizacja projektu"
	@echo "  make help  - ta pomoc"
