#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY_1 24601
#define KEY_2 24602

int shmid;
int shmd;
int fd;
union semun sm;
struct sembuf semaphore;

#define ROWS 10
#define COLS 10

#define NUM_SHIPS 5

#define PLAYER_ONE 1
#define PLAYER_TWO 2

#define CARRIER 'c'
#define BATTLESHIP 'b'
#define CRUISER 'r'
#define SUBMARINE 's'
#define DESTROYER 'd'
#define HIT 'X'
#define WATER '~'

#define SHSIZE 100
#define KEY_1 24601
#define KEY_2 24602

// #define NORTH 0
// #define SOUTH 1
// #define WEST  2
// #define EAST  3


// typedef struct stats {
// 	int        numHits;
// 	int        numMisses;
// 	int        totalShots;
// 	double     hitMissRatio;
// } Stats;

typedef struct coordinate {
	int xcoor;
	int ycoor;
} Coordinate;

typedef struct ship {
  char shipName;
  int length;
	int hits;
} Ship;

typedef struct cell {
	char shipSymbol;
	Coordinate position;
	Ship thisShip;
} Cell;

// typedef enum {
// 	C_LENGTH = 5,
// 	B_LENGTH = 4,
// 	R_LENGTH = 3,
// 	S_LENGTH = 3,
// 	D_LENGTH = 2
// } ShipType;

// typedef struct cell {
//   ship this_ship; //store the ship type
//   int positionx; //x-coordinate of position
//   int positiony; //y-coordinate of position
// } cell;

void printWelcome ();
void initializeBoard (Cell Board[ROWS][COLS]);
void printBoard (Cell Board[ROWS][COLS]);
void placeShips (Cell Board[ROWS][COLS], Ship ships[]);
void place (Cell Board[ROWS][COLS], Ship ship);
void randomizePositions(Cell Board[ROWS][COLS], Ship ships[]);
void hit(Cell Board[ROWS][COLS], Ship ships[]);
int PlayerWins(Ship ships[]);
void printMyShips(Ship ships[NUM_SHIPS]);
