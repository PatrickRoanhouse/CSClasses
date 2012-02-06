#include "car.h"

Car::Car()
  :Vehicle("default Car", 5)
{
  carState = IN_PARK;
}

Car::Car(const char *name)
:Vehicle(name, 5)
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

const char * Car::getName() const
{
    return (Vehicle::getName());
}

bool Car::operator==(const Car *c) const
{
    if (this != c)
    {
        const Vehicle * v1 = c;
        const Vehicle * v2 = this;
        
        return ( (v1 == v2) && (carState == c -> carState));
    }
    else
        return false;
}

bool Car::operator==(const Car &c) const
{
    if (this != &c)
    {
        const Vehicle * v1 = &c;
        const Vehicle * v2 = this;
        
        return ( (v1 == v2) && (carState == c.carState));
    }
    else
        return false;
}
ostream& operator<<(ostream &out, const Car *c)
{
    const Vehicle * v = c;
    out << "<Car>" << endl << "{" << endl;
    out << "  ";
    out << *v << endl;
    out << "  car_state: ";
    
    
    if (c -> carState == IN_PARK)
        out << "IN_PARK";
    else
        out << "IN_GEAR";
    
    out << endl << "}";
    
    return out;
}

ostream& operator<<(ostream &out, const Car &c)
{
    const Vehicle *v = &c;
    out << "<Car>" << endl << "{" << endl;
    out << "  " << *v << endl;
    out << "  car_state: ";
    
    
    if (c.carState == IN_PARK)
        out << "IN_PARK";
    else
        out << "IN_GEAR";
    
    out << endl << "}";
    
    return out;
}
