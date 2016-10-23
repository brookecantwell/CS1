#include <iostream>

using namespace std;

main () {

	int length, width;
	char draw, type, border, fill;

	void drawRectangle (int length, int width, char border, char fill);

	cout << "Would you like to draw a shape? (y/n) ";
	cin >> draw;

	if (draw == 'N' || draw == 'n')
		cout << "OK." << endl;
	else
	if (draw == 'Y' || draw == 'y') {
		while (draw == 'Y' || draw == 'y') {
			cout << "Enter length: ";
			cin >> length;
			cout << "Enter width: ";
			cin >> width;
			cout << "Enter border character: ";
			cin >> border;
		

			cout << "Would you like to draw a (f)illed shape or a (h)ollow shape? ";
			cin >> type;

			switch(type) {
				case 'F':
				case 'f':
					cout << "Enter fill character: ";
					cin >> fill;
					break;
				case 'H':
				case 'h':
					fill = ' ';

			} //end switch

			drawRectangle (length, width, border, fill);
			
			cout << "Would you like to draw another shape? (y/n) ";
			cin >> draw;

		} //end while
	} //end if

	else
		cout << "Please enter 'y' or 'n'." << endl;
}
