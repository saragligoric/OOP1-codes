#pragma once
#include <string>
#include <iostream>

using namespace std;

class Igrac{
	string ime;
	int vrednost;
public:
	Igrac(string i, int b = 1000) :ime(i), vrednost(b) {}

	string getime() const { return ime; }
	int getvrednost() const { return vrednost; }

	Igrac& povecaj(double proc);
	Igrac& smanji(double proc);

	friend bool operator==(const Igrac& i1, const Igrac& o2);

	friend ostream& operator<<(ostream& os, const Igrac& i);
};

