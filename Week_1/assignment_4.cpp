// Refractor menu using functions

#include <iostream>
using namespace std;

void showMenu() {
	cout << "___________________________________\n";
	cout << "\nOptions: \n\t1. Add Item \n\t2. View Items \n\t3. Exit\n";
	cout << "\nPlease enter your choice (1-3): ";
}

string addItem() {

	int user_choice;
	cout << "___________________________________\n";
	cout << "\nHere's our Menu!" << endl;
	cout << "\nPlease choose an item to add:" << endl << endl;
	cout << "\t1. Pizza";
	cout << "\n\t2. Hamburger";
	cout << "\n\t3. Fries";
	cout << "\n\t4. Soda";
	cout << "\n\t5. Water" << endl;
	cout << "\nEnter your choice (1-5): ";

	cin >> user_choice;

	switch (user_choice) {
	case 1:
		cout << "\tYou added a Pizza." << endl;
		return "Pizza";
		break;
	case 2:
		cout << "\tYou added a Hamburger." << endl;
		return "Hamburger";
		break;
	case 3:
		cout << "\tYou added Fries." << endl;
		return "Fries";
		break;
	case 4:
		cout << "\tYou added a Soda." << endl;
		return "Soda";
		break;
	case 5:
		cout << "\tYou added Water." << endl;
		return "Water";
		break;
	default:
		cout << "\n**Invalid option. Try Again.**" << endl;
		addItem();
		return "";
		break;
	}
	
}

void viewItems(string& item_list) {
	cout << "\n___________________________________\n";
	cout << "\nItems in your order: " << item_list << endl;
}

void optionChooser(int option, string& item_list) {
	if (option == 1) {

		string item = addItem();

		if (item == "") {
			return;
		}

		if (item_list == "") {
			item_list = item;
			return;
		}

		item_list += ", " + item;
	}
	else if (option == 2) {
		viewItems(item_list);
	}
}

void exitMenu() {
	cout << "\n\nExiting the menu...\n";
	cout << "Thank you for using our Menu!\n";
}

int main()
{
	cout << "Welcome to our Restaurant!\n";

	int option;
	string item_list = "";

	do {
		showMenu();
		cin >> option;
		optionChooser(option, item_list);
	} while (option != 3);

	exitMenu();

	return 0;
}

