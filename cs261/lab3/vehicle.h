#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

typedef enum {ON, OFF} State;

class Vehicle
{
  public:
      // Constructors
    Vehicle();
    Vehicle(int fuelAmount, int fuelUsageRate);

      // Methods
    void turnon();
    void turnoff();
    void go();
    void addFuel(int fuelAmount);

  protected:
    State getVehicleState();
    int getFuelUsageRate();
    int getFueCapacity();
    void setFuelCapacity(int capacity);
    void setVehicleState(State state);

  private:
    int fuelUsageRate;
    int fuelCapacity;
    State vehicleState;

};

#endif
