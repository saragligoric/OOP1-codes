#include <iostream>
#include "Destinacija.h"
#include "Smestaj.h"
#include "Datum.h"
#include "Aranzman.h"

using namespace std;

int main() {
	try {
		Destinacija dst1("Dubai", "vodi me bilo gde bmk");
		dst1.oceni(5);
		dst1.oceni(3);
		dst1.oceni(4);
		cout << dst1<<endl;

		Smestaj s1(dst1, "Kapri", Smestaj::APARTMAN, 4, 1200);
		cout << s1;

		Datum d1(9, 8, 2000);
		cout << d1;
		Datum d2(25, 9, 2000);
		cout << d2<<endl;
		cout << d2-d1<<endl;

		Prevoz prev1(dst1, 100);

		Aranzman a1(dst1, d1, d2);
		a1.dodeliprevoz(prev1);
		a1.dodelismestaj(s1);
		cout << a1;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}
