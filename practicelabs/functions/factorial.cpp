#include <iostream>

using namespace std;

main () {

	int computeFactorial(int i);
	int num;
	int result;

	cout << "To see a chart of factorials from 1 to 'n' enter number here: ";
	cin >> num;
		
	cout << "Number\tFactorial" << endl;

	for (int i = 1; i <= num; i++) {
		computeFactorial(i);
	}	
}
