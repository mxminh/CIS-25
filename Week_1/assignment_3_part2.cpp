// DEBUGGING Find the largest of three numbers using if statements.

#include <iostream>
using namespace std;
int main() {
	float n1, n2, n3;

	cout << "Enter three numbers (seperated by spaces): ";
	cin >> n1 >> n2 >> n3;

	if (n1 >= n2 && n1 >= n3) {
		cout << "Largest number: " << n1;
	}

	else if (n2 >= n1 && n2 >= n3) {
		cout << "Largest number: " << n2;
	}

	else if (n3 >= n1 && n3 >= n2) {
		cout << "Largest number: " << n3;
	}

	return 0;
}