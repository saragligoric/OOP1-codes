#pragma once
#include "Element.h"

class Desna :public Element {
public:
	char getoznaka() const override { return ')'; }
	string getnatpis()const override { return ")"; }
	Desna* kopija() const override {
		return new Desna(*this);
	}
};
