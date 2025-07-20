#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>      // To format output

class Clans {
private:
    std::string filename; 

	// Vectors to hold Clan Data (each vector corresponds to a column in the CSV)
	// Makes it easy to manage and access data
    std::vector<std::string> clan_tags;
    std::vector<std::string> clan_names;
    std::vector<std::string> clan_descriptions;
    std::vector<std::string> clan_locations;
    std::vector<bool> isFamilyFriendlyList;
    std::vector<int> clan_levels;

    // Truncates long strings and adds "..." at the end if they exceed maxLength
    std::string truncate(const std::string& text, size_t maxLength) {

        if (text.length() <= maxLength) {
            return text;
        }

        else {
            std::string result = text.substr(0, maxLength - 3);
            result += "...";
            return result;
        }
    }

public:

	// Constructor to initialize the filename
    Clans(const std::string& file) {
        filename = file;
    }
        
    // Reads clan data from CSV up to the number of rows specified by 'count'
    void readClanData(int count) {

        // Clear previous data in case the function is called again
        clan_tags.clear();
        clan_names.clear();
        clan_descriptions.clear();
        clan_locations.clear();
        isFamilyFriendlyList.clear();
        clan_levels.clear();

        // Opening the File
        std::ifstream file(filename); 

		// Check if the file was opened successfully
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
		std::getline(file, line); // Skips the first line (since it's a header)

        int rowCount = 0;

        while (std::getline(file, line) && rowCount < count) {

			std::stringstream ss(line); // Create a string stream to parse the line
            std::string tag, name, type, description, location, isFamilyFriendlyStr;
            std::string badgeUrl, levelStr;

			// Extract comma-separated values from the line (since they are stored like: ..., ..., ..., ..., etc.)
            std::getline(ss, tag, ',');
            std::getline(ss, name, ',');
            std::getline(ss, type, ',');
            std::getline(ss, description, ',');
            std::getline(ss, location, ',');
            std::getline(ss, isFamilyFriendlyStr, ',');
            std::getline(ss, badgeUrl, ',');
            std::getline(ss, levelStr, ',');

            // If required values are missing, skip the line
            if (tag.empty() || name.empty() || levelStr.empty()) {
                continue;
            }

            // Convert "true"/"false" or "1"/"0" to boolean
            bool isFriendly = false;
            if (isFamilyFriendlyStr == "true" || isFamilyFriendlyStr == "1") {
                isFriendly = true;
            }

            int level = 0;
            try {
                level = std::stoi(levelStr); // Convert string to integer
            }
            catch (...) {
                continue; // Skip line if conversion fails
            }

            // Store the parsed values into vectors
            clan_tags.push_back(tag);
            clan_names.push_back(name);
            clan_descriptions.push_back(description);
            clan_locations.push_back(location);
            isFamilyFriendlyList.push_back(isFriendly);
            clan_levels.push_back(level);

            rowCount++; 
        }

        file.close(); // Closing File
    }

    // Displays the stored clan information in a formatted output
    void displayClans(int count) {

        readClanData(count); // First read data for 'count' number of clans

        std::cout << "\nNow Displaying " << clan_tags.size() << " clan(s):\n\n";

        // Loop through and print each clan's info
        for (int i = 0; i < clan_tags.size(); i++) {
            std::cout << "===================================================================\n";
            std::cout << "\nCLAN #" << (i + 1) << "\n\n";
            std::cout << std::left // Align text to the left for clean layout
                << std::setw(13) << "Tag: " << truncate(clan_tags[i], 20) << "\n"
                << std::setw(13) << "Name: " << truncate(clan_names[i], 30) << "\n"
                << std::setw(13) << "Location: " << truncate(clan_locations[i], 25) << "\n"
                << std::setw(13) << "Level: " << clan_levels[i] << "\n"
                << std::setw(13) << "Friendly: " << (isFamilyFriendlyList[i] ? "Yes" : "No") << "\n"
				<< std::setw(13) << "Description: " << truncate(clan_descriptions[i], 100) << "\n\n"; // Uses truncate to limit description length
        }

        std::cout << "===================================================================\n";
    }
};

int main() {

	// Create an instance of Clans with the CSV filename
	std::string filename = "coc_clans_dataset.csv";     // Name of the CSV file containing clan data (can't attach to github due to size limits)
    Clans clans(filename); 

    short int count;
    std::cout << "How many clans would you like to display? ";
    std::cin >> count; 

    clans.displayClans(count); 

	std::cout << "\nThank you for using the Clash of Clans Display Program!\n";

    return 0;
}