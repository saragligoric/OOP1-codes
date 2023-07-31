#include <iostream>
#include "Operand.h"
#include "Sabiranje.h"
#include "Leva.h"
#include "Desna.h"
#include "Izraz.h"
#include "Generator.h"

using namespace std;

int main() {
	try {
		Operand o1("A");
		Operand o2("B");
		Operand o3("C");
		Operand o4("D");
		Leva l1;
		Desna d1;
		Sabiranje s1;

		Izraz i;

		//prvi test primer
		/**i.getizraz() += &l1;
		*i.getizraz() += &l1;
		*i.getizraz() += &l1;
		*i.getizraz() += &o1;
		*i.getizraz() += &s1;
		*i.getizraz() += &o2;
		*i.getizraz() += &d1;
		*i.getizraz() += &s1;
		*i.getizraz() += &o3;
		*i.getizraz() += &d1;
		*i.getizraz() += &s1;
		*i.getizraz() += &o4;
		*i.getizraz() += &d1;*/

		//drugi test primer
		*i.getizraz() += &o1;
		*i.getizraz() += &s1;
		*i.getizraz() += &l1;
		*i.getizraz() += &l1;
		*i.getizraz() += &o2;
		*i.getizraz() += &s1;
		*i.getizraz() += &o3;
		*i.getizraz() += &d1;
		*i.getizraz() += &s1;
		*i.getizraz() += &o4;
		*i.getizraz() += &d1;

		//treci test primer (vraca gresku)
		/**i.getizraz() += &o1;
		*i.getizraz() += &s1;
		*i.getizraz() += &s1;
		*i.getizraz() += &o2;*/

		//cout << *i.getizraz();
		//cout<<i.getizraz()->getbrojpod()<<endl;
		//i.getizraz()->operator*();
		//i.getizraz()->operator-();
		cout << *i.getizraz();
		cout << i.getizraz()->getbrojpod() << endl;

		Generator::getgeninstance();
		cout<<*(Generator::getgeninstance().operator()(i).getizraz());
		//cout << endl << "kraj" << endl;
	}
	catch (exception e) {
		cout << e.what();
	}
}