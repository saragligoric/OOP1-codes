#pragma once
#include "Destinacija.h"

class Prevoz{
	Destinacija destprevoz;
	double cenakarte;
public:
	Prevoz(const Destinacija& d, double c) :destprevoz(d), cenakarte(c) {};

	Destinacija getdestprevoz() const { return destprevoz; }
	double getcenakarte() const { return cenakarte; }
};

