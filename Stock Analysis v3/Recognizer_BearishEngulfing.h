#pragma once
#include "Recognizer.h"

ref class Recognizer_BearishEngulfing : Recognizer
{
	public:
	Recognizer_BearishEngulfing() : Recognizer("Bearish Engulfing", 2)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[1]->isBullish() &&
			subCandlesticks[0]->isBearish() &&
			subCandlesticks[1]->close < subCandlesticks[0]->open &&
			subCandlesticks[1]->open > subCandlesticks[0]->close);
	}
};

