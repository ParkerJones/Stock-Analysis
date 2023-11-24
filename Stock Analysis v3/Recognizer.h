#pragma once
#include "SmartCandlestick.h"

using namespace System::Collections::Generic;

ref class Recognizer
{
	public:
	Recognizer(String^ pattern, int size)
	{
		patternName = pattern;
		patternSize = size;
	};

	String^ patternName;
	int patternSize;

	List<int>^ Recognize(List<SmartCandlestick^>^ candlesticks) {
		List<int>^ outList = gcnew List<int>();
		for (int i = 0; i < candlesticks->Count - patternSize; ++i)
		{
			if (IsPattern(candlesticks->GetRange(i, patternSize)))
			{
				outList->Add(i + patternSize - 1);
			}
		}
		return outList;
	}

	virtual bool IsPattern(List<SmartCandlestick^>^ subCandlesticks) = 0;

};

