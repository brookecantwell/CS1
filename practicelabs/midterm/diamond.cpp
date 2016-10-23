#include <iostream>
#include <iomanip>

using namespace std;

main () {

	const int SIZE = 10;

	for (int x = 1; x <= SIZE; x++) {
		for (int y = 1; y <= SIZE; y++) {
			if (y > x)
				cout << ' ';
			else
				cout << '*';
		}
		cout << endl;
	}
}
