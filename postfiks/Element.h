#pragma once
#include <string>
#include <iostream>

using namespace std;

class Element{
public:
	virtual char getoznaka() const = 0;
	virtual string getnatpis()const = 0;
	virtual Element* kopija() const = 0;

	virtual ~Element() {};

	friend ostream& operator<<(ostream& os, const Element& el) {
		return os << el.getnatpis();
	}
};

