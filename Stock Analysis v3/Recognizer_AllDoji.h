#pragma once
#include "Recognizer.h"

ref class Recognizer_AllDoji : Recognizer
{
	public:
	Recognizer_AllDoji() : Recognizer("All Doji", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isDoji();
	}
};

