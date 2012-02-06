#ifndef FLEET_H
#define FLEET_H
#include "bst.h"
#include "vehicle.h"
#include <iostream>

class Fleet:public BST<Vehicle>
{
  public:
    Fleet();
    void insert(Vehicle &v);
    void remove(const char *key);
    void print() const;
    
};


#endif
