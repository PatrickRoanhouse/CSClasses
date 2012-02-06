#include "vehicle.h"

Vehicle::Vehicle():passengerTree(UNLIMITED)
{
    fuelCapacity  = 0;
    fuelUsageRate = 10;
    vehicleState  = OFF;
    vehicleName   = NULL;
}

Vehicle::Vehicle(const char * name, const int passengerLimit):passengerTree(passengerLimit)
{
  fuelCapacity  = 0;
  fuelUsageRate = 10;
  vehicleState  = OFF;
    // Copy the name
  if (strlen(name)+1 <= 256)
  {
    vehicleName = new char [strlen(name)+1];
    strcpy(vehicleName, name);
  }
  else  // name is too long
    throw 10;
}

Vehicle::Vehicle(int fuelAmount, int usageRate, 
                 const char * name, const int limit):passengerTree(limit)
{
  fuelCapacity  = fuelAmount;
  fuelUsageRate = usageRate;
  vehicleState  = OFF;
    
    // Copy the name
  if (strlen(name)+1 <= 256)
  {
    vehicleName = new char [strlen(name)+1];
    strcpy(vehicleName, name);
  }
  else // name too long
    throw 10;
}

Vehicle::~Vehicle()
{
    if (vehicleName)
        delete [] vehicleName;
    vehicleName = NULL;
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

bool Vehicle::operator==(const Vehicle &v) const
{
  if (this != &v)
    return ((fuelUsageRate == v.fuelUsageRate)
            &&
            (fuelCapacity  == v.fuelCapacity)
            &&
            (vehicleState  == v.vehicleState)
            &&
            (strcmp(vehicleName, v.vehicleName) == 0)
            &&
            (passengerTree == v.passengerTree));
  else
    return true;
}

bool Vehicle::operator==(const Vehicle *v) const
{
  if (this != v)
    return ((fuelUsageRate == v -> fuelUsageRate)
            &&
            (fuelCapacity  == v -> fuelCapacity)
            &&
            (vehicleState  == v -> vehicleState)
            &&
            (strcmp(vehicleName, v -> vehicleName) == 0)
            &&
            (passengerTree == v -> passengerTree));
  else
    return true;
}

Vehicle& Vehicle::operator=(const Vehicle &v)
{
    if (this != &v)
    {
        fuelCapacity = v.fuelCapacity;
        fuelUsageRate = v.fuelUsageRate;
        vehicleState  = v.vehicleState;
        
    
        if (vehicleName)
            delete [] vehicleName;
        vehicleName = NULL;
        
        vehicleName = new char [257];
        strncpy(vehicleName, v.vehicleName, 257);
        
        passengerTree = v.passengerTree;
        
    }
    else
        return *this;
}

const char * Vehicle::getName() const
{
    return static_cast<const char *> (vehicleName);
}

void Vehicle::insertPassenger(const char * name, const int weight)
{
    if (vehicleState == OFF)
    {
        Passenger p(name, weight);
        if ( passengerTree.insert(name, p) )
            cout << "passenger '" << name << "' added" << endl;
        else
            cout << "[!] passenger limit has been reached" << endl;
    }
    else
        cout << "[!] cannot add passengers when vehicle is running" << endl;
    return;
}

void Vehicle::removePassenger(const char *name)
{
    if ( passengerTree.remove(name) )
        cout << "passenger '" << name << "' removed" << endl;
    else
        cout << "couldn't find passenger '" << name << "' to remove" << endl;
    
    return;
}

void Vehicle::listPassengers() const
{
    cout << "---- Passenger List ---- " << endl;
    passengerTree.print();
    return;
}

ostream& operator<<(ostream &out, const Vehicle &v)
{
    out << "<Vehicle>" << endl << "{" << endl
      << "  name: "        << v.vehicleName   << endl
      << "  fuel_rate: "   << v.fuelUsageRate << endl
      << "  fuel_amount: " << v.fuelCapacity  << endl
      << "  state: ";

  if (v.vehicleState == ON)
    out << "ON";
  else
    out << "OFF";
  out << endl;
    
  v.passengerTree.print();
  out << "}";

  return out;
}

ostream& operator<<(ostream &out, const Vehicle *v)
{
    out << "<Vehicle>" << endl << "{" << endl
    << "  name: "        << v -> vehicleName   << endl
    << "  fuel_rate: "   << v -> fuelUsageRate << endl
    << "  fuel_amount: " << v -> fuelCapacity  << endl
    << "  state: ";
    
    if (v -> vehicleState == ON)
        out << "ON";
    else
        out << "OFF";
    out << endl;
    
    v-> passengerTree.print();
    out << "}";
    
    return out;
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

