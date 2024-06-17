#pragma once
#include "WeatherBook.h"

class WeatherMain
{
public:
	WeatherMain();
	/** Call this to start the sim */
	void init();
private:
	// handle menu and user input 
	void printMenu();
	int getUserOption();
	void processUserOption(int userOption);
	
	// menu options
	void printHelp();
	void weatherDataMenu();
	void printCandlesticks();
	void getKnownCountries();

	WeatherBook weatherBook;
};
