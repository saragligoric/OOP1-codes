#pragma once
#include <string>
#include <iostream>

using namespace std;

class Destinacija{
	string naziv;
	string opis;
	double prosocena=0;
	int brojocena = 0;
public:
	Destinacija(string n, string o) :naziv(n), opis(o) {}

	Destinacija& oceni(int ocena);

	friend bool operator>(const Destinacija& d1, const Destinacija& d2);

	string getnaziv()const { return naziv; }
	string getopis() const { return opis; }
	double getprosocena()const { return prosocena; }

	friend ostream& operator<<(ostream& os, const Destinacija& d);

	friend bool operator==(const Destinacija& d1, const Destinacija& d2);
};

