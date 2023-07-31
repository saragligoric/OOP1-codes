#include "Smestaj.h"

ostream& operator<<(ostream& os, const Smestaj& s)
{
	string tipsmestaja[]{ "HOTEL","APARTMAN" };
	os << tipsmestaja[s.tip] << " " << s.naziv << " ";
	for (int i = 0; i < s.zvezdice; i++) {
		os << "*";
	}
	os << endl;
	return os;
}
