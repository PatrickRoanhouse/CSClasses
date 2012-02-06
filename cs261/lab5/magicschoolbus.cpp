#include "magicschoolbus.h"

Magicschoolbus::Magicschoolbus()
  :Car("default Magicschoolbus")
{
}

Magicschoolbus::Magicschoolbus(const char *name)
:Car(name)
{
}

ostream& operator<<(ostream &out, const Magicschoolbus *b)
{
    const Car *c = b;
    out << "<Magicschoolbus>" << endl << "{" << endl;
    out << c << endl;
    out << endl << "}";
    return out;
}

ostream& operator<<(ostream &out, const Magicschoolbus &b)
{
    const Car *c = &b;
    out << "<Magicschoolbus>" << endl << "{" << endl;
    out << *c << endl;
    out << endl << "}";
    return out;
}
