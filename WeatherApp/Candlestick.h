#pragma once
#include <string>

// THIS PART OF CODE IS WRITTEN BY ME
class Candlestick 
{
public:
    /*defines candlestick type (date, open, close, high, low)*/
    Candlestick(const std::string& date, double open, double close, double high, double low);

    std::string date;
    double open;
    double close;
    double high;
    double low;
};
// END OF MY PART
