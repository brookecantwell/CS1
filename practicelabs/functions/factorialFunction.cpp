#include <iostream>

using namespace std;

int computeFactorial (int i) {

	int result = 1;	
	
	for (int c = i; c > 0; c--) {
		result *= c;
	}

	cout << i << '\t' << result << endl;

	return(result);
}
