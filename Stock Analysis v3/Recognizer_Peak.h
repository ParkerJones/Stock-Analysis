#pragma once
#include "Recognizer.h"
ref class Recognizer_Peak : Recognizer
{
	public:
	Recognizer_Peak() : Recognizer("Peaks", 3)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[1]->high > subCandlesticks[2]->high && subCandlesticks[1]->high > subCandlesticks[0]->high);
	}
};

