#include "networking.h"
#include "game.h"

void readBoard(Cell Board[ROWS][COLS], char buffer[256], int socket);
void sendBoard(Cell Board[ROWS][COLS], char buffer[256], int socket);
void printGame(Cell me[ROWS][COLS], Cell opp[ROWS][COLS]);

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];

  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  // Create the game boards for both players
  Cell playerOne[ROWS][COLS];       /* Player one game board */
  Cell playerTwo[ROWS][COLS];       /* Player two game board */

  // Create ships
  Ship ship1[NUM_SHIPS] = {{'c', 5},
                          {'b', 4},
                          {'r', 3},
                          {'s', 3},
                          {'d', 2}};

  Ship ship2[NUM_SHIPS] = {{'c', 5}, {'b', 4}, {'r', 3}, {'s', 3}, {'d', 2}};

  // printWelcome();
  initializeBoard(playerOne);
  initializeBoard(playerTwo);

  placeShips(playerTwo, ship2);
  printf("Waiting for Player One...\n");


  // sendBoard(playerTwo, buffer, server_socket);
  // readBoard(playerOne, buffer, server_socket);
  write(server_socket, playerTwo, sizeof(playerTwo));
  read(server_socket, playerOne, sizeof(playerOne));

  write(server_socket, ship2, sizeof(ship2));
  read(server_socket, ship1, sizeof(ship1));

  printf("TESTING: %c\n\n", playerOne[2][3].shipSymbol);
  printGame(playerTwo, playerOne);
  // read(server_socket, bufferb, sizeof(bufferb));
  printf("Waiting for Player One...\n");
  printf("Both players are ready! Game is starting...\n\n");
  sleep(3);

  while (!PlayerWins(ship1) && !(PlayerWins(ship2))) {

    system("clear");
    printGame(playerTwo, playerOne);
    printShips(ship2, ship1);
    read(server_socket, playerTwo, sizeof(playerTwo));
    read(server_socket, ship2, sizeof(ship2));
    hit(playerOne, ship1);
    write(server_socket, playerOne, sizeof(playerOne));
    write(server_socket, ship1, sizeof(ship1));
  }
  if (PlayerWins(ship1)) {
    printf("Player one won!!\n");
  }
  else {
    printf("Player two won :(\n");
  }
  close(server_socket);
  exit(0);
}

void readBoard(Cell Board[ROWS][COLS], char buffer[256], int socket){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      read(socket, buffer, 256);
      // fgets(buffer, 256, socket);
      Board[i][j].shipSymbol = buffer[0];
    }
  }
}

void sendBoard(Cell Board[ROWS][COLS], char buffer[256], int socket){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      buffer[0] = Board[i][j].shipSymbol;
      write(socket, buffer, 256);
    }
  }
}

void printGame(Cell me[ROWS][COLS], Cell opp[ROWS][COLS]){
  system("clear");
  printBoards(me, opp);
}
