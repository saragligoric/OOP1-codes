#include "Tim.h"

bool operator==(const Tim& t1, const Tim& t2)
{
	if (t1.nazivtima != t2.nazivtima || t1.dim != t2.dim) return false;

	for (int i = 0; i < t1.dim; i++) {
		if (t1.tim[i] == nullptr && t2.tim[i] != nullptr) return false;
		if (t1.tim[i] != nullptr && t2.tim[i] == nullptr) return false;
		if (t1.tim[i] != nullptr && t2.tim[i] != nullptr) {
			if (*t1.tim[i] == *t2.tim[i]) return true;
			else return false;
		}
	}

	return true;
}

ostream& operator<<(ostream& os, const Tim& t)
{
	t.pisi(os);
	return os;
}

void Tim::kopiraj(const Tim& t)
{
	nazivtima = t.nazivtima;
	trenbroj = t.trenbroj;
	tim = new Igrac * [dim = t.dim];
	for (int i = 0; i < dim; i++) {
		tim[i] = t.tim[i];
	}
}

void Tim::premesti(Tim& t)
{
	nazivtima = t.nazivtima;
	trenbroj = t.trenbroj;
	tim = t.tim;
	dim = t.dim;
	t.tim = nullptr;
}

void Tim::brisi()
{
	delete[] tim;
	tim = nullptr;
}

Tim& Tim::prikljuci(Igrac& i, int poz)
{
	tim[poz-1] = &i;
	trenbroj++;
	return *this;
}

double Tim::getsrvred() const
{
	double sum = 0;
	for (int i = 0; i < dim; i++) {
		if (tim[i] != nullptr) {
			sum += tim[i]->getvrednost();
		}
	}
	return sum / trenbroj;
}

Igrac* Tim::operator[](int poz)
{
	return tim[poz-1];
}

const Igrac* Tim::operator[](int poz) const
{
	return const_cast<Tim&>(*this)[poz - 1];
}

void Tim::pisi(ostream& os) const
{
	os << nazivtima;
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
	os << "]" ;
}
