#include <string.h>
#include <iomanip>
#include "hashmap.h"

hashmap::bucket::bucket()
{
   state = EMPTY;
   data  =  NULL;
}

hashmap::bucket::~bucket()
{
   if (data)
     delete data;

   data = NULL;
}

   // Set state to deleted, and remove data
void hashmap::bucket::clear()
{
   state = EMPTY;
   if (data)
     delete data;
   data = NULL;
}

hashmap::hashmap(int capacity)
{
   lstLen     = capacity;
   itemsInLst = 0;
   bucketLst  = new bucket [capacity];
}

hashmap::~hashmap(void)
{
   if (bucketLst)
     delete [] bucketLst;
}

bool hashmap::get(char const * const symbol, stock& s) const
{
   bool indexFound = false;
   int index = hashStr(symbol) % lstLen;

   if (itemsInLst != 0)
   {
      int indexLookedup = 1;
      while((!indexFound) && (indexLookedup <= lstLen))
      {
         if ( (bucketLst[index].state == OCCUPIED ) && 
           (strcmp(bucketLst[index].data -> tick, symbol) == 0))
         {
            indexFound = true;
            s = bucketLst[index].data;
         }

         else
         {
            index = (index + 1) % lstLen;
            ++indexLookedup;
         }
      }
   }
	return indexFound;
}

bool hashmap::put(const stock& s, int& usedIndex, int& hashIndex, int& symbolHash)
{
   bool indexFound = false;
   bool ret        = false;
   
      // If there is room in list, continue
   if (itemsInLst != lstLen)
   {
     int index;

     symbolHash = hashStr(s.tick);
     index      = symbolHash % lstLen;
     hashIndex  = index;

     while (!indexFound)
      {
            // Check if stock is already in list
         if ( (bucketLst[index].state == OCCUPIED) &&
              (strcmp(bucketLst[index].data -> tick, s.tick) == 0))
         {
            indexFound = true;
            ret        = false;
         }

         else if (bucketLst[index].state == EMPTY)
         {
            bucketLst[index].state = OCCUPIED;
            bucketLst[index].data  = new stock(s);

            indexFound = true;
            ret        = true;
            usedIndex  = index;
            ++itemsInLst;
         }
           // Linear probing to find non occupied index
         index = (index + 1) % lstLen;         
      }
   }  

   return ret;
}

bool hashmap::remove(char const * const symbol)
{
   int index  = hashStr(symbol) % lstLen;
   bool found = false;

   if (itemsInLst != 0)
   {
      int indexLookedup = 1;
      while ( (!found) && (indexLookedup <= lstLen) )
      {
         if ( (bucketLst[index].state == OCCUPIED) && 
             (strcmp(bucketLst[index].data -> tick, symbol) == 0))
         {
            bucketLst[index].clear();
            --itemsInLst;
            found = true;
         }

         else
         {
            index = (index + 1) % lstLen;
            ++indexLookedup;
         }
      }
   }

	return found;
}

int hashmap::hashStr(char const * const str)
{
	// Hash string according to the formula in java.lang.String.hashCode():
	//
	//   s[0]*(31^(n-1)) + s[1]*(31^(n-2)) + ... + s[n-1]
	//
	// s is the array of characters, n is the number of characters in the string,
	// and 31^n means 31 to the nth power.
	//
	// This function is declared static because its result depends
	// only on the characters in the string. You will need to apply
	// the modulo operator to the result of this function to generate
	// the required table index. The place to do this is in the functions
	// that call this function.
	//
	// You can and should do this computation entirely with integers. In other
	// words, there is no need to use floating point values. In particular, you
	// should not use the pow() function from <math.h> in this lab.
   
   int hash = 0;
   int i;
   int strLen = strlen(str);

   for (i = 0; i < strLen; ++i) 
   {
      hash = 31*hash + str[i];
   }
   
	return hash;
}

ostream& operator<<(ostream& out, const hashmap& h)
{

 out << setfill(' ') << left
     << setw(10) << "symbol"
     << setw(35) << "name"
     << setw(8) << "price"
     << "date" << endl;

 out << setw(10) << "------"
     << setw(35) << "----"
     << setw(8) << "-----"
     << "----" << endl;

   for (int i = 0; i < h.lstLen; i++) 
   {
      if (h.bucketLst[i].state == OCCUPIED)
         out << *h.bucketLst[i].data << endl;
   }

   out << endl;

	return out;
}
