#pragma once
#include "Element.h"

class Operand:public Element{
	string natpis;
public:
	Operand(string n) :natpis(n) {}
	char getoznaka() const override { return 'D'; };
	string getnatpis()const override {
		return natpis;
	};
	Operand* kopija() const override{ 
		return new Operand(*this);
	};
};

