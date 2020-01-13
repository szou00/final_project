all: game.o
<<<<<<< HEAD
	gcc -o battleship game.o

game.o: game.c
	gcc -c game.c

=======
	gcc -o play game.o

shellfunc.o: game.c game.h
	gcc -c game.c

# main.o: main.c game.c
# 	gcc -c main.c

run:
	./play

>>>>>>> 20708a658ae0932f97fd03d4c5b77ffba0babf23
clean:
	rm *.o
	rm *~
