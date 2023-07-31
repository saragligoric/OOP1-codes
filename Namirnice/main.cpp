#include <iostream>
#include "Nutritivna.h"
#include "Namirnica.h"
#include "Sastojak.h"
#include "Lista.h"

using namespace std;

int main() {
	Nutritivna n1(100, 200, 40);
	Nutritivna n2(20, 12, 60);
	
	Namirnica nam1("sir", n1, false);
	Namirnica nam2("riba", n2, true);
	
	Sastojak s1(nam1, 3);
	cout << s1.nutritivna();
	cout << s1.kal();
}