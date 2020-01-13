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

#define ROWS 10
#define COLUMNS 10

#define NUM_OF_SHIPS  5

#define PLAYER_ONE    0
#define PLAYER_TWO    1

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3


// typedef struct stats {
// 	int        numHits;
// 	int        numMisses;
// 	int        totalShots;
// 	double     hitMissRatio;
// } Stats;

typedef struct coordinate {
	int        row;
	int        column;
} Coordinate;

typedef struct cell {
	char       symbol;
	Coordinate position;
} Cell;

typedef struct ship {
  char symbol
  char length;
  // int player; //which player this ship belongs to
} Ship;

typedef enum {
	C_LENGTH = 5,
	B_LENGTH = 4,
	R_LENGTH = 3,
	S_LENGTH = 3,
	D_LENGTH = 2
} ShipType;

// typedef struct cell {
//   ship this_ship; //store the ship type
//   int positionx; //x-coordinate of position
//   int positiony; //y-coordinate of position
// } cell;

void         printWelcome                (void);
void         initializeBoard             (Cell board[][COLS]);
void         printGame                   (Cell board [][COLS], Boolean showPegs);
