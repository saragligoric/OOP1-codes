#include "Racun.h"

ostream& operator<<(ostream& os, const Racun& r)
{
    return os << "R:" << r.broj << ": = :" << r.iznos <<"-"<< r.getvaluta() << endl;
}

Racun& Racun::operator+=(double i)
{
    iznos += i;
    return *this;
}

bool Racun::prenos(double i, Racun& rna)
{   
    if (iznos < i) return false;
    else {
        iznos -= i;
        rna.iznos += i;
        return false;
    }
}
