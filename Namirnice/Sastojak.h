#pragma once
#include "Namirnica.h"

class Sastojak{
	Namirnica nam;
	double kolicina;
public:
	Sastojak(const Namirnica& n, double kol) :nam(n), kolicina(kol) {}

	Namirnica getnam()const { return nam; }
	double getkolicina() const { return kolicina; }

	Nutritivna nutritivna() const;
	double kal() const;

	friend ostream& operator<<(ostream& os, const Sastojak& n);
};

