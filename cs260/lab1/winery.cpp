#include "winery.h"
#include <iostream>
#include <iomanip>
using namespace std;

using namespace std;

winery::winery()
{
  name = NULL;
  location = NULL;
  acres = 0;
  rating = 0;
}

winery::winery(const char * const inputName, const char * const inputLocation, const int inputAcres, const int inputRating)
{
	// your code here, or in this constructor's initialization list
  name = NULL;
  location = NULL;
  acres = 0;
  rating = 0;


  copyStr(name, inputName);
  copyStr(location, inputLocation);
  acres = inputAcres;
  rating = inputRating;
}

winery::~winery()
{
	// your code here
   if (name)
     delete [] name;
   name = NULL;

   if (location)
     delete [] location;
   location = NULL;
}

const char * const winery::getName() const
{
	return name;
}

const char * const winery::getLocation() const
{
	return location;
}

const int winery::getAcres() const
{
	return acres;
}

const int winery::getRating() const
{
	return rating;
}

void winery::copy(const winery &awinery)
{
   copyStr(name, awinery.name);
   copyStr(location, awinery.location);

   acres = awinery.acres;
   rating = awinery.rating;

   return;
}

void winery::displayHeadings(ostream& out)
{
  out << setw(25) << left << "name"
      << setw(20) << "location"
      << setw(10) << "acres"
                  << "rating"
      << endl 
      << setw(25) << left << "----"     
      << setw(20) << "--------" 
      << setw(10) << "-----"    
                  << "------"   
      << endl;

  return;
}

   // A safer way to copy strings
void winery::copyStr (char *&dataMem, const char * const inputStr)
{
  int len = strlen(inputStr) + 1;

   //#TODO Make this am const
  if (len <= 256) {

    if (dataMem)
      delete [] dataMem;
    
    dataMem = new char [len];
    strcpy(dataMem, inputStr);

  }

  return;
}

ostream& operator<<(ostream& out, winery *w)
{
   out << setw(25) << left <<    w-> name;
   out << setw(20) <<            w-> location;
   out << setw(10) <<            w-> acres;     
   out <<                        w-> rating;

	return out;
}
