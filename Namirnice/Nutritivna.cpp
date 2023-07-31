#include "Nutritivna.h"
#include "Nutritivna.h"

Nutritivna operator+(const Nutritivna& n1, const Nutritivna& n2)
{
	return Nutritivna(n1.hidrati + n2.hidrati, n1.masti + n2.masti, n1.proteini + n2.proteini);
}

ostream& operator<<(ostream& os, const Nutritivna& n)
{
	return os << "[uh: " << n.hidrati << ", ma: " << n.masti << ", pr: " << n.proteini << "]" << endl;
}

double Nutritivna::kalorije() const
{
	return hidrati * 4 + proteini * 4 + masti * 9;
}
