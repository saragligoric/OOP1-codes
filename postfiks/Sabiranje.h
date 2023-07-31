#pragma once
#include "Operator.h"

class Sabiranje :public Operator{
public:
	int getprioritet()const override {
		return 1;
	}

	string getnatpis()const override {
		return "+";
	};

	Sabiranje* kopija() const override {
		return new Sabiranje(*this);
	}
};

