#include <iostream>
using std::cin;
using std::cout;
using std::endl;


main() {
	void func1(), func2(), func3(int), func4(), func5(), func6(), func7(), func8(), func9();

	func1();
	func2();
	
	int gArray[] = {55, 65};
	for ( int i = 0; i < 2; i++ )
		func3( gArray[i] );

	func4();
	func5();
	func6();
	func7();
	func8();
	func9();

}

void func1() {

	cout << "func1(): " << endl;

	int x = 1;
	
	 while (x <= 5 ) {
		x++;
		cout << "The value of x is: " << x << endl;
	}
}

void func2() {

	cout << "func2(): " << endl;

	for ( int i = 0; i < 5; i+=2 )
		cout << i << endl;
}

void func3( int grade ) {

	cout << "func3(): " << endl;

	cout << "The student with a grade of " << grade << " " << (grade >= 60 ? "Passed" : "Failed") << endl;
}

void func4() {
	cout << "func4(): " << endl;

	int total = 5;

	for ( int i = 1; i <= 10; i++ ) {
		switch( i ) {
			case 1:
				total += i;
				break;

			case 4:
				total -= i;
				break;
			
			case 5:
				cout << "The value of total when i == " << i << " is " << total << endl;
			case 6:
				total *= total;
				break;

			default:
				total = 0;
		}
	}

	cout << "The final value of total is: " << total << endl;
}

void func5() {
	cout << "func5(): " << endl;

	int x;

	for ( x = 1; x <= 10; x++ ) {
		if ( x == 7 )
			break;

		if ( x == 3 )
			continue;

		cout <<x << " ";
	}

	cout << endl << "The final value of x is: " << x << endl;
}

void func6() {

	cout << "func6() " << endl;

	int row = 10;
	int column;

	while (row >=1) {
		column = 1;

		while (column <= 10) {
			if ( row % 2 )
				cout << ">>";
			else
				cout << "<<";

			column++;
		}

		--row;
		cout << endl;
	}
}

void func7() {

	cout << "func7() " << endl;

	{ // block1
	int ctr = 1;

	while ( ctr++ < 10 )
		cout << ctr << endl;
	}

	{ // block2
	int ctr = 1;

	do {
		cout << ctr << endl;
	} while ( ++ctr < 10 );

	}

	{ // block3
	int ctr = 0;

	for ( ctr = 1; ctr <= 10; ctr+=3 )
		cout << ctr << " ";
		cout << 2*ctr << endl;
	}

	{ // block4
	int arrayNum[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i=0;

	do {
		cout << arrayNum[++i] << endl;
		} while (i <= 5);
	}
}

void func8() {

	cout << "func8() " << endl;

	int number = 0;
	int total = 0;
	int max = 10;

	for ( number = 3; number <= max; number+=2 ) 
		total += number;
		if ( total  >= number )
	 		total -= number;
		if (total >= max )
			total-=max;
		else
			total = 1;

	cout << "the current value of total is: " << total << endl;
}

void func9() {

	cout << "func9() " << endl;

	int doSomething( int &, int  );

        int j = 2;
        int k = 2;
        int r = j++;

        cout << "r == " << r << " j == " << j << " k == " << k << endl;

        r = doSomething(j, ++k);

        cout << "r == " << r << " j == " << j << " k == " << k << endl;
}

int doSomething( int & f, int k ) {
        int j = f+k++;

	  f--;

        return(j+k);
}
