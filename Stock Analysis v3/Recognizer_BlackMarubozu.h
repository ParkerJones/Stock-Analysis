#pragma once
#include "Recognizer.h"

ref class Recognizer_BlackMarubozu : Recognizer
{
	public:
	Recognizer_BlackMarubozu() : Recognizer("Black Marubozu", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return (subCandlesticks[0]->isMarubozu() && subCandlesticks[0]->isBearish());
	}
};

