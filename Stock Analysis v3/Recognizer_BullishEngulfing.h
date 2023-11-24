#pragma once
#include "Recognizer.h"

ref class Recognizer_BullishEngulfing : Recognizer
{
	public:
	Recognizer_BullishEngulfing() : Recognizer("Bullish Engulfing", 2)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[1]->isBearish() &&
			subCandlesticks[0]->isBullish() &&
			subCandlesticks[1]->open < subCandlesticks[0]->close &&
			subCandlesticks[1]->close > subCandlesticks[0]->open);
	}
};

