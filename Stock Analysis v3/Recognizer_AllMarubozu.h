#pragma once
#include "Recognizer.h"

ref class Recognizer_AllMarubozu : Recognizer
{
	public:
	Recognizer_AllMarubozu() : Recognizer("All Marubozu", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isMarubozu();
	}
};

