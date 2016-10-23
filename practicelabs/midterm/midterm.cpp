/*
 * midterm.cpp
 *
 * Brooke Cantwell
 *
 * 22 October 2015
 *
 * Asks the user if they want to
 * draw a line, asks the user to
 * specify the kind of line they
 * want to draw, the length, and
 * the character, and outputs the
 * line and asks the user if they
 * want to draw another line.
 *
 */



#include <iostream>

using namespace std;

main () {
	char answer, lineType, direction, character;
	int length;

	// Ask the user if they want to draw a line

	cout << "Would you like to draw a line? (y/n) ";
	cin >> answer;

	// Begin while loop, continue to draw lines until the user enters 'N' or 'n'

	while (answer != 'n' && answer != 'N') {

		// Ask the user what kind of line they want to draw

		cout << "Would you like to draw a (v)ertical, (h)orizontal, or (d)iagonal line? ";
		cin >> lineType;
		
		// If the user wants to draw a diagonal line ask them what direction they want it to go in
		
		if (lineType = 'd') {

			cout << "Would you like a (r)ight facing line or a (l)eft facing line? ";
			cin >> direction;			
		}

		// Ask for length and what kind of character to use

		cout << "Enter length: ";
		cin >> length;

		cout << "Enter character type ($, #, *, !): ";
		cin >> character;		

		// Draw lines

		// Horizontal

		if (lineType == 'h' || lineType == 'H') {
			for (int i = 1; i <= length; i++)
				cout << character;
			cout << "\n";
		}

		// Vertical

		else
		if (lineType == 'v' || lineType == 'V') {
			for (int i = 1; i <= length; i++)
				cout << character << '\n';
			cout << "\n";
		}

		// Diagonal (right)

		else
		if ((lineType == 'd' || lineType == 'D') && (direction == 'R' || direction == 'r')) {
			for (int i = 1; i <= length; i++) {
				for (int s = 1; s <= i; s++) {
					if (i == s)
						cout << character;
					else
						cout << ' ';
					}
			cout << endl;
			}
		}

		// Diagonal (left)

		else
		if ((lineType == 'd' || lineType == 'D') && (direction == 'L' || direction == 'l')) {
			for (int i = 1; i <= length; i++) {
				for (int s = length; s >= i; s--) {
					if (i == s)
						cout << character;
					else
						cout << ' ';
					}
			cout << endl;
			}	

		}

	// Ask the user if they want to keep drawing lines

	cout << "Would you like to draw another line? (y/n) ";
	cin >> answer;	

	} 

	cout << endl;
}
