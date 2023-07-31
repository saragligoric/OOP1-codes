#include "Mec.h"
#include "Greska.h"

ostream& operator<<(ostream& os, const Mec& m)
{
	string sishod[]{ "POBEDA_DOMACIN","NERESENO","POBEDA_GOST" };
	os << m.timovi;
	if (m.odigran) os << sishod[m.ishod] << endl;
	return os;
}

Mec& Mec::odigraj()
{
	odigran = true;
	if (timovi.getpok1()->getsrvred() > timovi.getpok2()->getsrvred()) {
		ishod = Ishod::POBEDA_DOMACIN;
		poenimeca.postavipok1(new int(3));
		poenimeca.postavipok2(new int(0));
		for (int i = 1; i <= timovi.getpok1()->getdim(); i++) {
			if (timovi.getpok1()->operator[](i) != nullptr) {
				timovi.getpok1()->operator[](i)->povecaj(10);
			}
		}
		for (int i = 1; i <= timovi.getpok2()->getdim(); i++) {
			if (timovi.getpok2()->operator[](i) != nullptr) {
				timovi.getpok2()->operator[](i)->smanji(10);
			}
		}
	}
	else if (timovi.getpok1()->getsrvred() < timovi.getpok2()->getsrvred()) {
		ishod = Ishod::POBEDA_GOST;
		poenimeca.postavipok1(new int(0));
		poenimeca.postavipok2(new int(3));
		for (int i = 1; i <= timovi.getpok1()->getdim(); i++) {
			if ((timovi.getpok1()->operator[](i)) != nullptr) {
				timovi.getpok1()->operator[](i)->smanji(10);
			}
		}
		for (int i = 1; i <= timovi.getpok2()->getdim(); i++) {
			if (timovi.getpok2()->operator[](i) != nullptr) {
				timovi.getpok2()->operator[](i)->povecaj(10);
			}
		}
	}
	else {
		ishod = Ishod::NERESENO;
		poenimeca.postavipok1(new int(1));
		poenimeca.postavipok2(new int(1));
	}
	return *this;
}

