#include "game.h"

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

void initializeBoard(Cell Board[ROWS][COLS]) {
  int r = 0, c = 0;
	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			Board[r][c].position.ycoor = r;
			Board[r][c].position.xcoor = c;
      Board[r][c].shipSymbol = ' ';
		}
  }
}

void printBoard(Cell Board[ROWS][COLS]) {
  char *empty = " ";
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
      if (strcmp(&Board[r][c].shipSymbol, empty) == 0) {
        printf("0 ");
      }
      else{
        printf("%c ", Board[r][c].shipSymbol);
      }
    }
    printf("\n");
  }
}

void placeShips(Cell Board[ROWS][COLS], Ship ships[]){
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  char *empty = " ";
  for (int i = 0; i < NUM_SHIPS; i++){
    int placed = 0;
    while (!placed){
      printBoard(Board);
      printf("This ship is %d cells long.\n", ships[i].length);
      printf("Enter the x-coordinate of initial position: ");
      scanf("%d", &x1);
      printf("Enter the y-coordinate of initial position: ");
      scanf("%d", &y1);
      printf("Enter the x-coordinate of final position: ");
      scanf("%d", &x2);
      printf("Enter the y-coordinate of final position: ");
      scanf("%d", &y2);
      int valid = 1;
      if (x1 != x2 && y1 != y2){
        printf("Invalid coordinates. Try again");
      }
      else if (x1 == x2){
        if (abs(y1-y2) != ships[i].length){
          printf("Ship dopes not match this length.\n");
        }
        else{
          int less = 0;
          int more = 0;
          if (y1 < y2){
            less = y1;
            more = y2;
          }
          else{
            less = y2;
            more = y1;
          }
          for (int j = less; j <= more; j++){
            if (strcmp(&Board[j][x1].shipSymbol, empty) != 0){
              valid = 0;
              printf("Ships overlapping\n");
            }
          }
          if (valid){
            for (int j = less; j <= more; j++){
              Board[j][x1].shipSymbol = ships[i].shipName;
            }
            placed = 1;
          }
        }
      }
      else{
        if (abs(x1-x2) != ships[i].length){
          printf("Ship dopes not match this length.\n");
        }
        else{
          int less = 0;
          int more = 0;
          valid = 1;
          if (x1 < x2){
            less = x1;
            more = x2;
          }
          else{
            less = x2;
            more = x1;
          }
          for (int j = less; j <= more; j++){
            if (strcmp(&Board[y1][j].shipSymbol, empty) != 0){
              valid = 0;
              printf("Ships overlapping\n");
            }
          }
          if (valid){
            for (int j = less; j <= more; j++){
              Board[y1][j].shipSymbol = ships[i].shipName;
            }
            placed = 1;
          }
        }
      }
    }
  }
}


//start off with 10 one box ships
// int randomizePositions(Cell Board[ROWS][COLUMNS]) {
//   srand(time(0));
//   int i, r, c;
//   int p = 10; //number of ships to be placed
//   int pl = 1; //player 1
//
//   while (p > 0) {
//     r = rand()%10;
//     c = rand()%10;
//     // printf("%d%d\n", r, c);
//     struct ship s1;
//     if (pl == 1) { //current player is player 1
//       s1.player = 1;
//       pl = 2; //next player is player 2
//     }
//     else {
//       s1.player = 2;
//       pl = 1; //next player is 1
//     }
//     s1.positionx = r;
//     s1.positiony = c;
//     Board[r][c].this_ship = s1;
//     Board[r][c].hasShip = 1;
//     p--;
//   }
//
//   printGame(Board);
//
//   return 0;
// }

// int main() {
//   int inGame = 1;
//   char str[100];
//   system("clear");
//
//   //initialization
//   // printWelcome();
//   cell Board[ROWS][COLUMNS];
//   initializeBoard(Board);
//   printf("Would you like to:\n(1)randomize the ship positions?\n(2)Manually enter them? Choose 1 or 2\n");
//   scanf("%s", str);
//   if (strcmp(str, "1") == 0) {
//     randomizePositions(Board);
//   }
// }
