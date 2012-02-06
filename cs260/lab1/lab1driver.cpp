// make NO CHANGES to this file, except to make it print out
// your actual name instead of "Your Name" on line 28

// this code enables Visual Studio's memory leak checking.
// Your code should not have memory leaks, and I will be
// testing your code for this in Visual Studio.  The #ifdef
// keeps this code from compiling in non-Windows environments.
// But if you use a non-Windows environment, you are still
// responsible for writing code with no memory leaks.
#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <iostream>

#include "winery.h"
#include "list.h"

using namespace std;

int main()
{
    list	*wineries = new list();
	winery	*wPtr;

    cout << "\nCS260 - Lab1 - Ladinu Chandrasinghe" << endl << endl;

	wineries->insert(winery("Lopez Island Vinyard", "San Juan Islands", 7, 95));
	wineries->insert(winery("Gallo", "Napa Valley", 200, 25));
	wineries->insert(winery("Cooper Mountain", "Willamette Valley", 100, 47));
	wineries->insert(winery("Duck Pond Cellars", "Willamette Valley", 845, 70));
	wineries->insert(winery("Del Rio", "Bear Creek Valley", 200, 37));
	wineries->insert(winery("Weisinger's of Ashland", "Bear Creek Valley", 6, 83));
	wineries->insert(winery("LongSword", "Applegate Valley", 16, 85));

	cout << "\n+++ list by name\n";
	wineries->displayByName(cout);
	cout << "\n+++ list by rating\n";
	wineries->displayByRating(cout);

	cout << "\n>>> removing Cooper Mountain\n";
	wineries->remove("Cooper Mountain");

	cout << "\n+++ list by name\n";
	wineries->displayByName(cout);
	cout << "\n+++ list by rating\n";
	wineries->displayByRating(cout);

	cout << "\n>>> inserting San Juan Vinyards\n";
	wineries->insert(winery("San Juan Vinyards", "San Juan Islands", 20, 90));

	cout << "\n+++ list by name\n";
	wineries->displayByName(cout);
	cout << "\n+++ list by rating\n";
	wineries->displayByRating(cout);

	cout << "\n>>> search for \"Gallo\"\n\n";
	wPtr = wineries->find("Gallo");
	if (wPtr != 0)
		cout << wPtr;
	else
		cout << "not found" << endl;

	cout << "\n>>> search for \"No Such\"\n\n";
	wPtr = wineries->find("No Such");
	if (wPtr != 0)
		cout << wPtr;
	else
		cout << "not found" << endl;

	cout << endl;
	delete wineries;

// in Visual Studio, reports on memory leaks in the Output window
#ifdef _WIN32
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
