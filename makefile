all: game.o
	gcc -o battleship game.o

game.o: game.c
	gcc -c game.c

clean:
	rm *.o
	rm *~
