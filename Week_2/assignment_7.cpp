/*
#include <iostream>
using namespace std;


class Item {
public:
	virtual void display() = 0;

};

class Perishable : public Item {
public:
	void display() override {
		cout << "Perishable Item" << endl;
	}
};

class NonPerishable : public Item {
public:
	void display() override {
		cout << "Non-Perishable Item" << endl;
	}
};

int main() {

	Item* ptr1 = new Perishable();
	Item* ptr2 = new NonPerishable();

	ptr1->display();
	ptr2->display();

	delete ptr1;
	delete ptr2;

	return 0;
}
*/

//BELOW, I AM FOLLOWING THE PROVIDED EXAMPLE AND ADDING NAME & QUANTITY.

#include <iostream>
using namespace std;


class Item {
public:

	string name;
	int quantity;

	Item(string n, int q) {
		name = n;
		quantity = q;
	}

	virtual void display() = 0;

};

class Perishable : public Item {
public:

	Perishable(string n, int q) : Item(n, q) {}

	void display() override {
		cout << name << "(Perishable Item), Quantity: " << quantity << endl;
	}
};

class NonPerishable : public Item {
public:

	NonPerishable(string n, int q) : Item(n, q) {}

	void display() override {
		cout << name << "(Non-Perishable Item), Quantity: " << quantity << endl;
	}
};

int main() {

	Item* ptr1 = new Perishable("Apple Juice", 25);
	Item* ptr2 = new NonPerishable("OatMeal", 50);

	ptr1->display();
	ptr2->display();

	delete ptr1;
	delete ptr2;

	return 0;
}