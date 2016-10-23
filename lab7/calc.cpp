/*
 * calc.cpp
 *
 * Calculator Lab #7
 *
 * Brooke Cantwell
 *
 * 12 October 2015
 *
 * A simple calculator that allows the
 * user to add, subtract, multiply, and
 * divide integers by parsing input into
 * different operand and operator variables
 * and continues to prompt the user for
 * input until they enter a sentinal value.
 *
 */



#include <iostream>
#include <iomanip>

using namespace std;

main () {

	//declaration of variables

	int op1, op2;
	char operation;
	double result;
	bool equation;

	//declaration of functions parseInput and calculator

	bool parseInput (int&, char&, int&);
	double calculator (int, char, int);

	//loop while the equation passed through parseInput is true

	while ( equation = parseInput (op1, operation, op2) == true ) {

		//call the calculator funtion with the operands and
		//operators as parameters

		result = calculator (op1, operation, op2);

		//result returned from calculator() function
		//sentinal value -9999997 represents an equation
		//that does not have a valid operator, the if()
		//conditional issues a continue statement
		//to invoke praseInput until it detecs either
		//a valid equation or the sential expression 0x0

		if ( result == -9999997 ) 
			continue;

		//result returned from the division() function
		//sentinal value -9999998 represents that the
		//division function detected the user is trying
		//to divide by zero, the if() conditional alerts
		//the user and uses a continue statement to invoke
		//parseInput() until a valid equation or sentinal
		//value is input.

		if (result == -9999998 ) {
			cout << "Error...cannot divide by zero." << endl;
			continue;
		} 

		//output results

		cout << op1 << ' '<< operation << ' ' << op2 << " = ";
		cout << std::setprecision(5) << result << endl;

	}

	cout << "OK! Goodbye." << endl;

}
