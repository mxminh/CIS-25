/*
Create a program that:
Accepts user input for item name, quantity, and cost
Calculates and displays the total cost
*/

#include <iostream>
using namespace std;

int main() {

    cout << "Welcome to the Cost Calculator!\n";

    string item_name;
    int quantity;
    float cost;

    cout << "\n\nEnter the item name: ";
    cin >> item_name;
    cout << "\nEnter the item quantity: ";
    cin >> quantity;
    cout << "\nEnter the item cost (exclude the '$'): ";
    cin >> cost;

    if (quantity > 1) {
        item_name += "s";
    }

    cout << "\n\nThe total cost for " << quantity <<
        " " << item_name << " is $" << quantity * cost << endl;

    return 0;
}