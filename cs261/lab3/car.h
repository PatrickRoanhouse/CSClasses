#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

typedef enum {IN_PARK, IN_GEAR} CarState;

class Car:public Vehicle
{
  public:
    // Constructor
  Car();

    // Methods
  void turnoff();
  void go();
  void park();
  void gear();

  private:
    CarState carState;
};
#endif
