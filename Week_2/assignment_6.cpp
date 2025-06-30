#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std;

class Item {
public:
	string name;
	int quantity;

    void saveToFile() {

        ofstream WriteToFile("items.txt");

        if (WriteToFile.is_open()) {

            WriteToFile << name << "," << quantity << endl;
            WriteToFile.close();
            cout << "Item successfully saved to file." << endl;
        }
        else {
            cout << "Unable to open file for writing. Please try again." << endl;
        }
    }

    void loadFromFile() {

        ifstream ReadFile("items.txt");

        if (ReadFile.is_open()) {

            string curr_line;

            while (getline(ReadFile, curr_line)) {
                cout << "\nFile content: " << curr_line << endl;
            }
            ReadFile.close();
        }
        else {
            cout << "Unable to open file for reading. Please try again." << endl;
        }
    }
};

int main() {
    Item computers_cases;

    computers_cases.name = "Fractal Terra";
    computers_cases.quantity = 62;

    computers_cases.saveToFile();
    computers_cases.loadFromFile();

    return 0;
}
