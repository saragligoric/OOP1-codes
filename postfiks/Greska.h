#pragma once
#include <exception>

using namespace std;

class GPrazna :public exception {
public:
	GPrazna() :exception("Lista iz koje pokusavate da uklonite element je prazna!") {}
};

class GPostfiks :public exception {
public:
	GPostfiks() :exception("Nije moguce generisati  ispravan izraz u postfiksnom obliku") {}
};

