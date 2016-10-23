/* 
 * age.cpp
 *
 * Lab #8 - How old are you really?
 *
 * Brooke Cantwell
 * 
 * 27 November 2015
 *
 * Simple age calculator that asks the user for
 * the current date, their birthday and calculates
 * their age in years, months, and days.
 *
 */



#include <iostream>

using namespace std;

main () {

	//declare local variables
	bool valid, validBirthday;
	int cmonth, cday, cyear;
	int bmonth, bday, byear;
	int ageYears, ageMonths, ageDays;
	char answer;
	const int MAXGUESSES = 3;

	//function declarations
	bool enterDate (int&, int&, int&, const int);
	bool enterBirthDate (int, int, int, int&, int&, int&, const int);
	void calculateAge (int, int, int, int, int, int, int&, int&, int&);

	//prompt the user for todays date and invoke the enterDate() function
	cout << "Please enter today's date, ";
	valid = enterDate(cmonth, cday, cyear, MAXGUESSES);

	//if validDate() function doesn't recognize a valid date after three tries
	//the user is alerted
	if (valid == false)
		cout << endl;
	else

	//if the date was valid show the user the date they entered and ask
	//if they would like to calculate their age.
	if (valid == true) {
		cout << "Date entered is: " << cmonth << '/' << cday << '/' << cyear << endl;

		cout << "Would you like to see how old you are? (y/n) ";
		cin >> answer;

		if (answer == 'N' || answer == 'n')
			cout << "You are so chicken!" << endl;
		else

		//if the user would like to see their age, call the enterBirthDate
		//function and assign the return value to the boolean variable
		//validBirthDate
		if (answer == 'Y' || answer == 'y') {
			if (validBirthday = enterBirthDate (cmonth, cday, cyear, bmonth, bday, byear, MAXGUESSES) == true) {

			cout << "Date entered is: " << bmonth << '/' << bday << '/' << byear << endl; 		
	
			//call the calculateAge() function to calculate the user's age
			calculateAge(bmonth, bday, byear, cmonth, cday, cyear, ageYears, ageMonths, ageDays);

			//display results
			cout << "You are " << ageYears << " years, " << ageMonths << " months, and " << ageDays << " days old." << endl;

			//display a special result if it is the users birthday
			if (bmonth == cmonth && bday == cday)
				cout << "Happy Birthday!" << endl;
			}
			
			else
				cout << "You have entered an invalid birth day." << endl;

		} //end if answer is yes

		else //if answe is not yes or no
			cout << "You did not enter 'y' or 'n'" << endl;


	} //end if current date is valid
}
