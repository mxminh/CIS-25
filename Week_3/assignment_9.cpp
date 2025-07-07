#include <iostream>
#include <string>
using namespace std;

class Item {
private:
	string name;
	int quantity;

public:

	void setName(string itemName) {
		name = itemName;
	}

	string getName() {
		return name;
	}

	void setQuantity(int itemQuantity) {
		quantity = itemQuantity;
	}

	int getQuantity() {
		return quantity;
	}

	void display() {
		cout << "\n\tItem Name: " << name;
		cout << "\n\tItem Quantity: " << quantity << endl;
	}
};

void searchItem(Item items[], int size, string itemName) {
	for (int i = 0; i < size; i++) {
		if (items[i].getName() == itemName) {
			cout << "\n\nItem found!" << endl;
			items[i].display();
			return;
		}

		
	}

	cout << "\nError: Item not found!" << endl;
}

int main() {

	const int size = 5;
	Item items[size];

	string itemName;
	int itemQuantity;

	for (int i = 0; i < size; i++) {

		cout << "\nITEM #" << i + 1 << endl;

		cout << "\n\tEnter item name: ";
		cin >> itemName;

		cout << "\n\tEnter item quantity: ";
		cin >> itemQuantity;

		items[i].setName(itemName);
		items[i].setQuantity(itemQuantity);

	}

	cout << "\nITEMS DETAILS" << endl;
	cout << "--------------------" << endl;

	for (int i = 0; i < size; i++) {
		cout << "\nITEM #" << i + 1 << " DETAILS" << endl;
		items[i].display();
	}

	string searchItemName;

	cout << "\nEnter item name to search: ";
	cin >> searchItemName;
	searchItem(items, size, searchItemName);

	return 0;
}
