#pragma once
#include <exception>

using namespace std;

class GNedovoljnavrednost :public exception {
public:
	GNedovoljnavrednost() :exception("Igrac nema dovoljnu vrednost da se prikljuci timu") {}
};

class GNeodigran: public exception {
public:
	GNeodigran() :exception("Mec nije odigran") {}
};