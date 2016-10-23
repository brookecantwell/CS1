/*
 * song.cpp
 *
 * Brooke Cantwell
 *
 * 29 October 2015
 *
 * Lab #5 - The 12 Days of Christmas
 *
 * Uses nested for() loops and switch
 * statements to sing "The 12 Days of
 * Christmas".
 *
 */


#include <iostream>

using namespace std;

main() {
	const int DAYS = 12;
	string firstName, day;
	char answer;

	// Ask user for their first name and if they want to start the program

	cout << "Hello, what is your first name?" << endl;
	cin >> firstName;

	cout << "Hello " << firstName << ", would you like to sing 'The 12 Days of Christmas?' (y/n)  " << endl;
	cin >> answer;
	

	while (answer == 'y' || answer == 'Y') {
		// For loop to control day number

		
		for (int i = 1; i <= DAYS; ++i) {
	
			// Switch statement assigns a string "day" to
			// use in the song
		
			switch (i) {
				case 1:
					day = "first";
					break;
				case 2:
					day = "second";
					break;
				case 3:
					day = "third";
					break;
				case 4:
					day = "fourth";
					break;
				case 5:
					day = "fifth";
					break;
				case 6:
					day = "sixth";
					break;
				case 7:
					day = "seventh";
					break;
				case 8:
					day = "eigth";
					break;
				case 9:
					day = "ninth";
					break;
				case 10:
					day = "tenth";
					break;
				case 11:
					day = "eleventh";
					break;
				case 12:
					day = "twelfth";
					break;		
			}

			// First part of the song, uses the string created in the switch statement

			cout << "On the " << day << " day of Christmas my true love gave to me " << endl;

			// For loop to control the number of gifts given

			for (int j = DAYS; j >= 1; j--) {

				if (j <= i)
		
					// Switch statement using gift counter variable
					// j to output gifts in the song
					
					switch (j) {
						case 1:
							cout << "a partridge in a pear tree." << endl;
							break;
						case 2:
							cout << "two turtle doves,\nand ";
							break;
						case 3:
							cout << "three french hens, ";
							break;
						case 4:
							cout << "four calling birds, ";
							break;
						case 5:
							cout << "five golden rings,\n";
							break;
						case 6:
							cout << "six geese a-laying,\n";
							break;
						case 7:
							cout << "seven swans a-swimming, ";
							break;
						case 8:
							cout << "eight maids a-milking, ";
							break;
						case 9:
							cout << "nine ladies dancing, ";
							break;
						case 10:
							cout << "ten lords a-leaping, ";
							break;
						case 11:
							cout << "eleven pipers piping, ";
							break;
						case 12:
							cout << "twelve drummers drumming, ";
							break;
					} // End switch statement	

			} // End inner for loop
		
			cout << endl;

		} // End outside for loop


	// Ask the user if they want to sing again
	
	cout << "Would you like to sing again? (y/n)" << endl;
	cin >> answer;

	}

}
