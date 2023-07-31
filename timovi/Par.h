#ifndef _Par_h_
#define _Par_h

#include <iostream>

using namespace std;

template <typename T>
class Par {
		T* pok1, * pok2;
public:
	Par(T* p1, T* p2) :pok1(p1), pok2(p2) {}

	T* getpok1() const { return pok1; }
	T* getpok2() const { return pok2; }

	void postavipok1(T* p) { pok1 = p; } 
	void postavipok2(T* p) { pok2 = p; }

	friend bool operator==(const Par& p1, const Par& p2) {
		if (p1.getpok1() == p2.getpok2()) return true;
		else return false;
	}

	friend ostream& operator<<(ostream& os, const Par& p) {
		return os << "[" << *p.getpok1() << "-" << *p.getpok2() << "]  ";
	}
};

#endif