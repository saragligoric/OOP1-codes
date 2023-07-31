#pragma once
#include "Par.h"
#include "Tim.h"
#include <iostream>

using namespace std;

class Mec{
public:
	enum Ishod{POBEDA_DOMACIN,NERESENO,POBEDA_GOST};
private:
	Par<Tim> timovi;
	Ishod ishod;
	bool odigran = false;
	Par<int> poenimeca=Par<int>(new int(0), new int(0));
public:
	Mec(Tim* p1, Tim* p2) :timovi(p1, p2) {}

	Par<Tim> getpar() const { return timovi; }
	Par<int> getpoenimeca()const { return poenimeca; }

	bool bodigran() const { return odigran; }
	Mec& odigraj();

	friend ostream& operator<<(ostream& os, const Mec& m);
};

