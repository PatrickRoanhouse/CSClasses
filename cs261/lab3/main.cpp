#include "airplane.h"
#include "car.h"

using namespace std;

int main()
{
 Airplane a1;
 Airplane a2(100,25,"jet",4);
 Car c1;

 cout << "------ Testing airplane 1 --------" << endl;
 a1.addFuel(1000);
 a1.turnon();
 a1.takeoff();
 a1.go();
 a1.go();
 a1.go();
 a1.land();
 a1.turnoff();

 cout << "------ Testing airplane 2 --------" << endl;
 a2.takeoff(); // should fail cause we're not started
 a2.turnon(); 
 a2.takeoff(); // should fail cause we don't have enough fuel
 a2.turnoff();
 a2.addFuel(210); 
 a2.turnon(); 
 a2.takeoff(); // should use 250 fuel (60 left)
 a2.turnoff(); // should crash
 a2.addFuel(250); 
 a2.turnon(); 
 a2.takeoff(); // should use 250 fuel (60 left)
 a2.go();
 a2.go();
 a2.go(); // should crash -- out of fuel


 cout << "------ Testing car --------" << endl;
 c1.addFuel(100);
 c1.go(); // can't go -- in park
 c1.gear();
 c1.go();
 c1.go();
 c1.turnoff(); // can't turn off when not in park
 c1.park();
 c1.turnoff();

 return 0;
}
