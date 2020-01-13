#include "game.h"

void initializeBoard(Cell board[ROWS][COLUMNS]) {
  int r = 0, c = 0;

	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLUMNS; c++) {
			board[r][c].positionx = r;
			board[r][c].positiony = c;
		}
}

void printGame(cell Board[ROWS][COLUMNS]) {
  int r = 0, c = 0;

	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLUMNS; c++) {
			// printf("* ");
			printf("%d%d ", Board[r][c].positionx, Board[r][c].positiony);
		}
    printf("\n");
  }
}

void printWelcome() {
  printf("WELCOME TO\n");
  printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
  printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
  // printf("   ___     ___    _____   _____    _       ___     ___    _  _     ___      ___  ");
  // printf("  | _ )   /   \  |_   _| |_   _|  | |     | __|   / __|  | || |   |_ _|    | _ \ ");
  // printf("  | _ \   | - |    | |     | |    | |__   | _|    \__ \  | __ |    | |     |  _/ ");
  // printf("  |___/   |_|_|   _|_|_   _|_|_   |____|  |___|   |___/  |_||_|   |___|   _|_|_  ");
  // printf("_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_| """ | ");
  // printf(""`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' ");
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
int randomizePositions() {
  srand(time(0));
  // int i = 0;
  int s = 10; //number of ships to be placed

  for (int i = 0; i<10; i++) {
    printf("%d\n", rand()%100);

  }
  return 0;
}

int main() {
  system("clear");
  printWelcome();

  cell Board[ROWS][COLUMNS];
  initializeBoard(Board);
  printGame(Board);
  randomizePositions();
}
