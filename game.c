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
  int x1, x2, y1, y2, orientation, valid;
  for (int i = 0; i < NUM_SHIPS; i++){
    int placed = 0;
    while (!placed){
      printf("This ship is %d cells long.\n", ships[i].length);
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
        if (y1+ships[i].length > ROWS) {
          y2 = y1 - ships[i].length;
        }
        else {
          // printf("y2: %d\n", y2);
          y2 = y1+ships[i].length;
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
              Board[j][x1].shipSymbol = ships[i].shipName;
              Board[j][x1].thisShip = ships[i];
              Board[y1][j].thisShip.hits = 0;
            }
            placed = 1;
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
        if (x1+ships[i].length > COLS) {
          x2 = x1 - ships[i].length;
        }
        else {
          // printf("x2: %d\n", x2);
          x2 = x1+ships[i].length;
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
            Board[y1][j].shipSymbol = ships[i].shipName;
            Board[y1][j].thisShip = ships[i];
            Board[y1][j].thisShip.hits = 0;
            // printf("number of hits: %d\n", Board[y1][j].thisShip.hits);
          }
          placed = 1;
          system("clear");
          printBoard(Board);
        }
        else {
          printf("ships are overlapping\n");
        }
      }
    }
  }
}

void hit(Cell Board[ROWS][COLS], Ship ships[]) {
  int r, c, s;
  printf("Your turn! Which position would you like to hit?\n");
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
  printf("ships sunk: %d\n", sunk);
  if (sunk == 5) {
    printf("Player won!\n");
    return 1;
  }
  return 0;
}

int createFile() {
  shmid = semget(KEY_2, 1, IPC_CREAT | 0644);
  if (shmid < 0) {
    printf("SEMAPHORE error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  semctl(shmid, 0, SETVAL, sm);
  shmd = shmget(KEY_1, sizeof(char *), IPC_CREAT | 0644);
  if (shmd < 0) {
    printf("MEMORY error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  fd = open("file.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
  if (fd < 0) {
    printf("FILE error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  close(fd);
  return 0;
}

int writeToFile(Cell Board[ROWS][COLS]) {
  int r,c;
  char next_line[1000];
  printf("trying to get in\n");
  //checking semaphore
  shmid = semget(KEY_2, 1, 0);
  if (shmid < 0) {
    printf("semaphore error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  semop(shmid, &semaphore, 1);
  //checking memory
  shmd = shmget(KEY_1, sizeof(char *), 0);
  if (shmd < 0) {
    printf("memory error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  //opening file
  FILE *fd = fopen("file.txt", "w");
  //printing last addition
  for (r=0; r<ROWS; r++) {
    for (c = 0; c<COLS;c++) {
      fprintf(fd, "%c", Board[r][c].shipSymbol);
    }
  }
  fclose(fd);
  //release memory
  semaphore.sem_op = 1;
  //release semaphore
  semop(shmd, &semaphore, 1);
  return 0;
}

int viewGame() {
  FILE *fd = fopen("file.txt", "r");
  char lines;
  if (fd == NULL) {
    printf("error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  lines = fgetc(fd);
  printf("the board:\n");
  while (lines != EOF) {
    printf("%c", lines);
    lines = fgetc(fd);
  }
  fclose(fd);
  return 0;
}

int removeFile() {
  printf("checking if semaphore is available\n");
  shmid = semget(KEY_2, 1, 0); //checks if semaphore is open
  if (shmid < 0) {
    printf("error %d: %s\n", errno, strerror(errno));
    return errno;
  }

  semop(shmid, &semaphore,1);

  //printing contents
  viewGame();

  shmd = shmget(KEY_1, 1, 0);
  if (shmd < 0) {
    printf("Trying to viewing the file you got shared memory error %d: %s\n", errno, strerror(errno));
    return errno;
  }

  //removing memory
  if (shmctl(shmd, IPC_RMID, 0) == -1) {
    printf("in removing u have shared memory error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  printf("\nshared memory removed\n");

  //removing semaphore
  if (semctl(shmid, IPC_RMID, 0) == -1) {
    printf("SEMAPHORE error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  printf("semaphore removed\n");

  //removing file
  if (remove("file.txt")) {
    printf("FILE error %d: %s\n", errno, strerror(errno));
    return errno;
  }
  printf("file removed\n");

  return 0;
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
