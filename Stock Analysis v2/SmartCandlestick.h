#pragma once
#include "Candlestick.h"
#include <math.h>
#include <string>
#include <iostream>

using namespace System;

/// <summary>
/// A candlestick with higher level properties and methods.
/// </summary>
ref class SmartCandlestick : public Candlestick
{
public:

	double topPrice;
	double bottomPrice;
	double totalRange;
	double bodyRange;
	double topTail;
	double bottomTail;

	// Array of detectable pattern names
	static array<String^>^ Patterns = gcnew array<String^> {
		"All Doji",
		"Neutral Doji",
		"Dragonfly Doji",
		"Gravestone Doji",
		"All Hammers",
		"Upright Hammers",
		"Inverted Hammers",
		"All Marubozu",
		"White Marubozu",
		"Black Marubozu"
	};

	SmartCandlestick() {
		topPrice = (isBullish()) ? close : open;
		bottomPrice = (isBullish()) ? open : close;
		bodyRange = fabs(open - close);
		topTail = (isBullish()) ? (high - close) : (high - open);
		bottomTail = (isBullish()) ? (open - low) : (close - low);
	}

	SmartCandlestick(Candlestick^ candlestick) {
		date = candlestick->date;
		high = candlestick->high;
		low = candlestick->low;
		open = candlestick->open;
		close = candlestick->close;
		volume = candlestick->volume;

		topPrice = (isBullish()) ? close : open;
		bottomPrice = (isBullish()) ? open : close;
		totalRange = fabs(high - low);
		bodyRange = fabs(open - close);
		topTail = (isBullish()) ? (high - close) : (high - open);
		bottomTail = (isBullish()) ? (open - low) : (close - low);
	}

	bool isBullish() {
		return (close > open);
	}

	bool isBearish() {
		return (open > close);
	}

	// Doji

	bool isDoji() {
		return (bodyRange <= (0.01 * high));
	}

	bool isNeutralDoji() {
		return (isDoji() && !(isDragonflyDoji()) && !(isGravestoneDoji()));
	}

	bool isDragonflyDoji() {
		return ((isDoji()) && (topTail <= (bottomTail * 0.2)));
	}

	bool isGravestoneDoji() {
		return ((isDoji()) && (bottomTail <= (topTail * 0.2)));
	}

	// Hammers

	bool isHammerUpright() {
		return ((bodyRange <= (totalRange * 0.45)) && (bodyRange >= (totalRange * 0.1)) && (topTail <= (bottomTail * 0.15)));
	}

	bool isHammerInverted() {
		return ((bodyRange <= (totalRange * 0.45)) && (bodyRange >= (totalRange * 0.1)) && (bottomTail <= (topTail * 0.15)));
	}

	// Marubozu

	bool isMarubozu() {
		return (abs(bodyRange - totalRange) / bodyRange < 0.075);
	}
};

