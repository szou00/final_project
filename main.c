#include "game.h"

int main(){

  // Create the game boards for both players
  Cell playerOne[ROWS][COLS];       /* Player one game board */
	Cell playerTwo[ROWS][COLS];       /* Player two game board */

  // Create ships
  Ship ship1[NUM_SHIPS] = {{'c', 5,},
	                           {'b', 4},
	                           {'r', 3},
	                           {'s', 3},
	                           {'d', 2}};

  Ship ship2[NUM_SHIPS] = {{'c', 5,},
                          {'b', 4},
                          {'r', 3},
                          {'s', 3},
                          {'d', 2}};

  //
  printWelcome();
  // createFile();
  initializeBoard(playerOne);
  // viewGame();
  initializeBoard(playerTwo);

  // printf("Hey Player One! Place your ships:\n");
  // placeShips(playerOne, ship1);
  // writeToFile(playerOne);
  // system("clear");
  // printf("Hey Player Two! Place your ships\n");
  // placeShips(playerTwo, ship2);
  // system("clear");
  int p = 0; //0 is player one
  // while (!PlayerWins(ship1) && !PlayerWins(ship2)) {
  //   if (p == 0) { //player one goes
  //     printf("Player One, ");
  //     hit(playerTwo, ship2); //they use player 2's board and ship
  //     p = 1;
  //   }
  //   else { //player two goes
  //     printf("Player Two, ");
  //     hit(playerOne, ship2); //they use player 1's board and ship
  //     p = 0;
  //   }
  //
  // }
  // removeFile();

  // placeShips(playerTwo, ship);
  // printBoard(playerTwo);

  // Randomly chooses who should go first;
  int player = 1;
  // randomizePositions(playerOne, ship);

  // while (1){
  //   switch(player){
  //
  //     case(PLAYER_ONE):
  //       printf("Player 2's Board\n");
  //       printBoard(playerTwo);
  //
  //     case(PLAYER_TWO):
  //       printf("Player 1's Board\n");
  //       printBoard(playerTwo);
  //   }
  // }
  return 0;
}
