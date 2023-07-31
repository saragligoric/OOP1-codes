#include "Sastojak.h"

ostream& operator<<(ostream& os, const Sastojak& n)
{
	return os << "[" << n.nam.getnutr().kalorije() << " kcal ] " << n.kolicina << " g x " << n.nam << endl;
}

Nutritivna Sastojak::nutritivna() const
{
	return Nutritivna(nam.getnutr().gethidrati() / 100 * getkolicina(), nam.getnutr().getmasti() / 100 * getkolicina(), nam.getnutr().getproteini() / 100 * getkolicina());
}

double Sastojak::kal() const
{
	return nutritivna().kalorije();
}
