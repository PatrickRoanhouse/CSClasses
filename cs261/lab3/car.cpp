#include "car.h"

Car::Car()
  :Vehicle()
{
  carState = IN_PARK;
}

  // Methods
void Car::turnoff()
{
  if (carState == IN_GEAR)
    cout << "The car cannot be turned off when not in park" << endl;
  else  // car is in park
    Vehicle::turnoff();
  return;
}

void Car::go()
{
  if (carState == IN_GEAR)
    Vehicle::go();
  else  // car is in park
    cout << "The car is in park, you cannot go" << endl;
  return;
}

void Car::park()
{
  carState = IN_PARK;
  return;
}

void Car::gear()
{
  carState = IN_GEAR;
  return;
}

