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

typedef struct ship {
  int ship_type;
  int player; //which player this ship belongs to
} ship;

typedef struct cell {
  ship this_ship; //store the ship type
  int positionx; //x-coordinate of position
  int positiony; //y-coordinate of position
} cell;
