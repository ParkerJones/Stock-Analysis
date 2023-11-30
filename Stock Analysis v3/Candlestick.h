#pragma once

/// <summary>
/// Representation of a single "candlestick" of a stock chart.
/// </summary>
ref class Candlestick
{
public:
	property System::DateTime^ date;
	property double high;
	property double low;
	property double open;
	property double close;
	property long volume;

	Candlestick(System::DateTime^ dt, double h, double l, double o, double c, long v) {
		date = dt;
		high = h;
		low = l;
		open = o;
		close = c;
		volume = v;
	}

	Candlestick() {
		date = System::DateTime::Now;
		high = 0;
		low = 0;
		open = 0;
		close = 0;
		volume = 0;
	}
};

