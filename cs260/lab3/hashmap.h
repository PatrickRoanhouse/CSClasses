#pragma once

#include "stock.h"

enum BucketState {EMPTY, OCCUPIED};

class hashmap
{
public:
	hashmap(int capacity);
	~hashmap(void);

	// gets the stock associated with the provided stock symbol from the hashmap,
	// returns true if successful, false if not
	bool get(char const * const symbol, stock& s) const;

	// adds the stock to the hashmap, returns true if successful,
	// false if not (if the symbol is already present as a key or
	// if the hash table was already full).
	// Additional data returned:
	//		usedIndex:	array index where the stock will actually be stored
	//		hashIndex:	array index produced by applying the modulo operator
	//						to the hash value produced by hashStr()
	//		symbolHash:	result of applying hashStr() to stock symbol
	bool put(const stock& s, int& usedIndex, int& hashIndex, int& symbolHash);

	// removes the stock associated with the provided symbol from the hashmap,
	// returns true if successful, false if not (if the symbol is not present as a key)
	bool remove(char const * const symbol);

	friend ostream& operator<<(ostream& out, const hashmap& h);

private:
	static int hashStr(char const * const symbol);	// string hashing function

   struct bucket
   {
      bucket();      // Default constructor
      ~bucket();
      void clear(); // Delete bucket content

      BucketState state;
      stock *     data;
   };

   bucket * bucketLst;  // The hash table
   int   lstLen;
   int   itemsInLst;

};
