/*
Instructions: Write a simple C++ program named hello_inventory.cpp that:
Prints "Hello Inventory System!"
Demonstrates use of escape characters (\n, \t)
Outputs sizes of int, float, and char
*/

#include <iostream>
using namespace std;

int main() {

    cout << "Hello Inventory System!\n";
    cout << "\nThese are the sizes of some basic data types in C++:\n\n";
    cout << "\tSize of int: " << sizeof(int) << " bytes\n";
    cout << "\tSize of float: " << sizeof(float) << " bytes\n";
    cout << "\tSize of char: " << sizeof(char) << " byte\n";

    return 0;
}
