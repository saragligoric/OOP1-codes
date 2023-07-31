#pragma once
#include "Tim.h"

class Privilegovani :public Tim{
	int minvred;
public:
	Privilegovani(string ime, int d, int v) :Tim(ime, d), minvred(v) {}

	Privilegovani& prikljuci(Igrac& i, int poz) override;

	void pisi(ostream& os) const override;
};

