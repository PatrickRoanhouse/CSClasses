#ifndef MAGIC_SCHOOL_BUS
#define MAGIC_SCHOOL_BUS
#include "car.h"

class Magicschoolbus:public Car
{
  public:
    Magicschoolbus();
    Magicschoolbus(const char *name);
    
    friend ostream& operator<<(ostream &out, const Magicschoolbus &b);
    friend ostream& operator<<(ostream &out, const Magicschoolbus *b);
    
};

#endif
