all: game.o
	gcc -o play game.o

shellfunc.o: game.c game.h
	gcc -c game.c

# main.o: main.c game.c
# 	gcc -c main.c

run:
	./play

clean:
	rm *.o
	rm *~
