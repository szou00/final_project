all: game.o
	gcc -o battleship game.o

game.o: game.c game.h
	gcc -c game.c

main.o: main.c game.h
	gcc -c main.c

run:
	./battleship

clean:
	rm *.o
	rm *~
