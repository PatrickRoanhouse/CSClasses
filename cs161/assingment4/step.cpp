#include <iostream>

using namespace std;

int main()
{
	int startNum, endNum, stepNum;
	
	cout << "\n[+] Enter starting, ending, and step number: ";
			cin >> startNum >> endNum >> stepNum;
	
		// This expression check for any value that is NOT the following:
		// 			
		// 			- starting num is greater than or eqal to 0
		// 			- starting num is less than ending number
		// 			- and step number is greater than 0
		//
		// Basically this check for values that are invalid
		
	while (!( ((startNum >= 0) && (startNum < endNum)) && stepNum > 0 ))
	{
		cout << "[-] Sorry, enter values again: ";
			cin >> startNum >> endNum >> stepNum;
		
	}
	
	

		// This print starting num and increment by steping num
	
	while (startNum <= endNum)
	{
		cout << startNum << endl;
		
		startNum += stepNum;
	}
	
	
		

	return 0;

}
