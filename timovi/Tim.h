#pragma once
#include <string>
#include <iostream>
#include "Igrac.h"

using namespace std;

class Tim{
protected:
	string nazivtima;
	int dim;
	int trenbroj=0;
	Igrac** tim;

	void kopiraj(const Tim& t);
	void premesti(Tim& t);
	void brisi();
public:
	Tim(string ime, int d) :nazivtima(ime), dim(d) {
		tim = new Igrac*[dim];
		for (int i = 0; i < dim; i++) {
			tim[i] = nullptr;
		}
	}

	Tim(const Tim& t) {
		kopiraj(t);
	}
	Tim& operator=(const Tim& t) {
		if (this != &t) {
			brisi();
			kopiraj(t);
		}
		return *this;
	}
	Tim(Tim&& t) {
		premesti(t);
	}
	Tim& operator=(Tim&& t) {
		if (this != &t) {
			brisi();
			premesti(t);
		}
		return *this;
	}
	~Tim() {
		brisi();
	}

	virtual Tim& prikljuci(Igrac& i, int poz);

	int getdim() const { return dim; }
	int gettrenbroj() const { return trenbroj; }
	double getsrvred() const;

	friend bool operator==(const Tim& t1, const Tim& t2);

	Igrac* operator[](int poz);
	const Igrac* operator[](int poz) const;

	friend ostream& operator<<(ostream& os, const Tim& t);
	virtual void pisi(ostream& os) const;
};

