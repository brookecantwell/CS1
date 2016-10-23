/*
 * hello.cpp
 *
 * This is the first C++ program for CISC 1600.
 *
 * Brooke Cantwell
 *
 * 9 September 2015
 *
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

main() {
	
	int processName( string );	

	string name;
	bool more_input = true;

	cout << "Hello World" << endl;
	cout << "Continue to enter your name when prompted or the . to end input..." << endl;

	do {

		cout << "What is your name? ";
		cin >> name;

		if ( name != "." ) {
			cout << name << "is " << processName(name) << "years old" << endl;
		} else {
			cout << "OK, bye" << endl;
			more_input = false;
		}

	} while ( more_input );
}

int processName( string n ) {

	int age;

	cout << endl << "Very nice to meet you " << n << "." << endl << "Welcome to the world of C++!!!" << endl;

	cout << "How old are you? ";
	cin >> age;

	if ( age > 21)
		cout << "Congratulations " << n << "you are legal!" << endl;
	else
	if (age == 21)
		cout << "Hey, just made it!!!" << endl;
	else
		cout << "Looks like you must wait another " << 21-age << " years" << endl;
	return( age );
}
