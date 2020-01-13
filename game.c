#include "game.h"
#define ROWS 10
#define COLUMNS 10

void printGame(cell Board[ROWS][COLUMNS]) {
  int r = 0, c = 0;

	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLUMNS; c++) {
      if (Board[r][c].hasShip == 1) {
        if (Board[r][c].this_ship.player == 1) {
          printf("1 ");
        }
        else {
          printf("2 ");
        }
      }
			else {
        printf("* ");
      }
			// printf("%d%d ", Board[r][c].positionx, Board[r][c].positiony);
		}
    printf("\n");
  }
}

void initializeBoard(cell Board[ROWS][COLUMNS]) {
  int r = 0, c = 0;

	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLUMNS; c++) {
			Board[r][c].positionx = r;
			Board[r][c].positiony = c;
      Board[r][c].hasShip = 0;
		}
  }
  printGame(Board);
}

void printWelcome() {
  printf("WELCOME TO\n");
  printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
  printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
  sleep(1);
  system("clear");
	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.\n");
	printf ("2. There are five types of ships to be placed by longest length to the\n");
	printf ("   shortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n");
	printf ("   has 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells\n");
	printf ("3. First player to guess the location of all ships wins\n\n");
  printf("                  L O A D I N G ...\n");
  sleep(5);
  printf("                  R E A D Y!\n");
  sleep(1);
  system("clear");
}

//start off with 10 one box ships
int randomizePositions(cell Board[ROWS][COLUMNS]) {
  srand(time(0));
  int i, r, c;
  int p = 10; //number of ships to be placed
  int pl = 1; //player 1

  while (p > 0) {
    r = rand()%10;
    c = rand()%10;
    // printf("%d%d\n", r, c);
    struct ship s1;
    if (pl == 1) { //current player is player 1
      s1.player = 1;
      pl = 2; //next player is player 2
    }
    else {
      s1.player = 2;
      pl = 1; //next player is 1
    }
    s1.positionx = r;
    s1.positiony = c;
    Board[r][c].this_ship = s1;
    Board[r][c].hasShip = 1;
    p--;
  }

  printGame(Board);

  return 0;
}

int main() {
  int inGame = 1;
  char str[100];
  system("clear");

  //initialization
  // printWelcome();
  cell Board[ROWS][COLUMNS];
  initializeBoard(Board);
  printf("Would you like to:\n(1)randomize the ship positions?\n(2)Manually enter them? Choose 1 or 2\n");
  scanf("%s", str);
  if (strcmp(str, "1") == 0) {
    randomizePositions(Board);
  }
}
