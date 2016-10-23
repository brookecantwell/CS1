#include <iostream>

using namespace std;

main () {

	cout << "func4(): " << endl;

	int total = 5;

	for ( int i = 1; i <= 10; i++ ) {
		switch( i ) {
			case 1:
				total += i;
				break;

			case 4:
				total -= i;
				break;
			
			case 5:
				cout << "The value of total when i == " << i << " is " << total << endl;
			case 6:
				total *= total;
				break;

			default:
				total = 0;
		}
	}

	cout << "The final value of total is: " << total << endl;
}

