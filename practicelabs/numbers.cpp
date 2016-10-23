/* numbers.cpp
 *
 * Math Challenge With Loops
 *
 * Brooke Cantwell
 *
 * 15 October 2015
 *
 */


#include <iostream>
#include <iomanip>

using namespace std;

main () {

	int num, sum, largest, smallest, counter = 1;
	float average;
	string answer;

	cout << "While (w) or do while (d)?";
	cin >> answer;

	if (answer == "w") {

        cout << "Please enters numbers and '-999' when you're done.\n";
        cin >> num;

		while (num != -999) {
			if (counter == 1)
				sum = largest = smallest = num;
			else {
				sum = sum + num;
			
				if (num > largest)
					largest = num;
				else
				if (num < smallest)
					smallest = num;

				}			

				cout << "Enter next number.\n";
				cin >> num;
			
				counter++;

		} //End while
		
		counter--;
		if (counter > 0)
			average = (float) sum / counter;		

		cout << "Sum: " << sum << "\n";
		cout << fixed << setprecision(4) << "Average: " << average << "\n";
		cout << "Smallest: " << smallest << "\n";
		cout << "Largest: " << largest << "\n";

	}
	else {

        cout << "Please enters numbers and '-999' when you're done.\n";
        cin >> num;

		do {
			if (counter == 1)
				sum = largest = smallest = num;
			else {
				sum = sum + num;	
				
				if (num > largest)		
					largest = num;
				else
				if (num < smallest)
					smallest = num;
			}

			cout << "Enter next number.\n";
			cin >> num;

			counter ++;

		} while (num != -999);	

		counter--;
		if (counter > 0)
			average = (float) sum / counter;
		
		cout << "Sum: " << sum << "\n";
		cout << fixed << setprecision(4) << "Average: " << average << "\n";
		cout << "Smallest: " << smallest << "\n";
		cout << "Largest: " << largest << "\n";

	}

}
