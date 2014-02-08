CC = gcc -Wall

sudoku: sudoku.o
	CC -o $@ $<
sudoku.o: sudoku.c
	CC -c $<

all: clear sudoku run

clear:
	rm -f *.o sudoku
run:
	./sudoku
