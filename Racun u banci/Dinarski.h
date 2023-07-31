#pragma once
#include "Racun.h"

class Dinarski :public Racun{
public:
	Dinarski(Osoba& o, int b, double i = 0) :Racun(o, b, i) {}
	string getvaluta() const override { return "RSD"; }
};

