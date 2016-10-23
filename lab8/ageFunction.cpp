/*
 * ageFunction.cpp
 *
 * Lab #8 - How old are you really?
 *
 * Brooke Cantwell
 *
 * 27 November 2015
 *
 * Functions used in the simple age calculator
 * age.cpp
 *
 */


#include <iostream>

using namespace std;

//function definition for enterDate() - the function that prompts
//the user for input and parses input into months, days, and years
//and then calls the validDate() function to make sure the entered 
//date is valid.

bool enterDate (int&month, int&day, int&year, const int MAXGUESSES) {

	bool valid;
	int counter = 1;

	bool validDate(int&, int&, int&);

	cout << "Please enter the date as MM DD YYYY: ";
	cin >> month >> day >> year;

	valid = validDate(month, day, year);

	// use the constant MAXGUESSES and the variable counter to
	// allow the user only three tries to enter a valid date
	
	if (valid == false) {
		while (valid == false && counter < MAXGUESSES) {
			counter++;
			cout << "The entered date is invalid, please re-enter: ";
			cin >> month >> day >> year;
			valid = validDate(month, day, year);
			
		}

	// if the user reaches the limit of three guesses, alert them
	// and bring an end to the program
	
	cout << "You have reached the limit for invalid dates." << endl;
	}

	return(valid);

}

// function definition for enterBirthDate() which prompts the user to enter
// their birthdate and invokes the enterDate() function to parse the input and
// the dateBefore() function to make sure the entered birth date occurs before
// the current date entered by the user

bool enterBirthDate (int cmonth, int cday, int cyear, int&bmonth, int&bday, int&byear, const int MAXGUESSES) {

	bool valid;
	bool valid2;

	bool dateBefore (int, int, int, int, int, int);
	bool enterDate (int&, int&, int&, const int);

	cout << "We need to know your date of birth, ";

	// call function enterDate() to prompt the user for input and parse
	// the input into b(irthday)month, bday, and byear

	valid = enterDate(bmonth, bday, byear, MAXGUESSES);

	//if the birth date entered by the user is a valid date, make sure
	//that the birth date occurs before the current date supplied by
	//the user in enterDate()

	if (valid == true)
		valid2 = dateBefore(cmonth, cday, cyear, bmonth, bday, byear);

	return(valid2);

}

//function definition for dateBefore() (invoked by enterBirthDate()  which
//compares variables c(urrent)month cday, and cyear to b(irth)month, bday, 
//and byear to make sure the birthday occurs before the current date supplied by the user

bool dateBefore (int cmonth, int cday, int cyear, int bmonth, int bday, int byear) {

	bool valid;


	//if the birth year is greater than the current year assign the boolean
	//variable 0 (false) to valid, indicating an invalid birth date

	if (byear > cyear)
		valid = false;
	else

	//if birth year is equal to the current year, perform relational operations
	//on the bmonth and cmonth variables to determine which date occured first

	if (byear == cyear) {

		//if the birth year and current year are the same, but the birth
		//month is less than the current month, assign the value of true
		//to the boolean variable valid

		if (bmonth < cmonth) 
			valid = true;
		else

		//if the bmonth = cmonth perform relational operations on bday and cday
		if (bmonth == cmonth)

			//if the bday is less than the cday assign true to the boolean variable valid
			if (bday < cday)
				valid = true;
			else
				//if the bday is greater than the cday assign the value false to valid
				valid = false;
		else

		//if bmonth is greater than the cmonth and byear is equal to the cyear 
		//assign false to valid, indicating an invalid birth day

		if (bmonth > cmonth)
			valid = false;
	else
	//if the cyear is greater than the byear assign the value of false to valid
	if (byear < cyear)
		valid = false;
	}
		
	return(valid);
}


//function definition for validDate() (invoked by enterDate() ) which uses variables of day, month, and year
//to make sure that the date entered is valid based on month, day, and year variables
bool validDate (int&month, int&day, int&year) {
	
	//local variables
	bool valid;
	int maxDay;

	//function declaration
	int getLastDay (int);

	//calculate maximum day based on month
	maxDay = getLastDay(month);

	//if the month is less than zero or greater than 12 assign the value false to
	//the boolean variable valid indicating an invalid date
	if (month < 0 || month > 12)
		valid = false;

	else

	//if the month is valid make sure that the day falls inbetween 1 and the maximum day
	//associated with the month entered
		
	if (month > 0 && month <= 12) {
		if (day > 0 && day <= maxDay)
			valid = true;
		else
			valid = false;
	}

	return (valid);	
}

//function definition for calculareAge(). Invoked by main(), calculate age accept parameters bmonth, bday, byear,
//cmonth, cday, and cyear (by value) to perform calculations and relational operations to determine age. The parameters
//ageYears, ageMonths, and ageDays are passed by reference so they can be output in the main() program.

void calculateAge (int bmonth, int bday, int byear, int cmonth, int cday, int cyear, int&ageYears, int&ageMonths, int&ageDays) {

	//local variable
	int maxDay;

	//function declaration
	int getLastDay (int);

	maxDay = getLastDay (bmonth);

	if (cyear >= byear && cmonth >= bmonth && cday >= bday){
		ageYears = cyear - byear;
		ageMonths = cmonth - bmonth;
		ageDays = cday - bday;

	}
	else

	if (cyear > byear) {
		if (cmonth >= bmonth) {
			if (cday < bday) {
				ageYears = cyear - byear;
				ageMonths = cmonth - bmonth - 1;
				ageDays = maxDay - bday + cday;
			}
		}
		else
		if (cmonth < bmonth) {
			if (cday > bday) {
				ageYears = cyear - byear - 1;
				ageMonths = 12 - bmonth + cmonth;
				ageDays = cday - bday;
			}
			else
			if (bday > cday) {
				ageYears = cyear - byear - 1;
				ageMonths = 12 - bmonth + cmonth - 1;
				ageDays = maxDay - bday + cday;
			}
		}
	}

}

//function definition for getLastDay(), uses the month entered to calculate the maximum
//valid day for that month

int getLastDay (int month) {
	
	int maxDay;
	
	switch (month) {
		case 4:
		case 6:
		case 9:
		case 11:
			maxDay = 30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxDay = 31;
			break;
		case 2:
			maxDay = 28;
	}

	return(maxDay);
}
