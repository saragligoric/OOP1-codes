#pragma once
#include "Izraz.h"

class Generator {
private:
	Generator() {};
public:
	static Generator& getgeninstance() {
		static Generator gen;
		return gen;
	}

	Generator(const Generator& g) = delete;
	Generator& operator=(const Generator& g) = delete;

	Izraz& operator()(Izraz& i);
};

