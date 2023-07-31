#include "Aranzman.h"

int Aranzman::gettrajanje() const
{
    return *datpoc - *datkraj;
}

double Aranzman::getcena() const
{
    if (prevoz == nullptr || smestaj == nullptr) throw GPrevozsmestaj();
    else {
        return prevoz->getcenakarte() + smestaj->getcena() * gettrajanje();
    }
}

Aranzman& Aranzman::dodeliprevoz(Prevoz& p)
{
    if (p.getdestprevoz() == *dest) {
        prevoz = &p;
        return *this;
    }
    else throw GDestinacija();
}

Aranzman& Aranzman::dodelismestaj(Smestaj& s)
{
    if (s.getdest().getnaziv() != dest->getnaziv()) throw GDestinacija();
    else smestaj = &s;
    return *this;
}

ostream& operator<<(ostream& os, const Aranzman& a)
{
    os << *a.dest << endl;
    if (a.smestaj != nullptr) {
        os << *a.smestaj << endl;
    }
    os << a.getcena();
    return os;
}
