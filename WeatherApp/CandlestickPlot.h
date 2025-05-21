#pragma once
#include <vector>
#include "Candlestick.h"

// THIS PART OF CODE IS WRITTEN BY ME
class CandlestickPlot 
{
public:
    /*takes the candlestick data and plots it*/
    void plotCandlestick(const std::vector<Candlestick>& data) const;
};
// END OF MY PART