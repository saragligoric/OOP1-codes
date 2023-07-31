#pragma once
#include "Greske.h"
#include <iostream>

using namespace std;

class Datum{
	int dan, mesec, godina;
public:
	Datum(int d, int m, int g);

	friend int operator-(const Datum& d1, const Datum& d2);

	friend ostream& operator<<(ostream& os, const Datum& d);
};

