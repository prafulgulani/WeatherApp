#include "WeatherMain.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype> 
#include <cstdlib>


WeatherMain::WeatherMain()
{
}

void WeatherMain::init() 
{
    std::cout << "      Welcome to Weather Application       " << std::endl;
    int input;
    // takes a input until user wants to exit the app
    while (true)
    {
        printMenu();
        std::cout << "Choose from 1-7: ";
        input = getUserOption();
        processUserOption(input);
    }
}

void WeatherMain::printMenu() const
{
    //simple statements to be printed in the console for interaction with the application
    std::cout << "\n===========================================" << std::endl;
    std::cout << "======           # MENU #            ======" << std::endl;
    std::cout << "====== 1: Print help                 ======" << std::endl;
    std::cout << "====== 2: Code of Countries          ======" << std::endl;
    std::cout << "====== 3: Print Candlestick Data     ======" << std::endl;
    std::cout << "====== 4: Plot Candlestick Data      ======" << std::endl;
    std::cout << "====== 5: Filter Data and Plot       ======" << std::endl;
    std::cout << "====== 6: Predict Temperature Change ======" << std::endl;
    std::cout << "====== 7: Exit                       ======" << std::endl;
    std::cout << "===========================================" << std::endl;
}

int WeatherMain::getUserOption() const 
{
    int userOption = 0;
    std::string line;

    // takes user option
    std::getline(std::cin, line);

    // check if it is correct, if not prints an error
    try {
        userOption = std::stoi(line);
        std::cout << "\n\n************** YOU TYPED - " << userOption << " **************" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\n\nInvalid input. Please enter a valid number." << std::endl;
        std::cout << "You entered: " << line << std::endl;
    }
    return userOption;
}

void WeatherMain::processUserOption(int userOption) const 
{
    // simple switch case statements working according to the printed menu
    switch (userOption) 
    {
        case 1:
            printHelp();
            break;
        case 2:
            getKnownCountries();
            break;
        case 3:
            printCandlestickData();
            break;
        case 4:
            plotCandlestick();
            break;
        case 5:
            plotFilterData(); 
            break;
        case 6:
            predictTemperatureChange();
            break;
        case 7:
            std::cout << "Exiting the application..." << std::endl;
            exit(0);
        default:
            std::cout << "Invalid choice. Choose 1-7" << std::endl;
            break;
    }
}

void WeatherMain::printHelp() const 
{
    // console out help
    std::cout << "Help - Get to know Weather\n" << std::endl;
}

// THIS PART OF CODE IS WRITTEN BY ME
void WeatherMain::getKnownCountries() const
{
    //calls printCountryCodes function from WeatherBook
    weatherBook.printCountryCodes();
}

std::string WeatherMain::getValidCountryCode() const 
{
    std::string country;

    while (true) 
    {
        // takes country code from user
        std::cout << "\nEnter country code: ";
        std::getline(std::cin, country);

        // converts country code to uppercase
        std::transform(country.begin(), country.end(), country.begin(), ::toupper);

        // checks if the country code is valid, if not prints an error with the list of country codes
        if (weatherBook.isValidCountryCode(country)) 
        {
            break;
        }
        else 
        {
            std::cout << "\nInvalid country code. Please try again." << std::endl;
            getKnownCountries(); // prints the list of country codes if wrong input is received
        }
    }
    return country;
}

std::string WeatherMain::getTimeframe() const 
{
    // asks day month or year timeframe from the user until correct input is received
    std::cout << "Select the timeframe for candlestick data: " << std::endl;
    std::cout << "1: Day" << std::endl;
    std::cout << "2: Month" << std::endl;
    std::cout << "3: Year" << std::endl;

    std::cout << "Choose from 1-3: ";
    int choice = getUserOption();

    switch (choice) {
    case 1:
        return "day";
    case 2:
        return "month";
    case 3:
        return "year";
    default:
        std::cout << "Invalid choice. Choose 1-3\n";
        return getTimeframe(); // recursively asks for a valid input
    }
}

void WeatherMain::printCandlestickData() const 
{
    // asks for a valid country code from the user
    std::string countryCode = getValidCountryCode();

    // asks for a valid timeframe option from the user
    std::string timeframe = getTimeframe();

    // calls generateCandlestickData function from the WeatherBook 
    auto data = weatherBook.generateCandlestickData(countryCode, timeframe);
        for (const auto& entry : data) 
        {
            std::cout << "Date: " << entry.date
                << ", Open: " << entry.open
                << ", Close: " << entry.close
                << ", High: " << entry.high
                << ", Low: " << entry.low << std::endl;
        }
}

void WeatherMain::plotCandlestick() const 
{
    // asks for a valid country code from the user
    std::string countryCode = getValidCountryCode();

    // asks for a valid timeframe option from the user
    std::string timeframe = getTimeframe();

    std::cout << "Plotting candlestick data..." << std::endl;

    // calls plotCandlestickData function from the WeatherBook 
    weatherBook.plotCandlestickData(countryCode, timeframe);
}

void WeatherMain::plotFilterData() const 
{
    // asks for a valid country code from the user
    std::string country = getValidCountryCode();

    // asks for date range from the user
    std::string startDate, endDate;
    std::cout << "Enter start date (YYYY-MM-DD): ";
    std::getline(std::cin, startDate);
    std::cout << "Enter end date (YYYY-MM-DD): ";
    std::getline(std::cin, endDate);

    std::cout << "Plotting candlestick data..." << std::endl;
    // calls plotFilteredData from the WeatherBook
    weatherBook.plotFilteredData(country, startDate, endDate);
}

void WeatherMain::predictTemperatureChange() const 
{
    // prints to console that I was not able to do it
    std::cout << "I have no idea how to do this." << std::endl;
}
// END OF MY PART