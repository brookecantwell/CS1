#include <iostream>

using std::cout;
using std::cin;
using std::string;

main () {
	string from, to, friendname, school;	

	cout << "What is your name?\n";
	cin >> from;

	cout << "Who are you writing a letter to?\n";
	cin >> to;

	cout << "Where does this person go to school?\n";
	cin >> school;

	cout << "What is their friend's name?\n";
	cin >> friendname;

	cout << "Dear " << to << ",\n";
	cout << "\tHow are you? I am fine. I missed seeing you the other evening. How is " << school <<" ? Are you getting good grades?" << "Have you seen " << friendname << " lately? I hope you have a good semester!\n";
	cout << "Sincerely, " << from << "\n";
}
