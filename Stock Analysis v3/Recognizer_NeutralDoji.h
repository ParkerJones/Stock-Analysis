#pragma once
#include "Recognizer.h"

ref class Recognizer_NeutralDoji : Recognizer
{
	public:
	Recognizer_NeutralDoji() : Recognizer("Neutral Doji", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isNeutralDoji();
	}
};

