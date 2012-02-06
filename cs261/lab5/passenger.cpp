#include "passenger.h"

Passenger::Passenger()
{
    passengerName = NULL;
}
Passenger::Passenger(const char * name, int weight)
{
    passengerName   = NULL;
    passengerWeight = weight;
    
        // Copy passenger name
    if (strlen(name)+1 <= STR_CAP)
    {
        passengerName = new char [strlen(name)+1];
        strcpy(passengerName, name);
    }
    else // name too long
        throw 10;
}

bool Passenger::operator==(const Passenger &p) const
{
    if (&p != this)
  
        return ((strcmp(p.passengerName, this -> passengerName) == 0)&&  (p.passengerWeight == this -> passengerWeight));
    else
        return true;
}

bool Passenger::operator==(const Passenger *p) const
{
    if (p != this)
        return ((strcmp(p -> passengerName, this -> passengerName) == 0) && (p -> passengerWeight == this -> passengerWeight));
    else
        return true;
}

Passenger& Passenger::operator=(const Passenger &r)
{
    if (this != &r)
    {
        this -> passengerWeight = r.passengerWeight;
        
        if (this -> passengerName)
            delete [] this -> passengerName;
        
        int len = static_cast<int>(strlen(r.passengerName)+1);
        
        passengerName = new char [len];
        strncpy(this -> passengerName, r.passengerName, len);
    }
    
    return *this;
}


Passenger::~Passenger()
{
    if (passengerName)
        delete [] passengerName;

    passengerName = NULL;
}