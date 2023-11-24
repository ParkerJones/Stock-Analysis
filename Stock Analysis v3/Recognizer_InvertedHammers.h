#pragma once
#include "Recognizer.h"

ref class Recognizer_InvertedHammers : Recognizer
{
	public:
	Recognizer_InvertedHammers() : Recognizer("Inverted Hammers", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isHammerInverted();
	}
};

