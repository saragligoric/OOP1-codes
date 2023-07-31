#ifndef _Lista_h_
#define _Lista_h_

#include "Greska.h"
#include <iostream>

using namespace std;

template <typename T>
class Lista {
private:
	struct Elem {
		T* pod;
		Elem* sled;
		Elem(T* t, Elem* s = nullptr) :pod(t->kopija()), sled(s) {}
	};
	Elem* prvi = nullptr,*posl=nullptr;
	int brojpod = 0;

	void kopiraj(const Lista& l);
	void premesti(Lista& l);
	void brisi();
public:
	Lista() = default;
	Lista(const Lista& l) {
		kopiraj(l);
	}
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista(Lista&& l) {
		premesti(l);
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}
	~Lista() {
		brisi();
	}

	Lista& operator+=(T* t);

	int getbrojpod()const { return brojpod; }

	//uklanja podatak sa kraja
	T* operator-();
	//uklanja podatak sa pocetka
	T* operator*();

	friend ostream& operator<<(ostream& os, const Lista<T>& l) {
		for (Elem* pom = l.prvi; pom; pom = pom->sled) {
			os << *pom->pod << " ";
		}
		return os;
	}

	T* topstack() {
		T* pom = posl->pod;
		return pom;
	}
};

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	prvi = posl = nullptr;
	brojpod = l.brojpod;
	for (Elem* pom = l.prvi; pom; pom = pom->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(pom->pod);
	}
}

template<typename T>
inline void Lista<T>::premesti(Lista& l)
{
	brojpod = l.brojpod;
	prvi = l.prvi;
	posl = l.posl;
	l.prvi = l.posl = nullptr;
}

template<typename T>
inline void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	prvi = posl = nullptr;
	brojpod = 0;
}

template<typename T>
Lista<T>& Lista<T>::operator+=(T* t)
{
	posl = (!prvi ? prvi : posl->sled) = new Elem(t);
	brojpod++;
	return *this;
}

template<typename T>
T* Lista<T>::operator-()
{
	if (!prvi) {
		throw GPrazna();
	}
	else {
		T* pom = posl->pod;
		Elem* stari = posl;
		Elem* tek = prvi;
		while (tek->sled != posl && posl!=prvi) {
			tek = tek->sled;
		}
		tek->sled = nullptr;
		if (posl == prvi) posl = prvi = nullptr;
		else posl = tek;
		//if (!posl) prvi = nullptr;
		brojpod--;
		delete stari;
		return pom;
	}
}

template<typename T>
T* Lista<T>::operator*()
{
	if (!prvi) {
		throw GPrazna();
	}
	else {
		T* pom = prvi->pod;
		Elem* stari = prvi;
		if (posl == prvi) posl = prvi = nullptr;//
		else prvi = prvi->sled;
		delete stari;
		brojpod--;
		return pom;
	}
}

#endif
