#include "Igrac.h"

bool operator==(const Igrac& i1, const Igrac& i2)
{
	if (i1.ime == i2.ime && i1.vrednost == i2.vrednost) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Igrac& i)
{
	return os << i.ime << "#" << i.vrednost;
}

Igrac& Igrac::povecaj(double proc)
{
	vrednost += (proc / 100) * vrednost;
	return *this;
}

Igrac& Igrac::smanji(double proc)
{
	vrednost -= (proc / 100) * vrednost;
	return *this;
}
