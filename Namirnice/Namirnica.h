#pragma once
#include <string>
#include "Nutritivna.h"

using namespace std;

class Namirnica{
	string naziv;
	Nutritivna nutr;//vrednost na 100 grama
	bool posna;
public:
	Namirnica(string n, Nutritivna nutr, bool p) :naziv(n), nutr(nutr), posna(p) {}

	string getnaziv() const { return naziv; }
	Nutritivna getnutr() const { return nutr; }
	bool getposna() const { return posna; }

	friend bool operator==(const Namirnica& n1, const Namirnica& n2);

	friend ostream& operator<<(ostream& os, const Namirnica& n);
};

