#include <iostream>

using namespace std;

int toCelsius (int farenheitTemp) {
	int result;

	result = (farenheitTemp - 32) * (0.55);
	return(result);
}

int toFarenheit (int celciusTemp) {
	int result;

	result = ((celciusTemp * 9) / 5) + 32;
	return(result);

}
	
