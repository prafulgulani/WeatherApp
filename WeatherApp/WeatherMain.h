#pragma once
#include "WeatherBook.h"

class WeatherMain 
{
public:
    /*weather main constructor*/
    WeatherMain();
    /*function to start the app*/
    void init();

private:
    // helper functions
    /*prints menu*/
    void printMenu() const;
    /*takes input from user and responds accodingly*/
    int getUserOption() const;
    /*calls appropriate functions according to the user input*/
    void processUserOption(int userOption) const;
    // THIS PART OF CODE IS WRITTEN BY ME
    /*check if a country code is valid*/
    std::string getValidCountryCode() const;
    /*asks user for timeframe for candlestick data and plot(day, month or year)*/
    std::string getTimeframe() const;

    // menu options
    /*prints help*/
    void printHelp() const;
    /*prints countries from database*/
    void getKnownCountries() const;
    /*generates candlestick data*/
    void printCandlestickData() const;
    /*plots the candlestick data*/
    void plotCandlestick() const;
    /*filters the data according to user needs*/
    void plotFilterData() const;
    /*predics the temperature*/
    void predictTemperatureChange() const;

    /*creates an instance of WeatherBook and assigns the data file*/
    WeatherBook weatherBook{ "data.csv" };
    // END OF MY PART
};

