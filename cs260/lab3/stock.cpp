#include <string.h>
#include <iomanip>
#include "stock.h"
#include "hashmap.h"

#ifndef STRLEN
#define STRLEN 256
#endif

stock::stock(char const * const symbol, char const * const stockName, int sharePrice, date priceDate)
{
   tick        = NULL;
   name        = NULL;
   price       = 0;
   dateOfprice = date();

   copyStr(tick, symbol);
   copyStr(name, stockName);
   
   price       = sharePrice;
   dateOfprice = priceDate;
}

stock::stock(const stock& s)
{
   tick        = NULL;
   name        = NULL;
   dateOfprice = s.dateOfprice;
   price       = s.price;
   
   copyStr(name, s.name);
   copyStr(tick, s.tick);
}

stock& stock::operator=(const stock& s)
{
   if (this != &s)
   {
      dateOfprice = s.dateOfprice;
      copyStr(tick, s.tick);
      copyStr(name, s.name);
      price = s.price;
   }

	return *this;
}

stock& stock::operator=(stock const * const s)
{
   if (this != s)
   {
      dateOfprice = s-> dateOfprice;
      copyStr(tick, s -> tick);
      copyStr(name, s -> name);
      price = s-> price;
   }

	return *this;
}

stock::stock()
{
   tick        = NULL;
   name        = NULL;
   price       = 0;
   dateOfprice = date(date::INVALID, 0, 0);
}

char const * const stock::getSymbol(void) const
{
	return tick;
}

stock::~stock(void)
{
   if (tick)
     delete [] tick;
   if (name)
     delete [] name;

   name  = NULL;
   tick  = NULL;
}

  // A safer way to copy strings
void stock::copyStr(char *&dataMem, const char * const inputStr)
{
  int len = strlen(inputStr) + 1;

  if (len <= STRLEN) {

    if (dataMem)
      delete [] dataMem;
    
    dataMem = new char [len];
    strcpy(dataMem, inputStr);

  }

  return;
}

// #TODO:prints share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const stock& s)
{
   int dollars = s.price / 100;
   int cents   = s.price % 100;

   out << setfill(' ') << setbase(10) << left
       << setw(10) << s.tick
       << setw(35) << s.name
       << dollars  << ".";
   if ( (cents % 10) == cents)
       out << "0";
   out << setw(5)  << cents
       << s.dateOfprice << right;

	return out;
}
