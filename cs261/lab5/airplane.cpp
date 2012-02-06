#include "airplane.h"

  // Constructors
Airplane::Airplane()
  :Vehicle("default Airplane", 250)
{
  numberOfEngines = 1;
  engineType      = PROP;
  planeState      = ON_GROUND;
}

Airplane::Airplane(const char *name)
:Vehicle(name, 250)
{
    numberOfEngines = 1;
    engineType      = PROP;
    planeState      = ON_GROUND;
}

Airplane::Airplane(int fuel, int fuelUsage, const char * type, int engineNumbers, const char * name, const int passengerLimit)
  :Vehicle(fuel, fuelUsage, name, passengerLimit)
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

const char * Airplane::getName()
{
  return (Vehicle::getName());
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

bool Airplane::operator==(const Airplane *a) const
{
    if (this != a)
    {
        const Vehicle * v1 = a;
        const Vehicle * v2 = this;
        return ((*v1 == *v2)                    &&
                (engineType == a -> engineType) &&
                (planeState == a -> planeState) &&
                (numberOfEngines == a -> numberOfEngines));
    }
    else
        return true;
}

bool Airplane::operator==(const Airplane &a) const
{
    if (this != &a)
    {
        const Vehicle * v1 = &a;
        const Vehicle * v2 = this;
        return ((*v1 == *v2)                 &&
                (engineType == a.engineType) &&
                (planeState == a.planeState) &&
                (numberOfEngines == a.numberOfEngines));
    }
    else
        return true;
}

ostream& operator<<(ostream &out, const Airplane *a)
{
    const Vehicle * v = a;
    out << "<Airplane>" << endl << "{" << endl;
    out << "  ";
    out << *v << endl;
    
    out << "  airplane_state: ";
    if (a -> planeState == ON_AIR)
        out << "ON_AIR";
    else
        out << "ON_GROUND";
    out << endl;
    
    out << "  engine_type: ";
    if (a -> engineType == PROP)
        out << "PROP";
    else
        out << "JET";
    out << endl;
    
    out << "  engine_count: " << a -> numberOfEngines;
    out << "}" << endl;
    
    return out;
}

ostream& operator<<(ostream &out, const Airplane &a)
{
    const Vehicle * v = &a;
    out << "<Airplane>" << endl << "{" << endl;
    out << "  ";
    out << *v << endl;
    
    out << "  airplane_state: ";
    if (a.planeState == ON_AIR)
        out << "ON_AIR";
    else
        out << "ON_GROUND";
    out << endl;
    
    out << "  engine_type: ";
    if (a.engineType == PROP)
        out << "PROP";
    else
        out << "JET";
    out << endl;
    
    out << "  engine_count: " << a.numberOfEngines;
    out << "}" << endl;
    
    return out;
}


