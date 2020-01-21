#include "game.h"

void printWelcome() {
  system("clear");
  printf("\n\n\n\n\n\n");
  printf("            ___  ___  ___  ___  _    ___  ___  _ _  _  ___ \n ");
  sleep(1);
  printf("           | . >| . ||_ _||_ _|| |  | __>/ __>| | || || . \\ \n");
  sleep(1);
  printf("            | . \\|   | | |  | | | |_ | _> \\__ \\|   || ||  _/\n");
  sleep(1);
  printf("            |___/|_|_| |_|  |_| |___||___><___/|_|_||_||_| \n");

  sleep(3);
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
  // system("clear");
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
  printBoard(Board);
  int c;
  char buf[20];
  for (int i = 0; i < NUM_SHIPS; i++){
    printf("Would you like to (1) manually place a ship or (2) randomly place one? ");
    scanf("%d", &c);
    if (c == 1) {
      manuallyPlace(Board, ships, i);
    }
    else {
      randomlyPlace(Board, ships, i);
    }
  }
}

void manuallyPlace(Cell Board[ROWS][COLS], Ship ships[], int current) {
  int x1, x2, y1, y2, orientation, valid;
  // int placed = 0;
  // while (!placed){
    printf("This ship is %d cells long.\n", ships[current].length);
    printf("Would you like the ship to be (1) horizontal or (2) vertical?\nType in 1 or 2: ");
    scanf("%d", &orientation);

    //in case they put in wrong num
    while (orientation != 1 && orientation != 2) {
      printf("Please choose a valid option: ");
      scanf("%d", &orientation);
    }
    //
    printf("Enter the x-coordinate of initial position: ");
    scanf("%d", &x1);
    printf("Enter the y-coordinate of initial position: ");
    scanf("%d", &y1);

    if (orientation == 2) {
      x2 = x1;
      // printf("y2: %d\n", y2);
      if (y1+ships[current].length > ROWS) {
        y2 = y1 - ships[current].length;
      }
      else {
        // printf("y2: %d\n", y2);
        y2 = y1+ships[current].length;
      }
      // printf("ship length: %d\n", ships[i].length);
      // printf("y2: %d\n", y2);

      valid = 1;
      int less, more;
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
          }
        }
        if (valid){
          for (int j = less; j < more; j++){
            Board[j][x1].shipSymbol = ships[current].shipName;
            Board[j][x1].thisShip = ships[current];
            Board[y1][j].thisShip.hits = 0;
          }
          // placed = 1;
          system("clear");
          printBoard(Board);
        }
        else {
          printf("Ships overlapping\n");
        }
      }
    else if (orientation == 1){
      y2 = y1;
      x2 = 0;
      // printf("x2: %d\n", x2);
      if (x1+ships[current].length > COLS) {
        x2 = x1 - ships[current].length;
      }
      else {
        // printf("x2: %d\n", x2);
        x2 = x1+ships[current].length;
      }
      // printf("ship length: %d\n", ships[i].length);
      // printf("x2: %d\n", x2);

      int less, more;
      valid = 1;
      if (x1 < x2){
        less = x1;
        more = x2;
      }
      else{
        less = x2;
        more = x1;
      }
      // printf("less: %d, more: %d\n", less, more);
      for (int j = less; j <= more; j++){
        if (Board[y1][j].shipSymbol != ' '){
          valid = 0;
        }
      }
      // printf("valid: %d\n", valid);
      if (valid){
        for (int j = less; j < more; j++){
          Board[y1][j].shipSymbol = ships[current].shipName;
          Board[y1][j].thisShip = ships[current];
          Board[y1][j].thisShip.hits = 0;
          // printf("number of hits: %d\n", Board[y1][j].thisShip.hits);
        }
        // placed = 1;
        system("clear");
        printBoard(Board);
      }
      else {
        printf("ships are overlapping\n");
      }
    }
  // }
}

void hit(Cell Board[ROWS][COLS], Ship ships[]) {
  int r, c, s;
  printf("which position would you like to hit?\n");
  printf("Enter the x-coordinate: ");
  scanf("%d", &c);
  printf("Enter the y-coordinate: ");
  scanf("%d", &r);

  int i = 0;
  if (Board[r][c].shipSymbol != ' ') {
    for (s = 0; s<5; s++) {
      // printf("ship symbol: %c ship name: %c\n", ships[s].shipName, Board[r][c].shipSymbol);
      if (Board[r][c].shipSymbol == ships[s].shipName) {
        ships[s].hits += 1;
        // printf("Number of hits that %c has: %d\n", ships[s].shipName, ships[s].hits);
      }
    }
    Board[r][c].shipSymbol = HIT;
    // printf("Number of hits: %d\n", Board[r][c].thisShip.hits);
  }
  else {
    Board[r][c].shipSymbol = WATER;
    // printf("Oops, you hit water!\n");
  }
  system("clear");
  printBoard(Board);
}

int PlayerWins(Ship ships[]) {
  int n, sunk = 0;
  for (n = 0; n < 5; n++) {
    if (ships[n].hits == ships[n].length) {
      sunk++;
    }
    // printf("ship hits: %d\n", ships[n].hits);
  }
  if (sunk == 5) {
    printf("Player won!\n");
    return 1;
  }
  return 0;
}

int checkShips(Ship ships[]) {
  int n, sunk = 0;
  for (n = 0; n < 5; n++) {
    if (ships[n].hits == ships[n].length) {
      sunk++;
    }
  }
  printf("You have sunk %d ships so far!\n", sunk);
  return sunk;
}

void randomlyPlace(Cell Board[ROWS][COLS], Ship ships[], int current) {
  int x1, y1, x2, y2, j, valid, more, less = 0;
  int o;
  int placing = 1;
  srand(time(0));

    o = rand()%2;
    // printf("%d\n",i);
    // printf("%d\n",o);

    if (o == 1) {
      // printf("horizontal\n");
      // while (placing) { //orientation is horizontal
        y1 = rand()%10;
        // printf("y1: %d\n", y1);
        x1 = rand()%10;
        // printf("x1: %d\n", x1);
        // printf("ship length: %d\n", ships[i].length);
        if (x1+ships[current].length >= COLS) {
          x2 = x1-ships[current].length;
        }
        else {
          x2 = x1+ships[current].length;
        }
        // printf("x2: %d\n", x2);
        //check if it's valid first
        if (x1<x2) {
          more = x2;
          less = x1;
        }
        else {
          more = x1+1;
          less = x2+1;
        }
        for (j = less; j <= more; j++){
          if (Board[y1][j].shipSymbol != ' '){
            valid = 0;
            // printf("not valid\n");
          }
        }
        if (valid) {
          for (j = less; j < more; j++){
            Board[y1][j].shipSymbol = ships[current].shipName;
            // printf("placed\n");
          }
          printf("placed one!\n");
        }
          // placing = 0;
        // }
    }

    if (o == 0) {
      // printf("vertical\n");
      // while (placing) { //orientation is horizontal
      x1 = rand()%10;
      // printf("x: %d\n", x1);
      y1 = rand()%10;
      // printf("y1: %d\n", y1);
      // printf("ship length: %d\n", ships[i].length);
      if (y1+ships[current].length >= ROWS) {
        y2 = y1-ships[current].length;
      }
      else {
        y2 = y1+ships[current].length;
      }
      // printf("y2: %d\n", y2);
      if (y1<y2) {
        more = y2;
        less = y1;
      }
      else {
        more = y1+1;
        less = y2+1;
      }
      // printf("more: %d\n", more);
      // printf("less: %d\n", less);
      for (j = less; j < more; j++){
        if (Board[j][x1].shipSymbol != ' '){
          valid = 0;
          // printf("%d, not valid\n", j);
        }
      }
      if (valid) {
        // printf("is valid\n");
        for (j = less; j < more; j++){
          Board[j][x1].shipSymbol = ships[current].shipName;
          // printf("placed\n");
        }
        printf("placed one!\n");
      }
  }
  printBoard(Board);
}

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
