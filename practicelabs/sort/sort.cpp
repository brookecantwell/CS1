#include <iostream>

using namespace std;

main () {

	int x, y, z;
	int largest, smallest, middle;

	cout << "Enter three integers separated by spaces: ";
	cin >> x >> y >> z;

	if (x > y) {
		if (x > z)
			largest = x;
		else
		if (x < z)
			middle = x;
	}

	if (y > x) {
		if (y > z)
			largest = y;
		else
		if (y < z)
			middle = y;
	}

	if (z > y) {
		if (z > x)
			largest = z;
		else
		if (z < x)
			middle = z;
	}

	if (y != largest && y != middle)
		smallest = y;
	if (x != largest && x != middle)
		smallest = x;
	if (z != largest && z != middle)
		smallest = z;
	
	cout << "Smallest = " << smallest << endl;
	cout << "Middle = " << middle << endl;
	cout << "Largest = " << largest << endl;
	

}
