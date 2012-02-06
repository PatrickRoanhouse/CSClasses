#ifndef PASSENGER_H
#define PASSENGER_H

#ifndef STR_CAP
#define STR_CAP 256
#endif

#include <cstring>
#include <stdio.h>

class Passenger
{
  public:
    Passenger(const char *name, int weight);
    Passenger();
    ~Passenger();
    
    bool operator==(const Passenger *p) const;
    bool operator==(const Passenger &p) const;
    Passenger& operator=(const Passenger &r);
    
  private:
    int    passengerWeight;
    char * passengerName;
};
#endif
