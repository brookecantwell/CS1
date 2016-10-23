#include <iostream>

using namespace std;

main () {

	const int MAXSTUDENTS = 4;

	string sName [MAXSTUDENTS];

	int sAge [MAXSTUDENTS];
	int snum;


	for (int i = 0; i < MAXSTUDENTS; i++) {
		cout << "Student #" << i + 1 << endl;
		cout << "Enter name: ";
		cin >> sName[i];
		cout << "Enter age: ";
		cin >> sAge [i];
	}

	for (int i = 0; i < MAXSTUDENTS; i++) {
		cout << sName[i] << ", " << sAge[i] << endl;
	}	

	cout << "Which student?";
	cin >> snum;

	cout << sName[snum-1] << ", " << sAge[snum-1] << endl;

}
