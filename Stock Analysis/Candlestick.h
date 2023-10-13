#pragma once

ref class Candlestick
{
public:
	System::DateTime^ date;
	double high;
	double low;
	double open;
	double close;
	long volume;

	Candlestick(System::DateTime^ dt, double h, double l, double o, double c, long v) {
		date = dt;
		high = h;
		low = l;
		open = o;
		close = c;
		volume = v;
	}
};

