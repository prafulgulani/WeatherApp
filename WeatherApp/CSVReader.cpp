#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>

// THIS PART OF CODE IS WRITTEN BY ME
std::vector<std::string> CSVReader::parseHeader(const std::string& filePath) 
{
    std::vector<std::string> headers;
    std::ifstream file(filePath);
    std::string line, value;

    if (file.is_open()) 
    {
        std::getline(file, line);  //take the first line
        std::stringstream ss(line);
        std::getline(ss, value, ',');  // skip timestamp column
        while (std::getline(ss, value, ',')) 
        {
            size_t pos = value.find('_');  // extract country code from header (country_temperature)
            if (pos != std::string::npos) 
            {
                std::string countryCode = value.substr(0, pos); // take the country code
                headers.push_back(countryCode); // and push
            }
        }
        file.close();
    }
    else 
    {
        std::cout << "Unable to open file" << std::endl;
    }
    return headers;
}

std::vector<WeatherBookEntry> CSVReader::parseData(const std::string& filePath, const std::vector<std::string>& countries) 
{
    std::vector<WeatherBookEntry> entries;
    std::ifstream file(filePath);
    std::string line, value;
    if (file.is_open()) 
    {
        std::getline(file, line);  // skip header line

        while (std::getline(file, line))
        {
            // from the line 
            std::stringstream ss(line);
            // take the timestamp 
            std::string timestamp;
            std::getline(ss, timestamp, ',');

            for (const auto& country : countries) 
            {
                std::getline(ss, value, ',');
                // and temp value 
                double temperature = std::stod(value);
                // and push the values along with country to create a WeatherBookEntry
                entries.emplace_back(timestamp, country, temperature);
            }
        }
        file.close();
    }
    else 
    {
        std::cout << "Unable to open file" << std::endl;
    }
    return entries;
}
// END OF MY PART