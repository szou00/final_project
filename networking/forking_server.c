#include "networking.h"
#include "game.h"

void process(char *s);
void subserver(int from_client);
void readBoard(Cell Board[ROWS][COLS], char buffer[256], int socket);
void sendBoard(Cell Board[ROWS][COLS], char buffer[256], int socket);
void printGame(Cell me[ROWS][COLS], Cell opp[ROWS][COLS]);

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup();

  while (1) {

    printf("Waiting for Player Two to connect...\n");
    int client_socket = server_connect(listen_socket);
    printf("Player Two has connected! Now starting the game. \n");

    // Create the game boards for both players
    Cell playerOne[ROWS][COLS];       /* Player one game board */
    Cell playerTwo[ROWS][COLS];       /* Player two game board */

    // Create ships
    Ship ship[NUM_SHIPS] = {{'c', 5},
                           {'b', 4},
                           {'r', 3},
                           {'s', 3},
                           {'d', 2}};

    // printWelcome();
    initializeBoard(playerOne);
    initializeBoard(playerTwo);
    printBoard(playerOne);

    placeShips(playerOne, ship);

    printGame(playerOne, playerTwo);

    char buffer[BUFFER_SIZE];

    readBoard(playerTwo, buffer, client_socket);
    sendBoard(playerTwo, buffer, client_socket);
    printf("TESTING: %c\n\n", playerTwo[2][3].shipSymbol);


    while (read(client_socket, buffer, sizeof(buffer))) {

      printf("[subserver %d] received: [%s]\n", getpid(), buffer);
      process(buffer);
      write(client_socket, buffer, sizeof(buffer));
    }//end read loop
    close(client_socket);
    exit(0);
    // f = fork();
    // if (f == 0)
    //   subserver(client_socket);
    // else
    //   close(client_socket);
  }
}

// void subserver(int client_socket) {
//   char buffer[BUFFER_SIZE];
//
//   while (read(client_socket, buffer, sizeof(buffer))) {
//
//     printf("[subserver %d] received: [%s]\n", getpid(), buffer);
//     process(buffer);
//     write(client_socket, buffer, sizeof(buffer));
//   }//end read loop
//   close(client_socket);
//   exit(0);
// }

void process(char * s) {
  while (*s) {
    if (*s >= 'a' && *s <= 'z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    else  if (*s >= 'A' && *s <= 'Z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    s++;
  }
}

void readBoard(Cell Board[ROWS][COLS], char buffer[256], int socket){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      read(socket, buffer, 256);
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
  printf("Player Two's Board\n\n");
  printBoard(opp);
  printf("\n\n\nYour Board\n\n");
  printBoard(me);
}

// void sendBoard(Cell Board, int client_socket, char buffer[][], int size){
//   for (int i = 0; i < 10; i++){
//     for (int j = 0; j < 10; j++){
//       buffer[i][j] = Board[i][j];
//     }
//     write(server_socket, bufferb, sizeof(bufferb));
//   }
// }