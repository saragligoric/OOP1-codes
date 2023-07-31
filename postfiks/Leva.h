#pragma once
#include "Element.h"

class Leva :public Element{
public:
	char getoznaka() const override { return '('; }
	string getnatpis()const override { return "("; }
	Leva* kopija() const override {
		return new Leva(*this);
	}
};

