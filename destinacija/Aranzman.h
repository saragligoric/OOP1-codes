#pragma once
#include "Destinacija.h"
#include "Datum.h"
#include "Smestaj.h"
#include "Prevoz.h"
#include <iostream>

using namespace std;

class Aranzman{
	Destinacija* dest;
	Datum* datpoc;
	Datum* datkraj;
	Prevoz* prevoz=nullptr;
	Smestaj* smestaj=nullptr;
public:
	Aranzman(Destinacija& d, Datum& d1, Datum& d2) :dest(&d), datpoc(&d1), datkraj(&d2) {}

	Destinacija* getdest() const { return dest; }
	Datum* getdatpoc() const { return datpoc; }
	Datum* getdatkraj() const { return datkraj; }

	int gettrajanje() const;
	double getcena() const;

	Aranzman& dodeliprevoz(Prevoz& p);
	Aranzman& dodelismestaj(Smestaj& s);

	friend ostream& operator<<(ostream& os, const Aranzman& a);
};

