#include <iostream>

using namespace std;

main ()  {
	cout << "func5(): " << endl;

	int x;

	for ( x = 1; x <= 10; x++ ) {
		if ( x == 7 )
			break;

		if ( x == 3 )
			continue;

		cout <<x << " ";
	}

	cout << endl << "The final value of x is: " << x << endl;
}
