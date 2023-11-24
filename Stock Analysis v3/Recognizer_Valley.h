#pragma once
#include "Recognizer.h"
ref class Recognizer_Valley : Recognizer
{
	public:
	Recognizer_Valley() : Recognizer("Valleys", 3)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[1]->low < subCandlesticks[2]->low && subCandlesticks[1]->low < subCandlesticks[0]->low);
	}
};

