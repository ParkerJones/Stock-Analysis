#pragma once
#include "Recognizer.h"

ref class Recognizer_UprightHammers : Recognizer
{
public:
	Recognizer_UprightHammers() : Recognizer("Upright Hammers", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isHammerUpright();
	}
};