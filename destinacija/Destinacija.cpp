#include "Destinacija.h"

Destinacija& Destinacija::oceni(int ocena)
{
	if (ocena > 0 || ocena <= 5) {
		prosocena *= brojocena;
		prosocena += ocena;
		brojocena++;
		prosocena /= brojocena;
	}
	return *this;
}

bool operator>(const Destinacija& d1, const Destinacija& d2)
{
	if (d1.getprosocena() > d2.getprosocena()) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Destinacija& d)
{
	return os << "[" << d.prosocena << "] " << d.naziv << "(" << d.opis << ")";
}

bool operator==(const Destinacija& d1, const Destinacija& d2)
{
	if (d1.naziv == d2.naziv && d1.opis == d2.opis && d1.prosocena == d2.prosocena) return true;
	else return false;
}
