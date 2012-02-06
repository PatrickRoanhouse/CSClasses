#include "airplane.h"
#include "car.h"
#include "bst.h"
#include "list.h"
#include "passenger.h"
#include "magicschoolbus.h"
#include "xwing.h"
#include "fleet.h"
#include <iostream>
using namespace std;

int main()
{
    Car            car;
    Airplane       airplane;
    Xwing          xwing;
    Magicschoolbus bus;
    
    cout << "--- testing vehicle default names ---"    << endl
         << car.getName()      << endl
         << airplane.getName() << endl
         << xwing.getName()    << endl
         << bus.getName()      << endl << endl;

    Car            car1      ("Honda Civic");
    Airplane       airplane1 ("Airforce I");
    Xwing          xwing1    ("Red Leader");
    Magicschoolbus bus1      ("TATA Bus");
    
    cout << "--- testing vehicle names ---" << endl
         << car1.getName()      << endl
         << airplane1.getName() << endl
         << xwing1.getName()    << endl
         << bus1.getName()      << endl << endl;
    
    cout << "--- testing operator '<<' on vehicles ---" << endl
         << car1      << endl
         << airplane1 << endl
         << xwing1    << endl
         << bus1      << endl << endl;
    
    Car car2("car 2");
    
    Passenger p1("Elmo", 10), p2("Batman", 50), p3("Batman", 50);
    
    cout << endl << "--- testing passenger class ---" << endl
         << "p1 = ('Elmo', 10)"   << endl << "p2 = ('Batman', 50)" << endl
         << "p3 = ('Batman', 50)" << endl;
    
    if (p1 == p2)
        cout << "p1 == p2" << endl;
    else
        cout << "p1 != p2" << endl;
    
    if (p2 == p3)
        cout << "p2 == p3" << endl << endl;
    else
        cout << "p2 != p3" << endl;
    
    cout << "--- testing adding passengers to vehicle ---" << endl;
    car2.insertPassenger("John Doe", 50);
    car2.insertPassenger("John Doe", 45);
    car2.insertPassenger("Big bird", 40);
    car2.insertPassenger("Bat Man", 42);
    car2.insertPassenger("Cookie Monster", 10);
    car2.insertPassenger("Elmo", 31);
    cout << endl;
    
    car2.removePassenger("John Doe");
    car2.removePassenger("Big bird");
    cout << endl;
    
    cout << "=== car2 ===" << endl;
    car2.listPassengers();
    
    cout << endl << "--- testing operator '==' on vehicles ---" << endl
                 << "==== car1 ====" << endl << car1 << endl
                 << "==== car2 ====" << endl << car2 << endl;
    
    if (car1 == car2)
        cout << "*** car1 == car2" << endl;
    else
        cout << "*** car1 != car2" << endl << endl;
    
    Xwing xwing2("Red Leader");
    
    cout << "--- testing xwing methods ---" << endl;
    xwing2.fire();
    cout << "=== Adding passengers to Xwing === " << endl;

    xwing2.insertPassenger("pilot", 56);
    xwing2.insertPassenger("pilot2", 42);
    xwing2.insertPassenger("pilotg", 42);
    cout << endl;
    
    
    cout << "--- testing fleet class ---" << endl;
    
    Fleet fleet;
    Car car3;
    Magicschoolbus bus3("TATA Bus");
    
    cout << "==== Adding vehicles to fleet ====" << endl; 
    fleet.insert(car);
    fleet.insert(airplane);
    fleet.insert(xwing);
    fleet.insert(bus);
    
    fleet.insert(car1);
    fleet.insert(airplane1);
    fleet.insert(xwing1);
    fleet.insert(bus1);
    
    fleet.insert(xwing2);
    fleet.insert(bus3);
    fleet.insert(car3);
    
    cout << endl << "==== Find duplicate vehicles ==== " << endl;
    if (fleet.hasDuplicates())
        cout << "duplicates found " << endl;
    else
        cout << "no duplicates found" << endl;
    
    cout << endl << "=== fleet list ===" << endl;
    fleet.print();
    
    cout << endl << "==== Remove duplicates ==== " << endl;
    fleet.remove("TATA Bus");
    fleet.remove("default Car");
    fleet.remove("Red Leader");
    
    cout << endl << "=== fleet list ===" << endl;
    fleet.print();
    
    
    
    return 0;
}

