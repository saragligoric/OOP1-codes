#include "Generator.h"
#include "Lista.h"
#include "Greska.h"
#include <iostream>

using namespace std;

Izraz& Generator::operator()(Izraz& i)
{
	int rang = 0;

	Izraz& pf=*new Izraz;	//postfiks
	cout << *pf.getizraz()<<endl;//
	Lista<Element> stek;	//stek
	//cout << stek << endl;//
	Element* next = i.getizraz()->operator*();
	//cout << *i.getizraz()<<endl;//
	int y = (i.getizraz()->getbrojpod());
	for (; y >= 0; y--) {
		if (next->getoznaka() == 'D') {
			*pf.getizraz() += next;//operand baca u postfiks
			//cout << *pf.getizraz() << endl;//
			rang++;
		}
		if (next->getoznaka() == 'O') {
			while (stek.getbrojpod() != 0 && next->kopija()->getoznaka() <= stek.topstack()->kopija()->getoznaka()) {
				*pf.getizraz() += stek.operator-();//ono sto je na vrhu steka baca u postfiks (operator)
				//cout << "postfiks" << *pf.getizraz() << endl;//
				//cout << "stek" << stek << endl;//
				rang--;
			}
			stek += next;//operator baca na stek
			//cout << "stek" << stek << endl;//
		}
		if (next->getoznaka() == '(') {
			stek += next;//zagrada se baca na stek
		}
		if (next->getoznaka() == ')') {
			while (stek.topstack()->getoznaka() != '(') {
				*pf.getizraz() += stek.operator-();
				rang--;
			}
			stek.operator-();
		}
		if (i.getizraz()->getbrojpod()!=0) {
			next = i.getizraz()->operator*();
		}
		//cout << *i.getizraz() << endl;
	}
	while (stek.getbrojpod() != 0) {
		*pf.getizraz() += stek.operator-();
		rang--;
	}

	if (rang != 1) throw GPostfiks();
	return pf;
}
