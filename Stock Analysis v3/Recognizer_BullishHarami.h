#pragma once
#include "Recognizer.h"

ref class Recognizer_BullishHarami : Recognizer
{
	public:
	Recognizer_BullishHarami() : Recognizer("Bullish Harami", 2)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[0]->isBullish() &&
			subCandlesticks[1]->isBearish() &&
			subCandlesticks[0]->close < subCandlesticks[1]->open &&
			subCandlesticks[0]->open > subCandlesticks[1]->close);
	}
};

