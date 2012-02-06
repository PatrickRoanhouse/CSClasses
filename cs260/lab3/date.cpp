#include "date.h"
using namespace std;

date::date(Month monthInp, int dayInp, int yearInp)
{
   month  = monthInp;
   day    = dayInp;
   year   = yearInp;
}

date::date(const date& d)
{
   month  = d.month;
   day    = d.day;
   year   = d.year;
}

date::date()
{
   month  = INVALID;
   day    = 0;
   year   = 0;
}

date::~date(void)
{
}

date& date::operator=(const date& d)
{
   if (this != &d)
   {
      month = d.month;
      year  = d.year;
      day   = d.day;
   }

	return *this;
}

ostream& operator<<(ostream& out, const date& d)
{
   switch (d.month)
   {
     case date::JANUARY:
         out << "January ";
         break;
     case date::FEBRUARY:
         out << "February ";
         break;
     case date::MARCH:
         out << "March ";
         break;
     case date::APRIL:
         out << "April ";
         break;
     case date::MAY:
         out << "May ";
         break;
     case date::JUNE:
         out << "June ";
         break;
     case date::JULY:
         out << "July ";
         break;
     case date::AUGUST:
         out << "August ";
         break;
     case date::SEPTEMBER:
         out << "September ";
         break;
     case date::OCTOBER:
         out << "October ";
         break;
     case date::NOVEMBER:
         out << "November ";
         break;
     case date::DECEMBER:
         out << "December ";
         break;
     case date::INVALID:
         out << "Invalid ";
         break;

       default:
         out << "Error ";
   }
   
   out << d.day << ", " << d.year;
	return out;
}
