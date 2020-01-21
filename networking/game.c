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
        printf("* ");
      }
      else{
        printf("%c ", Board[r][c].shipSymbol);
      }
    }
    printf("\n");
  }
}

void printBoards(Cell Board[ROWS][COLS], Cell opp[ROWS][COLS]) {
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 0;

  printf("Your Board\t\t\tPlayer Two's Board\n");
  printf("  ");
  while (n<10) {
    printf("%d ", nums[n]);
    n++;
  }
  //printing board 2
  printf("\t\t");
  n = 0;
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
        printf("* ");
      }
      else{
        printf("%c ", Board[r][c].shipSymbol);
      }
    }
    //printing Board 2
    printf("\t\t");
    printf("%d ", nums[r]);
    for (int c = 0; c < COLS; c++) {
      if (opp[r][c].shipSymbol == HIT || opp[r][c].shipSymbol == WATER) {
        printf("%c ", opp[r][c].shipSymbol);
      }
      else {
        printf("* ");
      }
    }
    printf("\n");
  }
}

void printShips(Ship me[NUM_SHIPS], Ship opp[NUM_SHIPS]) {
  int i, n = 0;
  printf("\n");
  printf("Your Ships\t\t\tPlayer Two's Ships\n");
  for (i = 0; i<NUM_SHIPS; i++) {
    printf("%c : %d", me[i].shipName, me[i].hits);
    printf("\t\t\t\t");
    printf("%c : %d\n", opp[i].shipName, opp[i].hits);
  }
}


void placeShips(Cell Board[ROWS][COLS], Ship ships[]){
  // int c;
  // char buf[20];
  printBoard(Board);
  for (int i = 0; i < NUM_SHIPS; i++){
<<<<<<< HEAD
    int placed = 0;
    while (!placed){
      char buf[256];

      printf("This ship is %d cells long.\n", ships[i].length);
      printf("Would you like the ship to be (1) horizontal or (2) vertical?\nType in 1 or 2: ");
      // fflush(stdout);
      // fflush(stdin);
      fgets(buf, sizeof(buf), stdin);
      orientation = atoi(buf);
      fflush(stdout);
      fflush(stdin);
      // scanf("%d", &orientation);

      //in case they put in wrong num
      while ((orientation != 1 && orientation != 2)) {
        printf("Please choose a valid option: ");
        // fflush(stdout);
        // fflush(stdin);
        fgets(buf, sizeof(buf), stdin);
        orientation = atoi(buf);
        fflush(stdout);
        fflush(stdin);
        // scanf("%d", &orientation);
        // cleanBuffer();
      }

      //taking in an x-coordinate
      printf("Enter the x-coordinate of initial position: ");
      fgets(buf, sizeof(buf), stdin);
      x1 = atoi(buf);
      fflush(stdout);
      fflush(stdin);
      // scanf("%d", &x1);
      while (!isValidCoord(x1)) {
        printf("Please choose a valid x-coordinate: ");
        fgets(buf, sizeof(buf), stdin);
        x1 = atoi(buf);
        fflush(stdout);
        fflush(stdin);
        // scanf("%d", &x1);
      }
      //y-coordinate
      printf("Enter the y-coordinate of initial position: ");
      fgets(buf, sizeof(buf), stdin);
      y1 = atoi(buf);
      fflush(stdout);
      fflush(stdin);
      // scanf("%d", &y1);
      while (!isValidCoord(y1)) {
        printf("Please choose a valid y-coordinate: ");
        fgets(buf, sizeof(buf), stdin);
        y1 = atoi(buf);
        fflush(stdout);
        fflush(stdin);
        // scanf("%d", &y1);
      }
=======
    // printf("Would you like to (1) manually place a ship or (2) randomly place one? ");
    // scanf("%d", &c);
    // if (c == 1) {
      manuallyPlace(Board, ships, i);
    // }
    // else {
    //   randomlyPlace(Board, ships, i);
    // }
  }
}

void manuallyPlace(Cell Board[ROWS][COLS], Ship ships[], int current){

  int x1, x2, y1, y2, orientation, valid, placed = 0;
  while (placed == 0) {

    printf("This ship is %d cells long.\n", ships[current].length);
    printf("Would you like the ship to be (1) horizontal or (2) vertical?\nType in 1 or 2: ");
    scanf("%d", &orientation);

    while (orientation != 1 && orientation != 2) {
      printf("Please choose a valid option: ");
      scanf("%d", &orientation);
    }

    //taking in an x-coordinate
    printf("Enter the x-coordinate of initial position: ");
    scanf("%d", &x1);
    while (!isValidCoord(x1)) {
      printf("Please choose a valid x-coordinate: ");
      scanf("%d", &x1);
    }
    //y-coordinate
    printf("Enter the y-coordinate of initial position: ");
    scanf("%d", &y1);
    while (!isValidCoord(y1)) {
      printf("Please choose a valid y-coordinate: ");
      scanf("%d", &y1);
    }
>>>>>>> e277435afca1e564b2e5dda05e42070a749ca054

    //placing the ships
    if (orientation == 2) {
      x2 = x1;
      if (y1+ships[current].length > ROWS) {
        y2 = y1 - ships[current].length;
      }
      else {
        y2 = y1+ships[current].length;
      }
      valid = 1;
      int less, more;
        if (y1 < y2){
          less = y1;
          more = y2;
        }
        else{
          less = y2+1;
          more = y1+1;
        }
        for (int j = less; j <= more; j++){
          if (Board[j][x1].shipSymbol != ' '){
            valid = 0;
          }
        }
        if (valid){
          for (int j = less; j < more; j++){
            Board[j][x1].shipSymbol = ships[current].shipName;
          }
          placed = 1;
          system("clear");
          printBoard(Board);
        }
        else {
          printf("There is already a ship in that position, please choose another.\n");
          sleep(2);
          system("clear");
          printBoard(Board);
        }
      }
    else if (orientation == 1){
        y2 = y1;
        x2 = 0;
        if (x1+ships[current].length > COLS) {
          x2 = x1 - ships[current].length;
        }
        else {
          x2 = x1+ships[current].length;
        }
        int less, more;
        valid = 1;
        if (x1 < x2){
          less = x1;
          more = x2;
        }
        else{
          less = x2+1;
          more = x1+1;
        }
        for (int j = less; j <= more; j++){
          if (Board[y1][j].shipSymbol != ' '){
            valid = 0;
          }
        }
        if (valid){
          for (int j = less; j < more; j++){
            Board[y1][j].shipSymbol = ships[current].shipName;
          }
          placed = 1;
          system("clear");
          printBoard(Board);
        }
        else {
          printf("There is already a ship in that position, please choose another.\n");
          sleep(2);
          system("clear");
          printBoard(Board);
        }
      }

    }
  }

int isValidCoord(int coordinate) {
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 0;
  for (n = 0; n < 10; n++) {
    if (coordinate == nums[n]) {
      return 1;
    }
  }
  return 0;
}

int hit(Cell Board[ROWS][COLS], Ship ships[]) {
  int r, c, s, success = 0;
  char buf[256];
  printf("Your turn! Which position would you like to hit?\n");

  printf("Enter the x-coordinate: ");
  fgets(buf, sizeof(buf), stdin);
  c = atoi(buf);
  fflush(stdout);
  fflush(stdin);
  while (!isValidCoord(c)) {
    printf("Please choose a valid x-coordinate: ");
    fgets(buf, sizeof(buf), stdin);
    c = atoi(buf);
    fflush(stdout);
    fflush(stdin);
  }
  printf("Enter the y-coordinate: ");
  fgets(buf, sizeof(buf), stdin);
  r = atoi(buf);
  fflush(stdout);
  fflush(stdin);
  while (!isValidCoord(r)) {
    printf("Please choose a valid x-coordinate: ");
    fgets(buf, sizeof(buf), stdin);
    r = atoi(buf);
    fflush(stdout);
    fflush(stdin);
    // scanf("%d", &x1);

  int i = 0;
  if (Board[r][c].shipSymbol == WATER || Board[r][c].shipSymbol == HIT) {

    printf("You already targeted this position once. Choose another.\n");
    printf("Enter the x-coordinate: ");
    scanf("%d", &c);
    while (!isValidCoord(c)) {
      printf("Please choose a valid x-coordinate: ");
      scanf("%d", &c);
    }
    //y-coordinate
    printf("Enter the y-coordinate: ");
    scanf("%d", &r);
    while (!isValidCoord(r)) {
      printf("Please choose a valid y-coordinate: ");
      scanf("%d", &r);
    }

  }
  else if (Board[r][c].shipSymbol != ' ') { //checking there is a ship
    for (s = 0; s<5; s++) {
      if (Board[r][c].shipSymbol == ships[s].shipName) {
        ships[s].hits += 1; //adding hits to the corresponding ship
      }
    }
    printf("You hit a %c ship!\n", Board[r][c].shipSymbol);
    Board[r][c].shipSymbol = HIT;
    success = 1;
  }
  else {
    Board[r][c].shipSymbol = WATER;
    printf("Oops - you didn't hit anything\n");
  }
  return success;
}

int PlayerWins(Ship ships[]) {
  int n, sunk = 0;
  for (n = 0; n < 5; n++) {
    if (ships[n].hits == ships[n].length) {
      sunk++;
    }
  }
  // printf("ships sunk: %d\n", sunk);
  if (sunk == 5) {
    // printf("Player won!\n");
    return 1;
  }
  return 0;
}


void randomlyPlace(Cell Board[ROWS][COLS], Ship ships[], int current) {
  int x1, y1, x2, y2, j, valid, more, less = 0;
  int o;
  int placed = 0;
  srand(time(0));

  while (placed != 1) {
    o = rand()%2;
    if (o == 1) {
        y1 = rand()%10;
        x1 = rand()%10;
        if (x1+ships[current].length >= COLS) {
          x2 = x1-ships[current].length;
        }
        else {
          x2 = x1+ships[current].length;
        }
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
          }
        }
        if (valid) {
          for (j = less; j < more; j++){
            Board[y1][j].shipSymbol = ships[current].shipName;
          }
          placed = 1;
          // printf("placed one!\n");
        }
    }

    if (o == 0) {
      x1 = rand()%10;
      y1 = rand()%10;
      if (y1+ships[current].length >= ROWS) {
        y2 = y1-ships[current].length;
      }
      else {
        y2 = y1+ships[current].length;
      }
      if (y1<y2) {
        more = y2;
        less = y1;
      }
      else {
        more = y1+1;
        less = y2+1;
      }
      for (j = less; j < more; j++){
        if (Board[j][x1].shipSymbol != ' '){
          valid = 0;
        }
      }
      if (valid) {
        for (j = less; j < more; j++){
          Board[j][x1].shipSymbol = ships[current].shipName;
        }
        // printf("placed one!\n");
        placed = 1;
      }
    }
  }
  system("clear");
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
