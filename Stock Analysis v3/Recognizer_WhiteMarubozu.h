#pragma once
#include "Recognizer.h"

ref class Recognizer_WhiteMarubozu : Recognizer
{
	public:
	Recognizer_WhiteMarubozu() : Recognizer("White Marubozu", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[0]->isMarubozu() && subCandlesticks[0]->isBullish());
	}
};

