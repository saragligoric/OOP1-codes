#pragma once
#include "Datum.h"
#include <string>

using namespace std;

class Osoba{
	string ime;
	string maticni;
	Datum dat;
public:
	Osoba(string i, string m, const Datum& d) :ime(i), maticni(m), dat(d) {}
	Osoba(const Osoba&) = delete;
	Osoba& operator=(const Osoba& o) = delete;

	string getime() const { return ime; }
	string getmaticni() const { return maticni; }
	Datum getdatum() const { return dat; }

	friend ostream& operator<<(ostream& os, const Osoba& d);
};

