#include "game.h"

int main(){

  // Create the game boards for both players
  Cell playerOne[ROWS][COLS];       /* Player one game board */
	Cell playerTwo[ROWS][COLS];       /* Player two game board */

  // Create ships
  Ship ship[NUM_SHIPS] = {{'c', 5,},
	                           {'b', 4},
	                           {'r', 3},
	                           {'s', 3},
	                           {'d', 2}};

  //creating coordinate arrays for the ships
  // int n = 0;
  // for (n = 0; n++; n<NUM_SHIPS) {
  //   Coordinate coords[ship[n].length];
  //   printf("coords lengths: %d\n", ship[n].length);
  //   ship[n].coordinates = coords;
  // }
  //
  // printWelcome();
  initializeBoard(playerOne);
  initializeBoard(playerTwo);
  printBoard(playerOne);

  placeShips(playerOne, ship);
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
