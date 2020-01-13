#include "battleship.h"

int main(){

  // Create the game boards for both players
  Cell playerOneGameBoard[ROWS][COLS];       /* Player one game board */
	Cell playerTwoGameBoard[ROWS][COLS];       /* Player two game board */

  // Create ships
  Ship ship[NUM_OF_SHIPS] = {{'c', 5},
	                           {'b', 4},
	                           {'r', 3},
	                           {'s', 3},
	                           {'d', 2}};

  printWelcome();
}
