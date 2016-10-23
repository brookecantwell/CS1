/*
 * arrayFunction.cpp
 *
 * Lab #9 - More Numbers Play
 *
 * Brooke Cantwell
 *
 * 5 December 2015
 *
 * Functions used in the array.cpp file
 */

#include <iostream>

using namespace std;

//function definition for inputArray( ), allows the user to
//populate an array until a sentinal value is entered
int inputArray (int arr[ ], const int SIZE, const int SENTINAL) {
	int counter = 0;

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter number " << i + 1 << " or " << SENTINAL << " to stop: ";
		cin >> arr[i];
		if (arr[i] == -999)
			break;
		else
			counter++;	
	}
	return(counter);
}

//function definition for displayArray( ), displays array contents until the
//number of elements input by the user is reached
void displayArray (const int arr[ ], int inputNumbers) {
	cout << "Position\tValue" << endl;
	cout << "-------\t\t-------" << endl;
	for (int i = 0; i < inputNumbers; i++) {
		if (arr[i] != -999)
			cout << i+1 << "\t\t" << arr[i] << endl;
	}
}

//function definition for arrayStatistics( ), calculates minimum, maximum, sum, and average for the array
void arrayStatistics (const int arr[ ], int inputNumbers, int&minimum, int&maximum, int&sum, double&average) {
	minimum = arr[0];
	maximum = arr[0];
	sum = 0;

	for (int i = 0; i < inputNumbers; i++) {
		if (arr[i] < minimum)
			minimum = arr[i];
		if (arr[i] > maximum)
			maximum = arr[i];
		sum += arr[i];
	}

	average = (double)sum / inputNumbers;
}

//function definition for countArray( ), counts instances of a specific number in the array
int countArray (const int arr[ ], int inputNumbers, int target) {
	int countNumber;	

	for (int i = 0; i < inputNumbers; i++) {
		if (arr[i] == target)
			countNumber++;	
	}
	return(countNumber);
}

//function definition for replaceNumber( ), replaces a specific number with another value
int replaceNumber (int arr[ ], int inputNumbers, int replaceThis, int replaceWith) {
	int replaceTimes;
	
	for (int i = 0; i < inputNumbers; i++) {
		if (arr[i] == replaceThis) {
			arr[i] = replaceWith;
			replaceTimes++;
		}
	}
	return(replaceTimes);
}

//function definition for modifyElement( ), allows the user to modify an element if
//the boolean value validModification is true (aka the user input a valid position)
bool modifyElement(int arr[ ], int inputNumbers, int modifyPosition, int modifyValue) {
	bool validModification;

	if (modifyPosition > inputNumbers)
		validModification = false;
	else
		validModification = true;

	if (validModification == true) 
		arr[modifyPosition - 1] = modifyValue;	

	return(validModification);
}

//function definition for clearElement( ), allows the user to clear a specific element
//of the array or the entire array based on used input
void clearElement (int arr[ ], int inputNumbers, int clearPosition) {
	if (clearPosition == -1) {
		for (int i = 0; i < inputNumbers; i++) {
			arr[i] = 0;
		}
	}
	else
		arr[clearPosition - 1] = 0;
}
