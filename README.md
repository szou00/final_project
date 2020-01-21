# FINAL PROJECT: Battleship

## Team Members
- Sharon Zou, Period 4
- William Lin, Period 4

## Description of the Project
For our final project, we decided to recreate the game Battleship. Battleship is a strategic guessing game between two players. It is played on two 10 by 10 grids. Each player begins the game by marking the positions they want their fleets to be. These positions are concealed from the other player, who will take a guess and choose a position to shoot at. Depending on whether the player guesses correctly or not, the board will correspondingly display a symbol in the position they shot at. The objective of the game is to destroy all of the opponent's fleet.

## Description of User Interface
Since battleship is a two-player game, the game will begin once both players connect. First, each player will input their names. Then, they will be able to choose the positions at which they would like to store their ships for the game. Once both players have finished placing their ships, the first player to have connected will start off the attack. His/her board will be displayed on the left (with their own ships displayed), while the opponent's board will be displayed on the right (with the ships hidden). The status of each player's ships will be displayed respectively below. For each turn, the game will prompt them to enter the x and y coordinates of the position they choose to attack next.

## Description of Technical Design
- Allocating memory: At the beginning of the game, memory is allocated to remember the names of the players and the position of their ships.
- Signals: When a player makes an error in entering their names or in the placement of their ships, messages are returned accordingly.
- Shared Memory:
- Networking: The two players rely on networking to communicated board and ship statuses.

## Instructions
```
 $ git clone git@github.com:szou00/final_project.git
 $ cd final_project
 $ make
```
In one terminal, type in `./server` to launch Player One
In a second terminal within the same folder, type in `./client` to launch Player Two
