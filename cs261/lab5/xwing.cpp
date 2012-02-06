#include "xwing.h"

Xwing::Xwing()
  :Airplane(500, 10, "jet", 4, "default Xwing", 1)
{
}

Xwing::Xwing(const char *name)
  :Airplane(500, 10, "jet", 4, name, 1)
{
}

void Xwing::fire() const
{
    std::cout << "shooting at virtual enemies..." << std::endl;
    return;
}

ostream& operator<<(ostream &out, const Xwing *x)
{
    const Airplane * a = x;
    out << "<X-wing>" << endl << "{" << endl;
    out << "  " << a << endl;
    out << "}" << endl;
    
    return out;
}
ostream& operator<<(ostream &out, const Xwing &x)
{
    const Airplane * a = &x;
    out << "<X-wing>" << endl << "{" << endl;
    out << "  " << *a << endl;
    out << "}" << endl;
    
    return out;
}