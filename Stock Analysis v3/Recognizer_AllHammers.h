#pragma once
#include "Recognizer.h"

ref class Recognizer_AllHammers : Recognizer
{
public:
	Recognizer_AllHammers() : Recognizer("All Hammers", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[0]->isHammerUpright() || subCandlesticks[0]->isHammerInverted());
	}
};

