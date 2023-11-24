#pragma once
#include "Recognizer.h"

ref class Recognizer_DragonflyDoji : Recognizer
{
	public:
	Recognizer_DragonflyDoji() : Recognizer("Dragonfly Doji", 1)
	{

	};

	bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) override
	{
		return subCandlesticks[0]->isDragonflyDoji();
	}
};

