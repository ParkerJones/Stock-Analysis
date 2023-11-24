#pragma once
#include "Recognizer.h"

ref class Recognizer_BearishHarami : Recognizer
{
	public:
	Recognizer_BearishHarami() : Recognizer("Bearish Harami", 2)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[0]->isBearish() &&
			subCandlesticks[1]->isBullish() &&
			subCandlesticks[0]->open < subCandlesticks[1]->close &&
			subCandlesticks[0]->close > subCandlesticks[1]->open);
	}
};

