#include <iostream>
using namespace std;

main () {

	int h, v;
	string answer;

	cout << "Would you like a hollow (h) square, or filled (f) square?";
	cin >> answer;

	// Square
	if (answer == 'h') {
		cout << "Enter horizontal dimensions for the square: ";
		cin >> h;

		cout << "Enter vertical dimensions for the square: ";
		cin >> v;


		for (int c = 1; c <= v; c++) {
			for (int c = 1; c <= h; c++)
			cout << '*';
		cout << '\n';
		}
	} //End if


	//Hollow square
	else {
		cout << "Enter horizontal dimensions for the square: ";
		cin >> h;

		cout << "Enter vertical dimensions for the square: ";
		cin >> v;


		for (int c = 1; c <= v; c++) {
			for (int c = 1; c <=h; c++)
				cout << '*';
		cout << '\n';
		}

	}
	// End else / hollow Square	


}


