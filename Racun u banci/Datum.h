#pragma once
#include <iostream>

using namespace std;

class Datum{
	int dan, mesec, godina;
public:
	Datum(int d=1, int m=1, int g=2021) :dan(d), mesec(m), godina(g) {}
	friend bool operator==(const Datum& d1, const Datum& d2);

	friend ostream& operator<<(ostream& os, const Datum& d);
};

