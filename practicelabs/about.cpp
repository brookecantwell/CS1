/* 
 *  about.cpp
 *
 *  Brooke Cantwell
 *
 *  24 September 2015
 *
 *  Practice Lab #3 - Let's Play with Variables!
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

main () {

string firstName, lastName, university;
int birthMonth, birthDay, birthYear;
float gpa, projectedSalary;
char middleInitial;
char dummy;

	cout << "Welcome to About.cpp\n";

	cout << "Enter name in the form First MI Last: ";
	cin >> firstName >> middleInitial >> lastName;

	cout << "Enter birth date in the form of MM/DD/YYYY: ";
	cin >> birthMonth >> dummy >> birthDay >> dummy >> birthYear;

	cout << "Enter current University: ";
	cin >> university;

	cout << "Enter projected GPA: ";
	cin >> gpa;

	cout << "Enter projected Salary: ";
	cin >> projectedSalary;	
	
	cout << "OK, you entered:\n\n" << firstName << ' ' << middleInitial << ". " << lastName << "\n" << birthMonth << "/" << birthDay << "/" << birthYear << "\n"<< university << "\n" << std::fixed << std::setprecision(4) << gpa << '\n' << std::setprecision(2) << projectedSalary << '\n' << "BYE!!!\n";

}
