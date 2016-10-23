#include <iostream>

using namespace std;

main () {

	char answer, convertTo, chartAnswer, chartType;
	int result;
	int celciusTemp, farenheitTemp;

	int toCelsius(int farenheitTemp);
	int toFarenheit(int farenheitTemp);	

	cout << "Would you like to convert a temperature? ";
	cin >> answer;

	if (answer == 'N' || answer == 'n')
		cout << "OK";
	else {
		cout << "Would you like to convert to (F)arenheit or (C)elsius? ";
		cin >> convertTo;

		switch(convertTo) {
			case 'F':
			case 'f':
				cout << "Enter Celcius temperature: ";
				cin >> celciusTemp;
				result = toFarenheit(celciusTemp);
				break;
			case 'C':
			case 'c':
				cout << "Enter Farenheit temperature: ";
				cin >> farenheitTemp;
				result = toCelsius(farenheitTemp);
				break;
		}

		cout << result << endl;
	} // end else (converting)

	cout << "Would you like to see a chart of temperature conversions? (y/n) ";
	cin >> chartAnswer;
	
	if (chartAnswer == 'N' || chartAnswer == 'n')
		cout << "OK." << endl;
	else {
		cout << "Would you like to see (F)arenheit conversions or (C)elsius conversions? ";
		cin >> chartType;
	
		if (chartType == 'F' || chartType == 'f') {
			cout << "Celsius\tFarenheit" << endl;			

			for (int celsiusTemp = 1; celsiusTemp <= 100; celsiusTemp++) {
				result = toFarenheit(celsiusTemp);
				cout << celsiusTemp << '\t' << result << endl;	
			}
		}

		if (chartType == 'C' || chartType == 'c') {
			cout << "Farenheit\tCelsius" << endl;
			
			for (int farenheitTemp = 32; farenheitTemp <= 212; farenheitTemp++) {
				result = toCelsius(farenheitTemp);
				cout << farenheitTemp << "\t\t" << result << endl;
			
			}
		}	
	} //end else (chart)	

	
}
