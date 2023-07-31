#pragma once
#include "Element.h"

class Operator:public Element{
public:
	virtual int getprioritet()const = 0;
	char getoznaka() const override{ return 'O'; }

	friend bool operator>(const Operator& o1, const Operator& o2);
};

