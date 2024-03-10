#include <iostream>
#include <fstream>
#include <string>

bool searchSubstring(const std::string& substring, std::ifstream& file) {
    std::string line;
    bool found = false;

    while (std::getline(file, line)) {
        if (line.find(substring) != std::string::npos) {
            found = true;
            break;
        }
    }

    return found;
}

void writeResultsToFile(bool found, const std::string& substring) {
    std::ofstream out("search_results.txt");
    if (!out.is_open()) {
        std::cout << "Failed to create a file to record the results." << std::endl;
        return;
    }

    if (found) {
        out << "Substring \"" << substring << "\" found in a text file." << std::endl;
    }
    else {
        out << "Substring \"" << substring << "\" was not found in the text file." << std::endl;
    }

    out.close();
}

int main() {
    std::string filename, substring;

    std::cout << "Enter the file name to search for: ";
    std::cin >> filename;

    std::cout << "Enter a substring to search for: ";
    std::cin >> substring;

    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "File " << filename << " could not be opened." << std::endl;
        return 1;
    }

    bool found = searchSubstring(substring, in);
    in.close();

    writeResultsToFile(found, substring);

    std::cout << "The search results are recorded in a file search_results.txt" << std::endl;

    return 0;
}