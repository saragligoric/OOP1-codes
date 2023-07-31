#include <iostream>
#include "Datum.h"
#include "Osoba.h"
#include "Dinarski.h"
#include "Racun.h"

using namespace std;

int main() {
	Datum d1;
	Datum d2(9, 8, 2000);
	
	Osoba o1("Sara", "35425", d1);
	Osoba o2("Milica", "4184311", d2);

	Dinarski din1(o1, 100, 1300);
	Dinarski din2(o2, 200, 2500);
	din1.prenos(1500, din2);
	cout << din1<<din2;
}