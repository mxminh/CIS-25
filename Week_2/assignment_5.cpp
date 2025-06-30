#include <iostream> 
#include <string> 
using namespace std;

struct Student {
	int id;
	string name;
	double gpa;
};

struct Item {
	int id;
	string name;
};

int binarySearch(Item* arr, int size, int target) {

	int left = 0;
	int right = size - 1;

	while (left <= right) {
		
		int middle = (left + right) / 2;

		if (arr[middle].id == target) {
			return middle;
		}

		else if (arr[middle].id > target) {
			right = middle - 1;
		}

		else if (arr[middle].id < target) {
			left = middle + 1;
		}
	}

	return -1;
}

int main() {

	const int size = 10;

	Student students[size];
	Item* items = new Item[size];

	students[0] = { 101, "Michael", 3.8 };
	students[1] = { 102, "Lakisha", 3.5 };
	students[2] = { 103, "Charlie", 3.9 };
	students[3] = { 104, "Minh", 4.0 };
	students[4] = { 105, "Adam", 2.7 };
	students[5] = { 106, "Sophia", 3.6 };
	students[6] = { 107, "Ethan", 2.9 };
	students[7] = { 108, "Isabella", 3.4 };
	students[8] = { 109, "Daniel", 3.1 };
	students[9] = { 110, "Olivia", 3.2 };

	for (int i = 0; i < size; i++) {
		items[i].id = students[i].id;
		items[i].name = students[i].name;

	}

	int user_id;

	cout << "Welcome to the Student Database!" << endl;

	cout << "\nEnter a Valid Student ID or 99999 to view its entirety: ";
	cin >> user_id;

	if (user_id == 99999) {

		cout << "\nHere is the entire Student Databse:" << endl;

		for (int i = 0; i < size; ++i) {
			cout << "\tStudent ID: " << students[i].id
				<< ", Name: " << students[i].name
				<< ", GPA: " << students[i].gpa << endl;
		}

		delete[] items;
		return 0;
	}

	int index = binarySearch(items, size, user_id);

	if (index == -1) {
		cout << "\nPlease enter a VALID student ID.";
		cout << "\nThe Student ID you entered does not exist in the database." << endl;
		cout << "\nPlease rerun to try again." << endl;
	}

	else {
		cout << "\nHere is the information associated with the Student ID: " << user_id << endl;
		cout << "\n\tStudent Name: " << items[index].name;
		cout << "\n\tStudent GPA: " << students[index].gpa << endl;
	}

	
	delete[] items;
	return 0;

}