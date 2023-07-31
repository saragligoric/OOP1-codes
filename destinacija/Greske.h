#pragma once
#include <exception>

using namespace std;

class GZvezdice :public exception {
public:
	GZvezdice() :exception("Broj zvezdica je van opsega") {}
};

class GDatum :public exception {
public:
	GDatum() :exception("Neispravan datum") {}
};

class GDestinacija :public exception {
public:
	GDestinacija() :exception("Nije vezano za destinaciju") {}
};
class GPrevozsmestaj :public exception {
public:
	GPrevozsmestaj() :exception("Nema prevoza ili smestaja") {}
};
