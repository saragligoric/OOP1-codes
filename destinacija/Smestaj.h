#pragma once
#include "Destinacija.h"
#include "Greske.h"

class Smestaj{
public:
	enum Tip{HOTEL,APARTMAN};
private:
	Destinacija dest;
	string naziv;
	Tip tip;
	int zvezdice;
	double cena;
public:
	Smestaj(const Destinacija& d, string n, Tip t, int z, double c) :dest(d), naziv(n), tip(t), cena(c) {
		if (z < 1 || z>5) throw GZvezdice();
		else zvezdice = z;
	}

	Destinacija getdest() const { return dest; }
	string getnaziv() const { return naziv; }
	Tip gettip() const { return tip; }
	int getzvezdice() const { return zvezdice; }
	double getcena() const { return cena; }

	friend ostream& operator<<(ostream& os, const Smestaj& s);
};

