#include "airplane.h"

  // Constructors
Airplane::Airplane()
  :Vehicle()
{
  numberOfEngines = 1;
  engineType      = PROP;
  planeState      = ON_GROUND;
}

Airplane::Airplane(int fuel, int fuelUsage, const char * type, int engineNumbers)
  :Vehicle(fuel, fuelUsage)
{
    // Set the engine type based on input
  if (strcmp("jet", type) == 0)
    engineType = JET;

  else if (strcmp("prop", type) == 0)
    engineType = PROP;
  
  else
      //#TODO: Handle exception
    engineType = PROP;
  
  planeState      = ON_GROUND;
  numberOfEngines = engineNumbers;
}

  // Methods
void Airplane::takeoff()
{
  if (getVehicleState() == ON)
  {
    int fuelUsageOnTakeoff;
    int vehicleFuelUsageRate;
    int vehicleFuelCapacity;

    vehicleFuelCapacity  = getFueCapacity();
    vehicleFuelUsageRate = getFuelUsageRate();
    fuelUsageOnTakeoff   = (vehicleFuelUsageRate*10); // take off require more fuel

      // Check to see if the current amount of fuel can support takeoff
    if ((vehicleFuelCapacity - fuelUsageOnTakeoff) <= 0)
      cout << "Not enough fuel to start the plane" << endl;
    else
    {
      setFuelCapacity(vehicleFuelCapacity - fuelUsageOnTakeoff);
      planeState = ON_AIR;
      cout << "We are in the air..." << endl;
    }
  }

  else
    cout << "The airplane isn't running so you can't take off" << endl;

  return;
}

void Airplane::land()
{
  if (planeState == ON_AIR)
  {
    planeState = ON_GROUND;
    cout << "The plane has landed" << endl;
  }
  else
    cout << "plane is already on the ground" << endl;

  return;
}

void Airplane::go()
{
  if (getVehicleState() == ON)
  {
      // when the plane is in the air
    if (planeState == ON_AIR)
    {
      int vehicleFuelCapacity  = getFueCapacity();
      int vehicleFuelUsageRate = getFuelUsageRate();

      if (vehicleFuelCapacity > 0)
      {
        setFuelCapacity(vehicleFuelCapacity - vehicleFuelUsageRate);
        cout << "going..." << endl;
       }
       
       if (getFueCapacity()<= 0)
       {
         cout << "out of fuel" << endl;
         setFuelCapacity(0); //set fuelCapacity to 0 because it could be negative
         setVehicleState(OFF);
         cout << "*** CRASH ***" << endl;
         planeState = ON_GROUND;
       }
     }

      // when the plane is on the ground
    else
       cout << "Not in the air" << endl;
   }
    // when plane is off
   else
      cout << "the vehicle has not been turned on" << endl;

    return;
}


void Airplane::turnoff()
{
  Vehicle::turnoff();

  if (planeState == ON_AIR) // Plane should crash if turned off during flight
  {
    cout << "*** CRASH ***" << endl;
    planeState = ON_GROUND; // When plane crashed it should be on ground
  }
}


