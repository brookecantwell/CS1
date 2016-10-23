#include <iostream>

using namespace std;

main () {


	//declare
	//default arguments - if a call is made without any arguments

	int add (int = 10, int = 25);
	double add (double, double);

	//function overloading - using the same function name for different datatypes

	int op1, op2, result;
	double dop1, dop2, dresult;


	cout << "Enter two numbers: ";

	cin >> dop1 >> dop2;

	cout << "main(1) " << dop1 << ' ' << dop2 << endl;

	//invoke
	dresult = add (); 
		//result = add (op1) -> add (op1, 25)
		//result = add (op2) -> add (op2, 25)

	cout << "main(2) " << dop1 << " + " << dop2 << " = " << dresult << endl;

}

//define
int add (int op1, int op2) {


	cout << "add(1) " << op1 << ' ' << op2 << endl;

	return (op1 + op2); //return (10 + 25)
}

double add (double op1, double op2) {

	cout << "add(2) " << op1 << ' ' << op2 << endl;

	return (op1 + op2);

}
