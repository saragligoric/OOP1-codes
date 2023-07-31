#pragma once
#include <exception>

using namespace std;

class GNePostojiTek :public exception{
public:
	GNePostojiTek() : exception("Ne postoji tekuci element") {}
};