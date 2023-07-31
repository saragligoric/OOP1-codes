#include <iostream>
#include "Igrac.h"
#include "Tim.h"
#include "Privilegovani.h"
#include "Mec.h"

using namespace std;

int main() {
	try {
		Igrac i1("Milutin", 1300);
		Igrac i2("Boban", 100);
		Igrac i3("Ljubosav", 2000);
		Igrac i4("Zivorad", 1700);

		//Tim t1("Arsenal", 12);
		Tim* t1=new Tim("Arsenal", 12);
		t1->prikljuci(i1, 1);
		t1->prikljuci(i2, 6);
		cout << *t1<<endl;

		//Privilegovani p1("Arsenalprivpoy", 12, 1500);
		Privilegovani* p1=new Privilegovani("Arsenalprivpoy", 12, 1500);
		p1->prikljuci(i3, 6);
		p1->prikljuci(i4, 10);
		cout << *p1<<endl;

		Mec m1(t1, p1);
		cout << m1<<endl;
		//cout << m1.getpoenimeca();
		m1.odigraj();
		cout << m1;
		//cout << *(m1.getpar().getpok1())<<endl;
		//cout << *(m1.getpar().getpok2())<<endl;
		//cout << m1.poeni();
		cout << m1.getpoenimeca();//

		//cout <<endl<< "kopiranje"<<endl;
		//Privilegovani ptest("Arsenalprivpoy", 12, 1500);
		//cout << ptest<<endl;
		////Privilegovani pkopija(ptest);
		//Privilegovani pkopija = ptest;
		//cout << pkopija<<endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}