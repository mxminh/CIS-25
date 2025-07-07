#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {

private:
	double balance;

public:

	BankAccount() {
		balance = 0.0;
	}

	void makePurchase(string item, double cost) {
		if (cost > balance) {
			cout << "\nInsufficient funds for " << item << "." << endl;
		}
		else {
			balance -= cost;
			saveToFile("Purchase of " + item, cost);
		}
	}

	void makeDeposit(double amount) {
		if (amount < 0) {
			cout << "\nCannot deposit a negative amount." << endl;
		}
		else {
			balance += amount;
			saveToFile("Bank Deposit", amount);
		}
	}

	void getBalance() {
		cout << "\nCurrent balance: $" << balance << endl;
		saveToFile("Balance Requested", balance);
	}

	void saveToFile(string type, double amount) {
		ofstream file("bank_account.txt", ios::app);
		if (file.is_open()) {
			file << type << ": $" << amount << endl;
			file.close();
			cout << "\nTransaction Type [" << type << "] - saved to file." << endl;

		}
		else {
			cout << "\nError opening file." << endl;
		}
	}
};

int main() {

	BankAccount newAccount;

	newAccount.makeDeposit(5000.00);
	newAccount.makePurchase("Laptop", 6299.99);
	newAccount.makePurchase("Smartphone", 999.99);
	newAccount.makePurchase("Headphones", 189.99);
	newAccount.getBalance();

	return 0;
}