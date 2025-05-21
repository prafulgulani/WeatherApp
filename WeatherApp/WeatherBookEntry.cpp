#include "WeatherBookEntry.h"

// THIS PART OF CODE IS WRITTEN BY ME
WeatherBookEntry::WeatherBookEntry(std::string timestamp, std::string country, double temperature)
    : timestamp(std::move(timestamp)), country(std::move(country)), temperature(temperature) 
{
}
// END OF MY PART
