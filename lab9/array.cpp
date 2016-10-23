/*
 * array.cpp
 *
 * Lab #9 - More Numbers Play
 *
 * Brooke Cantwell
 *
 * 5 December 2015
 *
 * Allows the user to populate an array with integer values
 * displays the array, and then offers options to create a 
 * new array, receieve statistics, count numbers in the array,
 * replace numbers, modify elements, or clear elements / the
 * entire array. 
 */


#include <iostream>
#include <iomanip>

using namespace std;

main() {

	//LOCAL VARIABLES
	
	//maximum array size, sentinal value
	const int SIZE = 15, SENTINAL = -999;
	//initialize all SIZE elements of array to 0
	int arr[SIZE] = {0};
	//inputNumbers(returned from inputArray( ) - actual number of elements entered by the user
	int inputNumbers;
	//local variables used in arrayStatistics( )
	int minimum, maximum, sum;
	double average;
	//local variables used in countArray( )
	int target, countNumber;
	//allows user to specify choice
	char choice, makeNewChoice;
	//variables used in replaceNumber( )
	int replaceThis, replaceWith, replaceTimes;
	//variables used in modifyElement( )
	int modifyPosition, modifyValue;
	bool validModification;
	//variables used in clearElement( )
	int clearPosition;

	//function declarations
	int inputArray (int[ ], const int, const int);
	void displayArray (const int[ ], const int);
	void arrayStatistics (const int[ ], int, int&, int&, int&, double&);
	int countArray(const int[ ], int, int);
	int replaceNumber(int[ ], int, int, int);
	bool modifyElement(int[ ], int, int, int);
	void clearElement(int[ ], int, int);

	//welcome the user to the program and invoke inputArray( ) to populate the array and return the number of elements
	//entered by the user
	cout << "Welcome to the world of Arrays!" << endl;
	cout << "To begin, enter the contents of your first array (maximum " << SIZE << " numbers). You can input a new array through the menu later in the program." << endl;

	inputNumbers = inputArray(arr, SIZE, SENTINAL);

	//display the array
	cout << "You have entered: " << endl;
	displayArray(arr, inputNumbers);

	//offer menu options until the user chooses to exit the menu
	do {
	
	//display menu options
	cout << "Please choose from the following menu options: " << endl;
	cout << "To input new values into the array, enter 'I' or 'i'." << endl;
	cout << "To see statistics, enter 'S' or 's'." << endl;
	cout << "To count an element, enter 'C' or 'c'." << endl;
	cout << "To replace an element, enter 'R' or 'r'." << endl;
	cout << "To modify an element, enter 'M' or 'm'." << endl;
	cout << "To clear an element, or the entire array, enter '0'." << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	//switch on variable choice to invoke function depending on what the user chose from the menu
	switch(choice) {
		case 'I':
		case 'i':
			//allow the user to input a new array
			inputNumbers = inputArray(arr, SIZE, SENTINAL);
			cout << "You have changed your array to:" << endl;
			displayArray(arr, inputNumbers);
			break;
		case 'S':
		case 's':
			//calculate and display statistics with arrayStatistics( )
			arrayStatistics (arr, inputNumbers, minimum, maximum, sum, average);

			cout << "Statistics: " << endl;
			cout << "Minimum: " << minimum << endl;
			cout << "Maximum: " << maximum << endl;
			cout << "Sum: " << sum << endl;
			cout << setprecision(4) << "Average: " << average << endl;
			break;
		case 'C':
		case 'c':
			//count occurances of a specific number with countArray( )
			cout << "Enter the number you would like to count: ";
			cin >> target;
			countNumber = countArray(arr, inputNumbers, target);	
			cout << "The number " << target << " appears " << countNumber << " times." << endl;
			break;

		case 'R':
		case 'r':
			//allow users to chose a number to replace with replaceNumber( ) and display the number of replacements made
			cout << "Enter the number you would like to replace: ";
			cin >> replaceThis;
			cout << "Enter the new value: ";
			cin >> replaceWith;
			replaceTimes = replaceNumber(arr, inputNumbers, replaceThis, replaceWith);
			cout << "The number " << replaceThis << " was replace with " << replaceWith << " " << replaceTimes << " times." << endl;
			//display new array
			cout << "Your array is now: " << endl;
			displayArray(arr, inputNumbers);
			break;
		case 'M':
		case 'm':
			//alow the user to modify a specific position with modifyElement
			cout << "Enter position to modify: ";
			cin >> modifyPosition;

			validModification = modifyElement(arr, inputNumbers, modifyPosition, modifyValue);

			//if the boolean function modifyElement returns false prompt the user to enter a valid position until it returns true
			if (validModification == false) {
				while (validModification == false) {
					cout << "That is an invalid position, please enter a position between 1 and " << inputNumbers << ": ";
					cin >> modifyPosition;
					validModification = modifyElement(arr, inputNumbers, modifyPosition, modifyValue);
				}
			}
			//if validModification is true ask for a new value to put into the array
			if (validModification == true) {
				cout << "Enter the new value: ";
				cin >> modifyValue;
				modifyElement(arr, inputNumbers, modifyPosition, modifyValue);
				//display the new array
				cout << "Your array is now: " << endl;
				displayArray(arr, inputNumbers);
			}
			break;

		case '0':
			//allow the user to clear a speific element / the whole array with clearElement( )
			cout << "What position would you like to clear? Enter the position or -1 to clear the entire array: ";
			cin >> clearPosition;
			clearElement (arr, inputNumbers, clearPosition);
			//display the new array
			cout << "Your array is now: " << endl;
			displayArray(arr, inputNumbers);
			break;
		default:
			//alert the user if they have entered an invalid menu option
			cout << "You have chosen an invalid menu option." << endl;
			
	}
	
	//ask the user if they want to choose another meny option
	cout << "Would you like to choose another menu option? (y/n): ";
	cin >> makeNewChoice;
	
	} while (makeNewChoice == 'Y' || makeNewChoice == 'y');
	//end do {menu options} while the user assigns "yes" to makeNewChoice

	//once the user quite the menu display a goodbye message
	cout << "Goodbye!" << endl;
		
}
