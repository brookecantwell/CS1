/* 
 * pizza.cpp
 *
 * Brooke Cantwell
 * 
 * 26 September 2015
 *
 * pizza.cpp allows a customer to place
 * an order with Little Italy Pizza for
 * 12 and 14 inch  pizzas, calculates 
 * the total price, change, and prints
 * a reciept.
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

main () {

	/* Declare local variables */

	string server, firstName, receipt, showReceipt = ("Yes"), noReceipt = ("No");
	int qtypizza12inch, qtypizza14inch, change2, dollars, quarters, dimes, nickels, pennies;
	float price12inch = 12.39, price14inch = 15.98, total12inch, total14inch, total, payment, change;

	/* Begin interaction with the customer */

	cout << "Hello! Welcome to Little Italy Pizzeria! My name is Brooke and I will be your server today.\n";

	cout << "What is your first name?\n";
	cin >> firstName;

	cout << "How many 12 inch pizzas would you like to order?\n";
	cin >> qtypizza12inch;

	cout << "How many 14 inch pizzas would you like to order?\n";
	cin >> qtypizza14inch;
	
	/* Calculate cost for 12 inch pizzas, 14 inch pizzas, and total cost */

	total12inch = qtypizza12inch * price12inch;
	total14inch = qtypizza14inch * price14inch;
	total = total12inch + total14inch;

	cout << "Your total is $" << total << ".\n";
	cout << "Please make a payment:\n";

	/* Use customer input to calculate change */	

	cin >> payment;
	change = payment - total;

	/* If customer payment is less than the total, cancel and alert customer */

	if (payment < total)
	{	
		cout << "You have entered a payment value that is less than the total cost, your order has been cancelled.\n";
		return 0;
	}

	/* If payment goes through, display change due and calculate how many dollars, quarters, dimes, nickles, and pennies */

	cout << "Thank you " << firstName << ", your change is $" << std::fixed << std::setprecision(2) << change << "\n";
	
	change2 = change * 100;

	dollars  = (change2) / 100;
	cout << "Dollars: " << dollars << "\n";	
	change2 = change2 % 100;

	quarters = change2 / 25;
	cout << "Quarters: " << quarters << "\n";
	change2 = change2 % 25;

	dimes = change2 / 10;
	cout << "Dimes: " << dimes << "\n";
	change2 = change2 % 10;

	nickels = change2 / 5;
	cout << "Nickels: " << nickels << "\n";
	change2 = change2 % 5;

	pennies = change2;
	cout << "Pennies: " << pennies << "\n";
	
	/* Ask the customer if they would like to see their receipt */

	cout << "Would you like your receipt? (Enter: Yes or No)\n";
	cin >> receipt;

	/* If the customer answers yes print the receipt */

	if (receipt == showReceipt)
	{
		cout << "Please wait for your reciept...\n\n\n";
		cout << "-----------------------------------" << "\n";
		cout <<	"Receipt by Little Italy Pizzeria" << "\n";
		cout << "-----------------------------------" << "\n";
		cout << "Order for: " << firstName << "\n\n";
		cout << "\t\tQuan\tPrice\n";
		cout << "12-inch pizza\t" << qtypizza12inch << "\t" << total12inch << "\n";
		cout << "14-inch pizza\t" << qtypizza14inch << "\t" << total14inch << "\n";
		cout << "-----------------------------------" << "\n";
		cout << "Total\t\t\t" << total << "\n";
		cout << "Amount received\t\t" << payment << "\n";
		cout << "Change\t\t\t" << change << "\n\n";
		cout << "Cashier: Brooke\n";  
		cout << "-----------------------------------" << "\n";
	}
	else
	{
		return 0;
	}
}
