/*
 * guessFunction.cpp
 *
 * Brooke Cantwell
 *
 * 5 November 2015
 *
 * Function used in the guess.cpp program.
 *
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// generateNumber function - generates a random number
// between some min and max value and returns rNum

signed int generateNumber (signed int min, signed int max) {

	signed int rNum;

	srand( time(0) );
	rNum = rand() % max + min;
	return(rNum);

}

// compare functions, compares the random number to the guessed
// number and returns the boolean variable sameNumber

bool compare (int rNum, int guess) {

	bool sameNumber;

	if (rNum == guess)
		sameNumber = 1;
	if (rNum != guess)
		sameNumber = 0;
	return (sameNumber);
}
