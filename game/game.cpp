/*
 *
 * Tic-Tac-Toe Game
 *
 * Brooke Cantwell
 *
 * 21 December 2015
 *
 * Allows users to play multiple Tic-Tac-Toe 
 * games and see a scoreboard at the end showing
 * who won each game, statistics about games won,
 * and outputting a message depending on who won
 * the most games or if there was a tie.
 *
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
//header file
#include "game2.h"

using namespace std;

main() {

	//local variables
	const int MAXGAMES = 30;
	int board[ROW][COL] = {0};
	int player[numPlayers] = {player1value, player2value};
	int gameWinner[MAXGAMES] = {0};
	string name1, name2, player1, player2;
	string players[numPlayers] = {"Player #1", "Player #2"};
	string playerNumbers[numPlayers] = {" ", " "};
	string playerNames[numPlayers] = {name1, name2};
	char playerChars[numPlayers] = {'X','O'};
	int rNum;
	bool win = false;
	int turns = 0;
	int winner, player1wins = 0, player2wins = 0;
	int currentPlayer;
	char playAgain = 'y';
	int games = 0;
	char scoreBoard;

	//function declarations / prototypes
	void displayBoard(const int[][COL], char[]);
	int randomNumberGenerator ();
	void play (int[ ][COL], int, int, int&, string[], string[]);
	bool checkWinner (const int [][COL], int&);
	int switchPlayers (int);
	int determineLoser(int);
	void clearBoard (int[ ][COL]);
	void trackScore (int[ ], int, int, int&, int&);
	void showScoreBoard (int[ ], int, int, int, string[ ], string[ ]);

	cout << "Welcome to Tic Tac Toe in C++!" << endl;
	
	//prompt for player names and store them in the playerNames[] array
	cout << "Enter the name of the first player: ";
	cin >> playerNames[0];

	cout << "Enter the name of the second player: ";
	cin >> playerNames[1];
	
	//randomize name1 and name2 to player number / x and o

	srand (time(0) );

	rNum = randomNumberGenerator();

	switch (rNum) {
		case 0:
			playerNumbers[0] = playerNames[0];
			playerNumbers[1] = playerNames[1];
			break;
		case 1:
			playerNumbers[0] = playerNames[1];
			playerNumbers[1] = playerNames[0];

	}

	//use a for loop to display contents of arrays containing player numbers, names, and characters
	for (int p = 0; p < 2; p++) {
		cout << players[p] << ": " << playerNumbers[p] << " is " << playerChars[p] << endl;
	}

	int i = 0;

	while (playAgain == 'y' || playAgain == 'Y' && games < MAXGAMES) {
		//initialize / reinitialized the turn count to zero
		turns = 0;

		cout << endl << "GAME #" << games + 1 << '!' << endl;

		displayBoard(board, playerChars);

		while (win == false) {

	 		//prompt the player for the row and column they want to play and store their
	 		//integer value in that spot in the aray
			play(board, player[i], i, turns, players, playerNumbers);

			cout << players[i] << " played:" << endl;

			//display the board using 'X' and 'O' characters
			displayBoard(board, playerChars);

			//check rows, columns, and diagonals for a winner
			win = checkWinner(board, winner);

			if (win == true) {
				//use trackScore() to increment either player1wins or player2wins
				//depending on the winner and store the winner (either 1 or 2) into
				//the gameWinner[] array using games as the index
				trackScore(gameWinner, games, winner, player1wins, player2wins);
				break;
			}
			else
			//if there have been 9 turns and no winner (a tie) break from the loop and ask if the
			//user wants to play again
			if (turns >= 9 && !win) {
				cout << "There has been a tie!" << endl;
				break;
			}

			else
				//switch i to the next play so their integer value is used in the play() function
				i = switchPlayers(i);	

		}

		//if there was a winner (and not a tie) use determineLoser() to find the loser and set them
		//to play first during the next game
		if (win == true) {
			cout << "Player #" << winner << " won!" << endl;
			i = determineLoser(winner);
		}
	
		//ask the user if they want to play again
		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;

		//clear the board
		clearBoard(board);

		win = false;	

		//increment the number of games to use in the gameWinner[] array
		games++;	
		
	} //while play again == y

	//ask the user if they want to see a score board (the number of games won, who won which games, and messages
	//depending on the number of games won
	cout << "Would you like to see a score board? (y/n): ";
	cin >> scoreBoard;

	switch(scoreBoard) {
		case 'Y':
		case 'y':
			showScoreBoard (gameWinner, games, player1wins, player2wins, playerNumbers, players);
			break;
		case 'N':
		case 'n':
			cout << "OK! Goodbye!" << endl;
			break;

	}

}
