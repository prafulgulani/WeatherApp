#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "WeatherMain.h"


WeatherMain::WeatherMain()
{
}

void WeatherMain::init()
{
    std::cout << "Welcome to Weather Application" << std::endl;
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void WeatherMain::printMenu()
{
    std::cout << "===========================================" << std::endl;
    std::cout << "======           # MENU #            ======" << std::endl;
    std::cout << "====== 1: Print help                 ======" << std::endl;
    std::cout << "====== 2: Get Weather Data           ======" << std::endl;
    std::cout << "====== 3: Candlesticks               ======" << std::endl;
    std::cout << "====== 4: Name of Countries          ======" << std::endl;
    std::cout << "===========================================" << std::endl;
}

int WeatherMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Starts from here -> Type in some number" << std::endl;
    std::getline(std::cin, line);
    try {
        userOption = std::stoi(line);
    }
    catch (const std::exception& e)
    {
    }
    //userOption = std::stoi(line);
    std::cout << "\n\n************** YOU CHOSE - " << userOption << " **************" << std::endl;
    return userOption;
}

void WeatherMain::processUserOption(int userOption)
{
    switch (userOption) {
    case 1:
        printHelp();
        break;
    case 2:
        weatherDataMenu();
        break;
    case 3:
        printCandlesticks();
        break;
    case 4:
        getKnownCountries();
        break;
    default:
        std::cout << "Invalid choice. Choose 1-4" << std::endl;
        break;
    }
}

void WeatherMain::printHelp()
{
    std::cout << "Help - Get to know Weather" << std::endl;
}

void WeatherMain::weatherDataMenu()
{
    std::cout << "===========================================" << std::endl;
    std::cout << "=====   # Choose your data format #  ======" << std::endl;
    std::cout << "====== 1: Data according to Day      ======" << std::endl;
    std::cout << "====== 2: Data according to Month    ======" << std::endl;
    std::cout << "====== 3: Data according to Year     ======" << std::endl;
    std::cout << "====== 4: Go Back                    ======" << std::endl;
    std::cout << "===========================================" << std::endl;
}

void WeatherMain::printCandlesticks()
{
    std::cout << "candlesticks" << std::endl;
}

void WeatherMain::getKnownCountries()
{
    std::string filePath = "data.csv";
    
    weatherBook.printCountryNames(filePath);
}
