/*
 * Tic-Tac-Toe Functions
 *
 * Brooke Cantwell
 *
 * 21 December 2015
 *
 * Functions used in the Tic Tac Toe
 * game (game.cpp)
 *
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game2.h"
#include <iomanip>

using namespace std;


//function definition for displayBoard(), displays the game board
//replacing the integers with either X or O depending on the player
void displayBoard(const int board[][COL], char playerChars[]) {	

	cout << endl << " +---+---+---+" << endl;

	for (int r = 0; r < ROW; r++) {

		for (int c = 0; c < COL; c++) {
			cout << " | ";			

			if (board[r][c] == player1value)
				cout << playerChars[0];
			else 
			if (board[r][c] == player2value)
				cout << playerChars[1];
			else
				cout << ' ';
			
		}
		cout << " |" << endl << " +---+---+---+" << endl;
	}

	cout << endl;
}

//function definition for randomNumberGenerator (determines player numbers)
int randomNumberGenerator () {
	int rNum;

	rNum = rand() % 2;

	return(rNum);
}


//function definition for play(), allows players to input the row and column
//they want to play and alerts them if the numbers are invalid or it the
//location is already taken
void play (int board[][COL], int player, int i, int&turns, string players[], string playerNumbers[]) {

	int row, col;
	char dummyVar;

	cout << players[i] << ": " << playerNumbers[i] << endl;
	cout << "Enter slot to play in the format ROWxCOLUMN: ";
	cin >> row >> dummyVar >> col;

	//the the input row or column is larger than the  board, or the position
	//is already filled, alert the user and ask for another slot
	if (row > ROW || col > COL) {
		cout << "That is not a valid position! Please re-enter: ";
		cin >> row >> dummyVar >> col;
	}
	if (board[row-1][col-1] != 0) {
		cout << "That position is already taken! Please re-enter: ";
		cin >> row >> dummyVar >> col;
	}	

	row--;
	col--;
	
	board[row][col] = player;

	turns++;

}

//function definition for checkWinner(), sums up rows, columns, and diagonals
bool checkWinner (const int board[][COL], int&winner) {
	int sum = 0;
	int dSumL = 0, dSumR = 0;
	bool win = false;	


	bool playerCompare (int, int, int&);

	//check diagonal for winner
	
	//diagonal left to right
	for (int r = 0, c = 0; r < ROW; r++, c++) {
		dSumL += board[r][c];
	}

	//diagonal right to left
	for (int r = 0, c = COL-1; c >= 0; r++, c--) {
		dSumR += board[r][c];
	}
	

	//compare to player1sum and player2sum
	//playerCompare() only work for rows and columns
	
	if (dSumL == player1sum || dSumR == player1sum) {
		win = true;
		winner = 1;
	}
	else
	if (dSumL == player2sum || dSumR == player2sum) {
		win = true;
		winner = 2;
	}
	else {
		win = false;
	}
		

	//check rows for winners
	for (int r= 0; r < ROW && !win; r++) {
		sum = 0;		
		for (int c = 0; c < COL; c++) {
			sum += board[r][c];
		}		
	win = playerCompare(sum, win, winner);			
	}

	//check columns for winners

	for (int c= 0; c < COL && !win; c++) {
		sum = 0;
		for (int r = 0; r < ROW; r++) {
			sum += board[r][c];
		} 
	win = playerCompare(sum, win, winner);
	}

	return(win);
}

//function definition for playerCompare() used in checkWinner() compares
//the sum of the rows and colums to player1sum and player1sum, returns the
//boolean variable win and changes the value of the winner variable
bool playerCompare (int sum, int win, int&winner) {
	
	if (sum == player1sum) {
		win = true;
		winner = 1;
	}
	else
	if (sum == player2sum) {
		win = true;
		winner = 2;
	}
	else
		win = false;

	return(win);

}

//function definition for switchPlayers(), switches the player
//after every turn using 0 for player 1 and 1 for player 2 so
//that the new player variable can be used as an index for the
//player array
int switchPlayers (int i) {

	int newPlayer;

	switch (i) {
		case 0:
			newPlayer = 1;
			break;
		case 1:
			newPlayer = 0;
	}

	return(newPlayer);
}

//determine the lower of the game and set them to play first the next round
int determineLoser(int winner) {
	int i;

	if (winner == 1)
		i = 1;
	else
	if (winner == 2)
		i = 0;

	return(i);
}


//function definition for clearBoard(), resets every slot in the board
//to zero before the next game
void clearBoard (int board[][COL]) {
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++)
			board[r][c] = 0;
	}

}

//function definition for trackScore(), after a winner is found takes the winner
//and stores it in the array gameWinner[] with the index game (counter variable) 
//for showScoreBoard() and  increments the counter for each player when they win
void trackScore (int gameWinner[], int games, int winner, int&player1wins, int&player2wins) {

	switch(winner) {
		case 1:
			player1wins++;
			gameWinner[games] = 1;
			break;
		case 2:
			player2wins++;	
			gameWinner[games] = 2;
	}
}


//function definition for showScoreBoard, outputs the value of the gameWinner[] array
//so users can see a scoreboard, the number of games won by each player and display a
//message based on relational operations between the number of games won by each player	

void showScoreBoard (int gameWinner[], int games, int player1wins, int player2wins, string playerNumbers[], string players[]) {

	int mostWins;

	cout << endl << "Score Board and Game Summary: " << endl << endl;

	//use a loop to output player numbers and names	
	for (int p = 0; p < 2; p++) {
		cout << players[p] << ": " << playerNumbers[p] << endl;
	}

	cout << endl << "Game\tWinner" << endl;
	cout << "--------------------" << endl;

	//use a loop to output the winner of each game that was played, or output
	//'tie' if there was no winner (aka gameWinner[i] == 0)
	for (int i = 0; i < games; i++) {
		if (gameWinner[i] != 0) {
			cout << i+1 << "\t("  << gameWinner[i] << "): ";
				if (gameWinner[i] == 1)
					cout << playerNumbers[0] << endl;
				else
					cout << playerNumbers[1] << endl;
		}
		else
			cout << i+1 << '\t' << "Tie" << endl;
	}

	//display the number of games won by each player
	cout << endl << "Games Won:" << endl << "----------" << endl;
	cout << playerNumbers[0] << ": " << player1wins << endl;
	cout << playerNumbers[1] << ": " << player2wins << endl << endl;

	//determine who won the most games and use that variable to decide which
	//player index is used in the congratulations statement
	if (player1wins != player2wins) {
		if (player1wins > player2wins)
			mostWins = 0;
		else
			mostWins = 1;

		cout << "Congratulations " << playerNumbers[mostWins] << " (" << players[mostWins] << ") you won the most games!" << endl;

	}
	else
	//if there is a tie let the players know
	if (player1wins == player2wins)
		cout << "Looks like an even match up! " << playerNumbers[0] << " and " << playerNumbers[1] << " won the same number of games!" << endl;
	
}

