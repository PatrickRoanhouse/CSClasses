#ifndef XWING_H
#define XWING_H
#include "airplane.h"
#include <iostream>

class Xwing:public Airplane
{
  public:
    Xwing();
    Xwing(const char *name);
    
    void fire() const;
    
    friend ostream& operator<<(ostream &out, const Xwing &x);
    friend ostream& operator<<(ostream &out, const Xwing *x);
    
};

#endif
