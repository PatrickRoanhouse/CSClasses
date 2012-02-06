#include "vehicle.h"

  // Constructors
Vehicle::Vehicle()
{
  fuelCapacity  = 0;
  fuelUsageRate = 10;
  vehicleState  = OFF;
}

Vehicle::Vehicle(int fuelAmount, int usageRate)
{
  fuelCapacity  = fuelAmount;
  fuelUsageRate = usageRate;
  vehicleState  = OFF;
}

  // Public Methods
void Vehicle::turnon()
{
  if (vehicleState == OFF && fuelCapacity > 0)
  {
    vehicleState = ON;
    cout << "Started vehicle" << endl;
  }

  else if (vehicleState == ON)
    cout << "the vehicle is already on" << endl;

  else // fuelCapacity == 0
    cout << "there is no fuel in the vehicle" << endl;

  return;
}

void Vehicle::turnoff()
{
  if (vehicleState == ON)
  {
    vehicleState = OFF;
    cout << "Turned off vehicle" << endl;
  }

  else // vehicleState == OFF
    cout << "It's not running" << endl;

  return;
}

void Vehicle::go()
{
  if (vehicleState == ON)
  {
    if (fuelCapacity > 0)
    {
      fuelCapacity = fuelCapacity - fuelUsageRate;
      cout << "going..." << endl;
    }

    if (fuelCapacity <= 0)
    {
      cout << "vehicle is out of fuel" << endl;
      fuelCapacity = 0; // fuelCapacity could be negative
      turnoff();
    }
  }

  else
    cout << "the vehicle isn't on" << endl;
  return;
}

void Vehicle::addFuel(int amount)
{
  if (amount <=0)
    cout << "cannot take away fuel" << endl;
  else
    fuelCapacity = fuelCapacity + amount;

  return;
}

  // Protected Methods
State Vehicle::getVehicleState()
{
  return vehicleState;
}

int Vehicle::getFuelUsageRate()
{
  return fuelUsageRate;
}

int Vehicle::getFueCapacity()
{
  return fuelCapacity;
}

void Vehicle::setFuelCapacity(int capacity)  // This directly manipulate fuelCapacity
{
  fuelCapacity = capacity;
  return;
}

void Vehicle::setVehicleState(State state)
{
  vehicleState = state;
  return;
}

