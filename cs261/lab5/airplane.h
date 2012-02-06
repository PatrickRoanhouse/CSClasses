#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "vehicle.h"
#include <cstring>

typedef enum {PROP, JET} EngineType;
typedef enum {ON_AIR, ON_GROUND} AirplaneState;

class Airplane:public Vehicle
{
  public:
      // Constructors
    Airplane();
    Airplane(const char * name);
    Airplane(int fuel, int fuelUsage, const char *type, int engineNumbers, const char *name, const int passengerLimit=250);

      // Methods
    void takeoff();
    void land();
      // Overidden methods
    void go();
    void turnoff();
    const char * getName();
    
    bool operator==(const Airplane &a) const;
    bool operator==(const Airplane *a) const;

  private:
    EngineType engineType;
    AirplaneState planeState;
    int numberOfEngines;
    
    friend ostream& operator<<(ostream &out, const Airplane &a);
    friend ostream& operator<<(ostream &out, const Airplane *a);
};
#endif
