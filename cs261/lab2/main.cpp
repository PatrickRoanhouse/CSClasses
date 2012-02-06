#include "vehicle.h"
using namespace std;

int main()
{
  
 Vehicle v1;
 Vehicle v2(100,25);

 cout << "------ Testing vehicle 1 --------" << endl;
 v1.go();
 v1.turnon();
 v1.turnoff();
 v1.addFuel(20);
 v1.turnon();
 v1.go();
 v1.turnoff();
 v1.go();

 cout << endl << "------ Testing vehicle 2 --------" << endl;

 v2.turnon();
 v2.go();
 v2.go();
 v2.go();
 v2.go();
 v2.go();
 
 return 0;
}
