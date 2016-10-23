/**************************************************
 * hello2.cpp                                     *
 *                                                *
 * This is the first C++ program for CISC 1600.   *
 *                                                *
 * Brooke Cantwell                                *
 *                                                *
 * 9 September 2015                               *
 *                                                *
 **************************************************
 */ 

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

main() {

	string name;
	string lname;

	cout << "Hello World" << " " << "I love you \n";
        
	cout << "What is your name?\n";
	cin >> name;
	cin >> lname;

	cout << endl << "Very nice to meet you " << name << " " << lname << "." << endl << "Welcome to the world of C++!!!" << endl;

}

