/* shopping.cpp
 *
 * Shopping Spree - Lab %4
 *
 * Brooke Cantwell
 *
 * 8 October 2015
 *
 * Asks the user if they want to go on a shopping
 * spree, asks them how much money they have,
 * and depending on their answer displays items
 * they can purchase. The program loops until
 * the customer has no money left, and then asks
 * them if they would like a receipt sent to their 
 * preferred email address.
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

main () {

	// Declare local variables

	int change, itemNumber = 1;
	float customerAmount, total;
	float priceW = 39.00, priceG = 50.00, priceM = 12.99, priceD = 24.99;
	string answer, fname, orderedItem, message, receipt, email, keepShopping, purchase;
	char item;

	// Ask the user their name and if they would like to go on a shopping spree
	// If the user says no quit the program, if not continue

	cout << "Welcome to your Halloween Shopping Spree, the alternative to Party City\nMy name is Brooke and I will be helping you with your order.\n";
	
	cout << "Please enter your first name.\n";
	cin >>fname;
	
	cout << "Hello " << fname << ", would you like to go on a Halloween shopping spree?\n";
	cin >> answer;

	if (answer == "NO" || answer == "No" || answer == "no")
		cout << "Cheapskate!\n";
	else {

		// Ask the user for the amount of money they have
	
		cout << "Please enter the amount of money you have.\n";
		cin >> customerAmount;
		
		// If the user has less money than the cost of the cheapest item, quit the program

		if (customerAmount < 12.99)
			cout << "You do not have enough money to purchase anything in the store.\n";
		else
		
		// Begin while loop -- continue while the user has more than 4 dollars

		while (customerAmount >=12.99) {

			// List the products that the user can afford

			cout << "Here is a list of things you can afford:\n";

			if (customerAmount >= 12.99) {
				cout << itemNumber << ". A retro Madonna costume, on sale for $12.99. Letter Code: M.\n";
				itemNumber++;
			}
			if (customerAmount >=24.99) {
				cout << itemNumber << ". A Donald Trump costume - we provide the toupe - you provide the idiotic rhetoric, $24.99. Letter Code: D.\n";
				itemNumber++;
			}
			if (customerAmount >= 39.00) {
				cout << itemNumber << ". A witchy witch costume, $39.00. Letter Code: W.\n";
				itemNumber++;
			}
			if (customerAmount>= 50) {
				cout << itemNumber << ". A gooouulish mask, $50.00. Letter Code: G.\n";
				itemNumber++;
			}		

			// Ask the user which item they would like to purchase

			cout << "Which of these items would you like to purchase? (Please use the letter code to specify the item.)\n";
			cin >> item;
			
			// Switch on item for its letter code


			switch (item) {
				case 'M':
				case 'm':
					orderedItem = "retro Madonna costume";
					total = priceM;
					change = customerAmount - priceM;
					purchase = "yes";
					message = "I hope you've been laying off the ice cream!\n";
					break;
				case 'D':
				case 'd':
					orderedItem = "Donald Trump costume";
					total= priceD;
					change = customerAmount - priceD;
					purchase = "yes";
					message = "Have you found somebody to be your Rosie O'Donnell?\n";
					break;
				case 'W':
				case 'w':
					orderedItem = "witchy witch costume";
					total = priceW;
					change = customerAmount - priceW;
					purchase = "yes";
					message = "That's not very creative!\n";
					break;
				case 'G':
				case 'g':
					orderedItem = "gooouulish mask";
					total = priceG;
					change = customerAmount - priceG;
					purchase = "yes";
					message = "Ooohhhhh!\n";
					break;
				default:
					cout << "You have entered an invalid letter code.";
					purchase = "no";
					break;		
			}

			// If the customer enters an item they can't afford, tell them

			if (total > customerAmount) {
				cout << "You chose an item that was not on the list.\n";
				purchase = "no";
				break;
			}
			
			// Tell the customer what they ordered and display change
			
			else {
				cout << "You have ordered a " << orderedItem << ".\n";
				cout << message;			

				cout << fixed << "You spent $" << setprecision(2) << total << ", and you have $" << fixed << setprecision(2) << change << " left.\n";
			}

			// Reset the amount of money the customer has to the value of the variable change

			customerAmount = change;

			// If the customer now has less than the cost of the cheapest item, tell them and quit

			if (customerAmount < 12.99) {
				cout << "You have run out of money!\n";
				break;			
			}
			
			// Ask the user if they would like to continue shopping
	
			cout << "Would you like to continue shopping?\n";
			cin >> keepShopping;

			if (keepShopping == "NO" || keepShopping == "No" || keepShopping == "no")
				break;
			else {
			
				itemNumber = 1;
			}
		// End of while loop (While customerAmount > 12.99)	

		}
		
		// Ask the user if thhey would like an online receipt and if so prompt for preferred email
		
		if (purchase == "yes") {	
			cout << "Would you like to recieve an online receipt?\n";
                	cin >> receipt;

			if (receipt == "NO" || receipt == "No" || receipt == "no")
				cout << "OK. Thank you, have a good day.\n";
			else {
				cout << "Please enter your preferred email.\n";
				cin >> email;
			}
		}		
	//End of else clause (Would you like to go on a shopping spree?)
	}
}
