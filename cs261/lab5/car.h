#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

typedef enum {IN_PARK, IN_GEAR} CarState;


class Car:public Vehicle
{
  public:
    // Constructor
  Car();
  Car(const char *name);

    // Methods
  void turnoff();
  void go();
  void park();
  void gear();
  const char * getName() const;
    
  bool operator==(const Car &c) const;
  bool operator==(const Car *c) const;

  private:
    CarState carState;
    
  friend ostream& operator<<(ostream &out, const Car &c);
  friend ostream& operator<<(ostream &out, const Car *c);
};
#endif
