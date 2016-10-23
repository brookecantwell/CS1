/*
 * midterm.cpp
 *
 * Brooke Cantwell
 *
 * 26 October 2015
 *
 * Midterm Exam
 *
 * Asks the user if they would
 * like to make a shape, keeps
 * making shapes until they
 * decide to quit, and displays
 * statistics about the shapes.
 */

#include <iostream>
#include <iomanip>

using namespace std;

main () {

	// Declare local variables

	int height, width, counter = 0, perimeter = 0, area = 0, fillNumber = 0, hollowNumber = 0, totalNumber;
	char answer, shape, character, border, fill;
	float averagePerimeter, averageArea;

	// Ask the user if they would like to draw some shapes

	cout << "Would you like to draw some shapes? (y/n) ";
	cin >> answer;

	// If they answer no tell them they aren't very brave

	if (answer == 'n' || answer == 'N')
		cout << "That's not very brave!" << endl;
	else
	
	// If they answer yes begin making shapes

	if (answer == 'y' || answer == 'Y') {	
		while (answer == 'Y' || answer == 'y') {
	
			// Ask the user if they would like to see filled or hollow shapes

			cout << "Please enter the shape you would like to see, (f)illed or (h)ollow? ";
			cin >> shape;

			// Switch on variable shape for fill and border characters and number
			// of filled and hollow shapes
			
			switch (shape) {
				case 'H':
				case 'h':
					fill = ' ';
					cout << "Enter border character: ";
					cin >> border;
					hollowNumber++;
					break;
				case 'F':
				case 'f':
					cout << "Enter border character: ";
					cin >> border;
					cout << "Enter fill character: ";
					cin >> fill;
					fillNumber++;
					break;
				default:
					cout << "You didn't follow the directions!\n";
					continue;
			}	

			// Ask the user for height and width

			cout << "Enter height: ";
			cin >> height;

			cout << "Enter width: ";
			cin >> width;

			// Draw shapes with user input for height and width

			for (int i = 1; i <= height; i++) {
				for (int j = 1; j <= width; j++) {
					if (i == 1 || i == height || j == 1 || j == width)
						cout << border;
					else
						cout << fill;
				}
			cout << endl;
			
			} // End for loop
		
			// Update perimeter and area stats and increment the counter
		
			perimeter += (height * 2) + (width * 2);
			area = area + (height * width);

			counter++;
		
			// Ask the user if they would like to make another shape
		
			cout << "Would you like to make another shape? (y/n) ";
			cin >> answer;

		} // End while answer = yes loop

		// Calculate the average perimeter, area, number of filled shapes,
		// number of hollow shapes, and total number of shapes

		averagePerimeter = (float) perimeter / counter;
		averageArea = (float) area / counter;
		totalNumber = hollowNumber + fillNumber;	

		// Output calculated statistics

		cout << "Average perimeter: " << fixed << setprecision(2) <<  averagePerimeter << endl;
		cout << "Average area: " << setprecision(2) << averageArea << endl;
		cout << "Number of filled shapes: " << fillNumber << endl;
		cout << "Number of hollow shapes: " << hollowNumber << endl;		 		
		cout << "Total number of shapes: " << totalNumber << endl;
	
	} // End if (answer = yes) clause

	// If the user answered something besides yes or no when asked
	// if they want to make shapes, accuse them of being bad at
	// following instructions.
	
	else
		cout << "You aren't very good at following directions!" << endl;
}
