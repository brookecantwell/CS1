#include <iostream>

using namespace std;

//global variable
//can only be accessed by functions below the declaration

//physical existence of memory (static vs. glocal vs. local)
//scope - within which bodies of code can a variable be accessed

int x = 9;

main () {

	void funcA(int&);

	cout << "main(1) " << "x = " << x << endl;


	int x = 5;
	cout << "main(1.5) " << "x = " << x << endl;

	funcA(x);
	funcA(x);
	funcA(x);

	cout << "main(2) " << "x = " << x << endl;

}


void funcA(int&x) {

	//static - works like local variable but tells the system not to
	//reset the contents with each iteration of a function call
	//memory allocated in global space

	static int y = 5;

	cout << "funcA(1) " << "x = " << x << ' ' << "y = " << y << endl;

	x++;
	y++;

	cout << "funcA(2) " << "x = " << x << ' ' << "y = " << y << endl;

}
