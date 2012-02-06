#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>
#include "bst.h"
#include "passenger.h"

using namespace std;

typedef enum {ON, OFF} State;

class Vehicle
{
  public:
      // Constructors
    Vehicle();
    Vehicle(const char *name, const int passengerLimit=UNLIMITED);
    Vehicle(int fuelAmount, int fuelUsageRate, 
            const char * name, const int passengerCap = UNLIMITED);
    ~Vehicle();

      // Methods
    void turnon();
    void turnoff();
    void go();
    void addFuel(int fuelAmount);
    const char * getName() const;
    
    void insertPassenger(const char *name, const int weight);
    void removePassenger(const char *name);
    void listPassengers() const;
    
    bool operator==(const Vehicle &v) const;
    bool operator==(const Vehicle *v) const;
    Vehicle& operator=(const Vehicle &v);

    

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
    char * vehicleName;
    
    BST<Passenger> passengerTree;
    


    friend ostream& operator<<(ostream &out, const Vehicle &v);
    friend ostream& operator<<(ostream &out, const Vehicle *v);

};

#endif
