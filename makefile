all: game.o main.o
	gcc -o battleship game.o main.o

game.o: game.c game.h
	gcc -c game.c

main.o: main.c game.h
	gcc -c main.c

run:
	./battleship

clean:
	rm *.o
	rm *~
