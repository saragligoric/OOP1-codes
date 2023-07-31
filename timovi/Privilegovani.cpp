#include "Privilegovani.h"
#include "Greska.h"

Privilegovani& Privilegovani::prikljuci(Igrac& i, int poz)
{
	if (i.getvrednost() < minvred) throw GNedovoljnavrednost();
	else Tim::prikljuci(i, poz);
}

void Privilegovani::pisi(ostream& os) const
{
	os << nazivtima;
	os << "(" << minvred << ")";
	bool flag = true;
	os << "[";
	for (int i = 0; i < dim; i++) {
		if (!flag && tim[i] != nullptr) {
			os << ", ";
		}
		if (tim[i] != nullptr) {
			os << *(tim[i]);
			flag = false;
		}
	}
	os << "]";
}
