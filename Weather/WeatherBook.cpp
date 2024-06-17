#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "WeatherBook.h"

WeatherBook::WeatherBook()
{
}


void WeatherBook::printCountryNames(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line, value;
    if (file.is_open()) {
        // Read the header line
        std::getline(file, line);
        std::stringstream headerStream(line);

        // Skip the first column (timestamp)
        std::getline(headerStream, value, ',');

        // Print the country names
        while (std::getline(headerStream, value, ',')) {
            std::cout << value << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }
}