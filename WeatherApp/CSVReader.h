#pragma once
#include <string>
#include <vector>
#include "WeatherBookEntry.h"

// THIS PART OF CODE IS WRITTEN BY ME
class CSVReader 
{
public:
    /*parses header for country codes*/
    static std::vector<std::string> parseHeader(const std::string& filePath);
    /*parses temperature values to create a WeatherBookEntry(timestamp, country, temperature)*/
    static std::vector<WeatherBookEntry> parseData(const std::string& filePath, const std::vector<std::string>& countries);
};

// END OF MY PART