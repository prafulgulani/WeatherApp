#pragma once
#include <string>

// THIS PART OF CODE IS WRITTEN BY ME
class WeatherBookEntry 
{
public:
    /*WeatherBookEntry constructor (timestamp, country, temperature)*/
    WeatherBookEntry(std::string timestamp, std::string country, double temperature);

    /*compare the timestamps*/
    static bool compareByTimestamp(const WeatherBookEntry& a, const WeatherBookEntry& b) 
    {
        return a.timestamp < b.timestamp;
    }

    std::string timestamp;
    std::string country;
    double temperature;
};

// END OF MY PART