#include "Operator.h"

bool operator>(const Operator& o1, const Operator& o2)
{
	if (o1.getprioritet() > o2.getprioritet()) return true;
	else return false;
}
