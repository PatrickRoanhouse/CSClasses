#define _CRT_SECURE_NO_DEPRECATE	// stop deprecation warnings, needs to be on first line

#include "data.h"
#include <iostream>
#include <cstring>
#include <iomanip>

//#define STR_CAP 256

using namespace std;

data::data(char const * const nameInp) : name(0)
{
    copyStr(name, nameInp);
}

data& data::operator=(const data& data2)
{
    if (this != &data2)
        copyStr(name, data2.name);
    
    return *this;
}

data::~data()
{
    if (name)
        delete [] name;
    name = NULL;
}

char const * const data::getName() const
{
	return name;
}

void data::setName (char * nameInp)
{
    copyStr(name, nameInp);
    return;
}

bool operator< (const data& d1, const data& d2)
{
    return ( strcmp(d1.getName(), d2.getName()) < 0 );
}

bool operator> (const data& d1, const data& d2)
{
    return ( strcmp(d1.getName(), d2.getName()) > 0 );
}

bool operator== (const data& d1, const data& d2)
{
    return  ( strcmp(d1.getName(), d2.getName()) == 0 );
}

    // Search key comparison with data nodes
bool operator< (const char * key, const data &node)
{
    return (strcmp(key, node.getName()) < 0);
}

bool operator> (const char * key, const data &node)
{
    return (strcmp(key, node.getName()) > 0);
}

bool operator== (const char * key, const data &node)
{
    return (strcmp(key, node.getName()) == 0);
}

   // A safer way to copy strings (hopefully)
void data::copyStr (char *&dataMem, const char * const inputStr)
{
  if (inputStr) // Check inputStr is not null
  {
      int len = strlen(inputStr) + 1;

       //#TODO Make this am const
      if (len <= 256) {

        if (dataMem)
          delete [] dataMem;
        
        dataMem = new char [len];
        strcpy(dataMem, inputStr);

      }
  }

  else
  {
      if (dataMem)
        delete [] dataMem;
      dataMem = NULL;
  }

  return;
}


ostream& operator<< (ostream& out, const data& outData)
{
    out << outData.name;
	return out;
}
