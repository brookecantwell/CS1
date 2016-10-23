/* 
 * Brooke Cantwell
 *
 * CISC1600 Final Exam
 *
 * 17 December 2015
 *
 * Generate a random number between a lower
 * and upper bound set by the user 100 times
 * and display the frequency each number
 * occured with a horizontal bar chart
 * representing the frequency of every 
 * number between the lower and upper bounds.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

main() {

	//local variables

	int rNum;
	int lower, upper;	
	const int REPEAT_TIMES= 100;
	char chart;

	//function declarations

	void getBounds(int&, int&);
	int getRandomNumber (int, int);
	void updateArray (int[ ], int);
	void summaryInformation(const int[ ], int, int);
	void displayChart (const int [ ], int, int);

	//seed for srand

	srand (time(0) );

	//function call for getBounds(), user inputs upper and lower bounds

	getBounds(lower, upper);

	//calculate the size of the array using the user input upper bound

	const int SIZE = upper + 1;

	//initialize all elements of counterArray[] to 0

	int counterArray[SIZE] = {0};

	//repeat getRandomNumber() and updateArray() a set number of times, generating 
	//a random number and incrementing the value of counterArray[rNum] each time

	for (int i = 0; i < REPEAT_TIMES; i++) {
		rNum = getRandomNumber(lower, upper);
		updateArray (counterArray, rNum);
	}

	//function call for summaryInformation (displays frequency of all numbers between
	//the upper and lower bounds

	summaryInformation(counterArray, lower, upper);

	//ask the user if they want to see the horizontal bar chart

	cout << endl << "To see a horizontal bar chart of the results, enter 'C' or 'c' (enter any other character to quit the program): ";
	cin >> chart;
	
	switch (chart) {
		case 'C':
		case 'c':
			//if the user enters 'C' or 'c' function call for displayChart()
			//outputting the bar chart
			displayChart (counterArray, lower, upper);
			break;
		default:
			cout << "OK! Goodbye." << endl;
	}

}
