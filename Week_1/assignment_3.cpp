// Build a simple menu using if or switch.

#include <iostream>
using namespace std;

int main() {

	int user_choice;

	cout << "Welcome to our Restaurant's Menu!" << endl;
	cout << "\nPlease choose an option:" << endl << endl;
	cout << "\t1. Pizza";
	cout << "\n\t2. Hamburger";
	cout << "\n\t3. Fries";
	cout << "\n\t4. Soda";
	cout << "\n\t5. Water" << endl;
	cout << "\nEnter your choice (1-5): ";

	cin >> user_choice;

	switch(user_choice) {
		case 1:
			cout << "You chose a Pizza." << endl;
			break;
		case 2:
			cout << "You chose a Hamburger." << endl;
			break;
		case 3:
			cout << "You chose Fries." << endl;
			break;
		case 4:
			cout << "You chose a Soda." << endl;
			break;
		case 5:
			cout << "You chose Water." << endl;
			break;
		default:
			cout << "Invalid option." << endl;
			break;
	}

	return 0;
}