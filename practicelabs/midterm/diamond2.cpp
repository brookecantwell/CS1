#include <iostream>

using namespace std;

main () {

	int size;

	cout << "Enter diamond size:" << endl;
	cin >> size;

	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < (size - i); j++)
			cout << ' ';
		for (int j = 1; j <= i; j++)
			cout << '*';
		for (int k = 1; k < i; k++)
			cout << '*';
		cout << endl;
	}

	for (int i = size; i >= 1; i--) {
		for (int j = 0; j < (size - i); j++)
			cout << ' ';
		for (int j = 1; j <= i; j++)
			cout << '*';
		for (int k = 1; k < i; k++)
			cout << '*';
		cout << endl;
	}
	
	cout << endl;

}
