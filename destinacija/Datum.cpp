#include "Datum.h"

Datum::Datum(int d, int m, int g)
{
	godina = g;
	if (m < 1 || m>12) {
		throw GDatum();
	}
	else mesec = m;
	switch (m) {
	case 1: case 3: case 5:case 7:case 8:case 10:case 12:
		if (d < 0 || d>31) throw GDatum();
		else dan = d;
	case 2:
		if (g % 400 == 0 || (g % 4 == 0 && g % 100 != 0)) {//moze 29
			if (d < 0 || d>29) throw GDatum();
			else dan = d;
		}
		else {
			if (d < 0 || d>28) throw GDatum();
			else dan = d;
		}
	case 4: case 6: case 9: case 11:
		if (d < 0 || d>30) throw GDatum();
		else dan = d;
	}
}

int operator-(const Datum& d1, const Datum& d2)
{
	int dani = 0;
	int dani1 = 0;
	int dani2 = 0;
	Datum date1 = d1;
	Datum date2 = d2;

	int danigod = 0;
	int danimes = 0;

	//racunamo za date1
	Datum hristeboze(1,1,1);
	while (hristeboze.godina != date1.godina) {
		if (hristeboze.godina % 400 == 0 || (hristeboze.godina % 4 == 0 && hristeboze.godina % 100 != 0)) {
			danigod = 366;
		}
		else {
			danigod = 365;
		}
		dani1 += danigod;
		hristeboze.godina++;
	}
	while (hristeboze.mesec != date1.mesec) {
		switch (hristeboze.mesec) {
		case 1: case 3: case 5:case 7:case 8:case 10:case 12:
			danimes = 31;
		case 2:
			if (hristeboze.godina % 400 == 0 || (hristeboze.godina % 4 == 0 && hristeboze.godina % 100 != 0)) {//moze 29, prestupna
				danimes = 29;
			}
			else {
				danimes=28;
			}
		case 4: case 6: case 9: case 11:
			danimes=30;
		}
		dani1 += danimes;
		hristeboze.mesec++;
	}
	while (hristeboze.dan != date1.dan) {
		dani1 ++;
		hristeboze.dan++;
	}
	//racunamo za date2 
	Datum hristebozespasime(1,1,1);
	while (hristebozespasime.godina != date2.godina) {
		if (hristebozespasime.godina % 400 == 0 || (hristebozespasime.godina % 4 == 0 && hristebozespasime.godina % 100 != 0)) {
			danigod = 366;
		}
		else {
			danigod = 365;
		}
		dani2 += danigod;
		hristebozespasime.godina++;
	}
	while (hristebozespasime.mesec != date2.mesec) {
		switch (hristebozespasime.mesec) {
		case 1: case 3: case 5:case 7:case 8:case 10:case 12:
			danimes = 31;
		case 2:
			if (hristebozespasime.godina % 400 == 0 || (hristebozespasime.godina % 4 == 0 && hristebozespasime.godina % 100 != 0)) {//moze 29, prestupna
				danimes = 29;
			}
			else {
				danimes = 28;
			}
		case 4: case 6: case 9: case 11:
			danimes = 30;
		}
		dani2 += danimes;
		hristebozespasime.mesec++;
	}
	while (hristebozespasime.dan != date2.dan) {
		dani2++;
		hristebozespasime.dan++;
	}
	//oduzmemo ih

	return abs(dani2 - dani1);
}

ostream& operator<<(ostream& os, const Datum& d)
{
	return os << d.dan << "." << d.mesec << "." << d.godina<<".";
}
