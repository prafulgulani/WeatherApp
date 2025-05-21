#pragma once
#include <string>
#include <vector>
#include "WeatherBookEntry.h"
#include "Candlestick.h"
#include "CandlestickPlot.h"

// THIS PART OF CODE IS WRITTEN BY ME
class WeatherBook 
{
public:
    /*WeatherBook constructor takes filepath as input*/
    WeatherBook(const std::string& filePath);
    /*prints country codes*/
    void printCountryCodes() const;
    /*checks if a country code is valid*/
    bool isValidCountryCode(const std::string& countryCode) const;
    /*generates temperature data for a particular country and its timeframe*/
    std::vector<Candlestick> generateCandlestickData(const std::string& country, const std::string& timeframe) const;
    /*plots candlestcik data for a particular country and its timeframe*/
    void plotCandlestickData(const std::string& country, const std::string& timeframe) const;
    /*filters the data for a particular country and timeframe and plots it*/
    void plotFilteredData(const std::string& country, const std::string& startDate, const std::string& endDate) const;
private:
    /*vector to store country codes*/
    std::vector<std::string> countryCodes;
    /*creates an instace of CandlestickPlot*/
    CandlestickPlot plot;
};
// END OF MY PART