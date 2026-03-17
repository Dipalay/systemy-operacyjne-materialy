NAME = fork
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -O -fPIC
LFLAGS = -Wall -std=c99 -pedantic -O
LIB =
HEAD =

.SUFFIXES: .c .o .x

all: $(NAME).x

$(NAME).x: $(NAME).o $(LIB)
	$(CC) $(LFLAGS) -o $@ $^

$(NAME).o: $(NAME).c $(HEAD)
	$(CC) $(CFLAGS) -c $<

.PHONY: run clean tar help

run: all
	./$(NAME).x

clean:
	rm -f *.o *.x *~

tar: clean
	(cd ..; tar -cvzf $(NAME).tar.gz $(notdir $(CURDIR)))

help:
	@echo "Możliwe cele:"
	@echo "  make all   - kompilacja programu"
	@echo "  make run   - kompilacja i uruchomienie"
	@echo "  make clean - usuwanie plików obiektowych i wykonywalnych"
	@echo "  make tar   - archiwizacja projektu"
	@echo "  make help  - ta pomoc"
