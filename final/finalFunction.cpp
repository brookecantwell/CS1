/* 
 * Brooke Cantwell
 *
 * CISC1600 Final Exam
 *
 * 17 December 2015
 *
 * Functions used in final.cpp
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


//function definition for getBounds(), prompts the user to input upper and lower bounds, and if the
//lower bound given by the user is less than zero alert the user and prompt them for another lower bound
void getBounds (int&lower, int&upper) {

	cout << "Enter the lower bound for the range of possible numbers: ";
	cin >> lower;

	while (lower < 0) {
		cout << "The minimum value for the lower bound is 0. Enter lower bound: ";
		cin >> lower;
	}
	
	cout << "Enter the upper bound for the range of possible numbers: ";
	cin >> upper;
}

//function definition for getRandomNumber(), generates a random number between the upper and lower
//bounds (inclusive) input by the user
int getRandomNumber(int lower, int upper) {
	int rNum;
	
	rNum = rand() % (upper - lower + 1) + lower;

	return(rNum);
}

//function definition for updateArray(), use the random number that was generated as the index of the
//array to increment the value to represent frequency
void updateArray (int counterArray[ ], int rNum) {
	
	counterArray[rNum]++;

}

//function definition for summaryInformation(), displays the number of times every number between the
//upper and lower bounds was generated
void summaryInformation (const int counterArray[ ], int lower, int upper) {

	cout << "Summary Information: " << endl << endl;

	for (int i = lower; i <= upper; i++) {
		cout << "The number " << i << " was generated " << counterArray[i] << " times." << endl;
	}
}

//function definition for displayChart(), outputs the frequency of the numbers as a bar chart
void displayChart (const int counterArray[ ], int lower, int upper) {
	

	cout << endl << "Number\tFrequency" << endl << endl;
	for (int i = lower; i <= upper; i++) {
		cout << i << '\t';
		for (int j = 0; j < counterArray[i]; j++) {
			cout << '*';
		}
	cout << endl;
	}
}
