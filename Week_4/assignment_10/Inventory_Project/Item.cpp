#include <iostream>
#include "Item.h"
using namespace std;

Item::Item() {
    name = "N/A";
    quantity = 0;
}

Item::Item(string itemName, int itemQuantity) {

    if (itemName.empty()) {
        cout << "Item name cannot be empty. Setting to 'N/A'." << endl;
        itemName = "N/A";
    }
    if (itemQuantity < 0) {
        cout << "Quantity cannot be negative. Setting to 0." << endl;
        itemQuantity = 0;
	}

    name = itemName;
    quantity = itemQuantity;
}

void Item::display() {
    cout << "Item: " << name << ", Quantity: " << quantity << endl;

}
