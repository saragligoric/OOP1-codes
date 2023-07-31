#pragma once
#include <iostream>
#include "Osoba.h"

using namespace std;

class Racun{
	Osoba& vlasnik;
	int broj;
	double iznos;
public:
	Racun(Osoba& o, int b, double i = 0) :vlasnik(o), broj(b), iznos(i) {}
	Racun(const Racun&) = delete;
	Racun& operator=(const Racun&) = delete;

	int getbroj() const { return broj; }
	double getiznos() const { return iznos; }
	virtual string getvaluta() const=0;				

	Racun& operator+=(double i);
	bool prenos(double i, Racun& rna);

	friend ostream& operator<<(ostream& os, const Racun& r);
};

