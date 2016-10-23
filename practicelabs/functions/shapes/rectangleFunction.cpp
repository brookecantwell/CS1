#include <iostream>

using namespace std;

void drawRectangle (int length, int width, char border, char fill) {

	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= width; j++) {
			if (i == 1 || i == length || j == 1 || j == width)
				cout << border;
			else
				cout << fill;
		}
	cout << endl;
	}

}
