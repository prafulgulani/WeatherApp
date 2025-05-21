#include "WeatherBook.h"
#include "CSVReader.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>

// THIS PART OF CODE IS WRITTEN BY ME
WeatherBook::WeatherBook(const std::string& filePath) 
{
    // uses the parseHeader function from CSVReader and stores country codes
    countryCodes = CSVReader::parseHeader(filePath);
}

void WeatherBook::printCountryCodes() const
{
    // simply prints the country codes
    std::cout << "These are the available Country Codes." << std::endl;
    for (const auto& country : countryCodes)
    {
        std::cout << country << ", ";
    }
}

bool WeatherBook::isValidCountryCode(const std::string& countryName) const 
{
    // checks in countryCodes vector if the user has entered a correct country code
    return std::find(countryCodes.begin(), countryCodes.end(), countryName) != countryCodes.end();
}

std::vector<Candlestick> WeatherBook::generateCandlestickData(const std::string& country, const std::string& timeframe) const 
{
    // parses data for the specific country using parseData function from CSVReader
    std::vector<WeatherBookEntry> countryEntries = CSVReader::parseData("data.csv", { country });
    
    // sorting by timestamp
    std::sort(countryEntries.begin(), countryEntries.end(), WeatherBookEntry::compareByTimestamp);

    // grouping data by timeframe by taking a substring from time data
    std::map<std::string, std::vector<double>> temperatureData;
    for (const auto& entry : countryEntries)
    {
        std::string key;
        if (timeframe == "day") 
        {
            key = entry.timestamp.substr(0, 10); // YYYY-MM-DD
        }
        else if (timeframe == "month") 
        {
            key = entry.timestamp.substr(0, 7);  // YYYY-MM
        }
        else
        {
            key = entry.timestamp.substr(0, 4);  // YYYY
        }
        temperatureData[key].push_back(entry.temperature);
    }

    // calculating candlestick metrics
    std::vector<Candlestick> candlestickData;
    double previousClose = 0;
    bool isFirst = true;

    for (const auto& pair : temperatureData)
    {
        const auto& temps = pair.second;
        if (temps.empty()) 
        {
            std::cout << "No temperature data for date: " << pair.first << std::endl;
            continue;
        }

        // if it is first data then take first value else take the close from second
        double open = isFirst ? temps.front() : previousClose;
        double close = temps.back();
        double high = *std::max_element(temps.begin(), temps.end());
        double low = *std::min_element(temps.begin(), temps.end());

        // pushback date and then candlestick data
        candlestickData.push_back(Candlestick(pair.first, open, close, high, low));

        // after first loop make isirst false so that close is taken as open for next candlestick data
        previousClose = close;
        isFirst = false;
    }
    return candlestickData;
}

void WeatherBook::plotCandlestickData(const std::string& country, const std::string& timeframe) const 
{
    // generate data using the generate function and plot using the plot function in CandlestickPlot
    auto data = generateCandlestickData(country, timeframe);
    plot.plotCandlestick(data);
}

void WeatherBook::plotFilteredData(const std::string& country, const std::string& startDate, const std::string& endDate) const 
{
    // generate candlestick data accoding to the country and timeframe
    auto data = generateCandlestickData(country, "day");

    // filter the data according to the date range
    std::vector<Candlestick> filteredData;
    for (const auto& entry : data)
    {
        if (entry.date >= startDate && entry.date <= endDate)
        {
            filteredData.push_back(entry);
        }
    }

    // plot the filtered data using the plot function in CandlestickPlot
    plot.plotCandlestick(filteredData);
}
// END OF MY PART