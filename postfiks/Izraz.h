#pragma once
#include "Lista.h"
#include "Element.h"

class Izraz {
	Lista<Element> izraz;
public:		
	Lista<Element>* getizraz() { return &izraz; }

	virtual Izraz* polikopija() const {
		return new Izraz(*this);
	}
};
