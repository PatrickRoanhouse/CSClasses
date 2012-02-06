// do not change anything in this file except to make it print out
// your own name instead of "Your Name"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <iostream>
#include <iomanip>
#include "hashmap.h"

using namespace std;

hashmap		hm(11);

static void searchStock(char *symbol)
{
	stock		s;

	cout << ">>> searching for " << symbol << endl;
	if (hm.get(symbol, s))
		cout << s;
	else
		cout << "not found\n";
	cout << endl;
}

static void addStock(const stock& s)
{
	int		hashIndex, usedIndex, symbolHash;

	if (hm.put(s, usedIndex, hashIndex, symbolHash))
		cout << ">>> added "
			 << left << setw(6) << setfill(' ') << s.getSymbol()
			 << right
			 << " at index "	<< setw(2) << usedIndex
			 << ", hash index "	<< setw(2) << hashIndex
			 << ", hash code 0x" << hex << uppercase << setw(8) << setfill('0') << symbolHash
			 << endl;
	else
		cout << ">>> could not add " << s.getSymbol() << endl;
}

static void removeStock(char *symbol)
{
	cout << ">>> removing " << symbol << endl;
	cout << symbol;
	if (hm.remove(symbol))
		cout << " removed\n";
	else
		cout << " not removed!\n";
	cout << endl;
}

int main(void)
{
#ifdef _WIN32
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	cout << "CS260 - Lab3 - Your Name\n\n";

	searchStock("IBM");
	addStock(stock("IBM", "International Business Machines", 2573, date(date::MAY, 23, 1967)));
	cout << endl;
	cout << hm << endl;
	searchStock("IBM");
	removeStock("IBM");
	searchStock("IBM");
	removeStock("IBM");
	addStock(stock("MLT", "MLT Software, Inc.", 800, date(date::APRIL, 18, 1988)));
	addStock(stock("IBM", "International Business Machines", 2573, date(date::MAY, 23, 1967)));
	addStock(stock("XRX", "Xerox", 1892, date(date::JUNE, 1, 1980)));
	addStock(stock("LMT", "Lockheed Martin", 8951, date(date::OCTOBER, 24, 2006)));
	addStock(stock("US:BA", "Boeing", 6407, date(date::DECEMBER, 14, 1993)));
	addStock(stock("GD", "General Dynamics", 7281, date(date::OCTOBER, 24, 2006)));
	addStock(stock("AAPL", "Apple Computer, Inc.", 2308, date(date::MAY, 1, 1980)));
	addStock(stock("AAPL", "Apple Computer, Inc.", 2308, date(date::MAY, 1, 1980)));
	addStock(stock("MSFT", "Microsoft Corporation", 2843, date(date::JANUARY, 23, 1995)));
	addStock(stock("GE", "General Electric", 1948, date(date::MARCH, 22, 1987)));
	cout << endl;
	cout << hm << endl;
	searchStock("GE");
	removeStock("IBM");
	searchStock("GE");
	removeStock("US:BA");
	searchStock("GE");
	removeStock("GE");
	cout << hm << endl;

	return 0;
}
