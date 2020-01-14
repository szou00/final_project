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
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 0;
  printf("  ");
  while (n<10) {
    printf("%d ", nums[n]);
    n++;
  }
  printf("\n");
	for (int r = 0; r < ROWS; r++) {
    printf("%d ", nums[r]);
		for (int c = 0; c < COLS; c++) {
      if (Board[r][c].shipSymbol == ' ') {
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
  for (int i = 0; i < NUM_SHIPS; i++){
    int placed = 0;
    while (!placed){
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
        printf("Invalid coordinates. Try again.\n");
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
            if (Board[j][x1].shipSymbol != ' '){
              valid = 0;
              printf("Ships overlapping\n");
            }
          }
          if (valid){
            for (int j = less; j <= more; j++){
              Board[j][x1].shipSymbol = ships[i].shipName;
            }
            placed = 1;
            printBoard(Board);
          }
        }
      }
      else if (y1 == y2){
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
            if (Board[y1][j].shipSymbol != 0){
              valid = 0;
              printf("Ships overlapping\n");
            }
          }
          if (valid){
            for (int j = less; j <= more; j++){
              Board[y1][j].shipSymbol = ships[i].shipName;
            }
            placed = 1;
            printBoard(Board);
          }
        }
      }
    }
  }
}

void hit(Board[ROWS][COLS], Ship ships[], int xcoor, int ycoor) {
  int i = 0;
  if (Board[xcoor][ycoor] != 0) {
    Board[xcoor][ycoor].shipSymbol == HIT;
    for (i = 0; i++; )
  }
}


// void randomizePositions(Cell Board[ROWS][COLS], Ship ships[]) {
//   srand(time(0));
//   int x1, y1, x2, y2;
//   int o;
//   int placing = 1;
//   int i = NUM_SHIPS;
//
//   while (i == NUM_SHIPS) {
//     o = rand()%2;
//     printf("%d\n",i);
//
//     if (o == 1) {
//       printf("horizontal\n");
//       while (placing) { //orientation is horizontal
//         y1 = rand()%10;
//         y2 = y1;
//         x1 = rand()%(10-ships[i].length);
//         printf("x1: %d\n", x1);
//         x2 += ships[i].length;
//         printf("x2: %d\n", y1);
//         if (x2 < COLS) {
//           for (int j = x1; j <= x2; j++){
//             Board[y1][j].shipSymbol = ships[i].shipName;
//             printf("placed\n");
//             i--;
//           }
//           placing = 0;
//         }
//       }
//     }
//
//     if (o == 2) {
//       printf("vertical\n");
//       while (placing) { //orientation is vertical
//         x1 = rand()%10;
//         x2 = y1;
//         y1 = rand()%10;
//         y2 += ships[i].length;
//         if (y2 < ROWS) {
//           for (int j = y1; j <= y2; j++){
//             Board[j][x1].shipSymbol = ships[i].shipName;
//             printf("placed\n");
//             i--;
//           }
//           placing = 0;
//         }
//       }
//     }
//   }
//
//   printBoard(Board);
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
