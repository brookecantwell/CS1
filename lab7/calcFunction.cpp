/*
 * calcFunction.cpp
 *
 * Lab #7
 *
 * Brooke Cantwell
 *
 * 12 November 2015
 *
 * Functions used by calc.cpp
 * (simple calculator).
 */




#include <iostream>

using namespace std;

//function definition for getEquation

bool parseInput (int&op1, char&operation, int&op2) {

	bool equation;

	cout << "Enter equation or 0x0 to exit: ";
	cin >> op1 >> operation >> op2;

	if (op1 == 0 && operation == 'x' && op2 == 0)
		equation = false;
	else
		equation = true;

	return (equation);

}

//function definition for getEquation

double calculator (int op1, char operation, int op2) {
	
	//declare the result variables
	double result;
	
	//declaration of functions called by calculator
	int addition(int,int);
	int subtraction(int, int);
	int multiplication(int, int);
	double division(int, int);

	//switch on the operation to devide which
	//mathematical function to call
	
	switch(operation) {
		case '+':
			result = addition (op1, op2);
			break;
		case '-':
			result = subtraction (op1, op2);
			break;
		case '*':
			result = multiplication (op1, op2);
			break;
		case '/':
			result = division (op1, op2);
			break;
		default:
			cout << "Please enter a valid expression." << endl;
			result = -9999997;
	}
	
	return (result);
}

//function definition for addition

int addition (int op1, int op2) {

	int addResult;

	addResult = op1 + op2;
	return (addResult);
}

//function definition for subtraction

int subtraction (int op1, int op2) {

	int subResult;

	subResult = op1 - op2;
	return (subResult);
}

//function definition for multiplication

int multiplication (int op1, int op2) {

	int multResult;

	multResult = op1 * op2;
	return (multResult);
}

//function definition for division

double division (int op1, int op2) {

	double divResult;

	//return a sentinal value if the user
	//tries to divide by zero
	
	if (op2 == 0) 
		divResult = -9999998;
	else 
		divResult = (double) op1 / op2;

	return (divResult);
}
