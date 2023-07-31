#ifndef _Lista_h_
#define _Lista_h_

#include "Greske.h"

template <typename T>
class Lista {
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& t, Elem* s = nullptr) :pod(t), sled(s) {}
	};
	Elem* prvi,*posl,*tek;
public:
	Lista() {
		prvi = posl = tek = nullptr;
	}

	Lista(const Lista* l) = delete;
	Lista& operator=(const Lista& l) = delete;

	~Lista() {
		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;
		}
		prvi = posl = tek = nullptr;
	}

	Lista& dodaj(const T& t);
	void naprvi();
	void nasled();
	bool postojitek() const;
	T& gettek() const;
};

template<typename T>
Lista<T>& Lista<T>::dodaj(const T& t){
	posl=(!prvi?prvi:posl->sled)= new Elem(t);
	return *this;
}

template<typename T>
void Lista<T>::naprvi(){
	tek = prvi;
}

template<typename T>
void Lista<T>::nasled(){
	if(tek)	tek = tek->sled;
}

template<typename T>
bool Lista<T>::postojitek() const{
	if (tek != nullptr) return true;
	else return false;
}

template<typename T>
T& Lista<T>::gettek() const{
	if (postojitek()) {
		return tek->pod;
	}
	else throw GNePostojiTek();
}

#endif
