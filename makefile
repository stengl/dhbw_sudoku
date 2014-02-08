CC = gcc -Wall

sudoku: sudoku.o tools.o variables.o helpers.o
	CC -o $@ $^
sudoku.o tools.o variables.o helpers.o: sudoku.c
	CC -c $<
	
sudoku.o: 

all: clear sudoku run

clear:
	rm -f *.o sudoku
run:
	./sudoku
