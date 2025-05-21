#include "CandlestickPlot.h"
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>

// THIS PART OF CODE IS WRITTEN BY ME
// ANSI escape codes for color
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";

void CandlestickPlot::plotCandlestick(const std::vector<Candlestick>& data) const 
{

    // get max and min temperatures
    double maxTemp = std::numeric_limits<double>::lowest();
    double minTemp = std::numeric_limits<double>::max();
    for (const auto& entry : data) 
    {
        maxTemp = std::max(maxTemp, entry.high);
        minTemp = std::min(minTemp, entry.low);
    }
    
    // a slight range addition
    double range = 3.0;
    maxTemp += range;
    minTemp -= range;

    // calculation for the temperature values on scale
    double tempRange = maxTemp - minTemp;
    int numDivisions = 15; 
    double intervalSize = tempRange / numDivisions;

    // creating the temperature scale and then taking its width as plotWidth for accurate plotting
    std::ostringstream tempScale;
    tempScale << std::showpos; // put a + for positive numbers
    for (int j = 0; j <= numDivisions; ++j) 
    {
        double tempValue = minTemp + j * intervalSize;
        //adding a 0 before single digits and a + sign so that all the values on the temperature scale take the same space
        tempScale << " " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << tempValue; 
    }
    std::string scaleLabels = tempScale.str();
    int plotWidth = scaleLabels.length();  // using the length of the temperature scale as plotWidth

    // for some reason calculating scale this way gives more accurate results, ideally it should be plotWidth/tempRange  
    double scale = static_cast<double>(plotWidth) / (tempRange+intervalSize);

    // plot 
    std::vector<std::vector<char>> plot(data.size(), std::vector<char>(plotWidth, ' '));

    // plotting candlestick data horizontally
    for (int i = 0; i < data.size(); ++i) 
    {
        const auto& entry = data[i];
        int openPos = static_cast<int>((entry.open - minTemp) * scale);
        int closePos = static_cast<int>((entry.close - minTemp) * scale);
        int highPos = static_cast<int>((entry.high - minTemp) * scale);
        int lowPos = static_cast<int>((entry.low - minTemp) * scale);

        // making candlestick like this 
        // ---------||||||||||||||||-----------
        //low   open/close    close/open    high

        // using - for high low lines
        for (int j = lowPos; j <= highPos; ++j) 
        {
            plot[i][j] = '-';
        }

        // and using | for open and close
        if (openPos < closePos) 
        {
            // green for bullish
            for (int j = openPos; j <= closePos; ++j) 
            {
                plot[i][j] = '|';
            }
        }
        else 
        {
            // red for bearish
            for (int j = closePos; j <= openPos; ++j) 
            {
                plot[i][j] = '|';
            }
        }
    }

    // printing plot
    for (int i = data.size() - 1; i >= 0; --i) 
    {
        std::cout << std::setw(12) << data[i].date << " | ";
        for (int j = 0; j < plotWidth; ++j) 
        {
            if (plot[i][j] == '|') // for making open close positions
            {
                if (data[i].open < data[i].close) // use green if open is less than close
                {
                    std::cout << GREEN << plot[i][j] << RESET;
                }
                else 
                {
                    std::cout << RED << plot[i][j] << RESET; // else use red
                }
            }
            else if (plot[i][j] == '-') 
            {
                if (data[i].open < data[i].close) // for making high low positions
                {
                    std::cout << GREEN << plot[i][j] << RESET; //use green if open is less than close 
                }
                else 
                {
                    std::cout << RED << plot[i][j] << RESET; // else red
                }
            }
            else 
            {
                std::cout << plot[i][j];
            }
        }
        std::cout << std::endl;
    }

    // print temperature scale
    std::cout << std::setw(14) << " ";
    for (int j = 0; j < plotWidth; ++j) 
    {
        if (j % (plotWidth / numDivisions) == 0) 
        {
            std::cout << '|';
        }
        else 
        {
            std::cout << '-';
        }
    }
    std::cout << std::endl;

    // Print temperature values
    std::cout << std::setw(10) << " " << scaleLabels << std::endl;

    std::cout << "Plotting complete" << std::endl;
}
// END OF MY PART
