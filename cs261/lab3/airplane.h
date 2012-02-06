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
    Airplane(int fuel, int fuelUsage, const char *type, int engineNumbers);

      // Methods
    void takeoff();
    void land();
      // Overidden methods
    void go();
    void turnoff();

  private:
    EngineType engineType;
    AirplaneState planeState;
    int numberOfEngines;
};
#endif
