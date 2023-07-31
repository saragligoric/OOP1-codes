#pragma once
#include <iostream>

using namespace std;

class Nutritivna{
	double hidrati, masti, proteini;
public:
	Nutritivna(double h, double m, double p) :hidrati(h), masti(m), proteini(p) {}

	double gethidrati()const { return hidrati; }
	double getmasti()const { return masti; }
	double getproteini()const { return proteini; }

	double kalorije() const;

	friend Nutritivna operator+(const Nutritivna& n1, const Nutritivna& n2);

	friend ostream& operator<<(ostream& os, const Nutritivna& n);
};

