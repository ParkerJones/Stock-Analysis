#pragma once
#include "Recognizer.h"

ref class Recognizer_GravestoneDoji : Recognizer
{
	public:
	Recognizer_GravestoneDoji() : Recognizer("Gravestone Doji", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isGravestoneDoji();
	}
};

