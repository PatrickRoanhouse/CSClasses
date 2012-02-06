#include <iostream>
#include <string>

using namespace std;

int printRect(int width, int height);
int getDimension(string dimension);

int main()
{
	int width, height;
	
	width = getDimension("width");
	height = getDimension("height");
	
	printRect(width, height);
	
	return 0;
}

	// This validate and returns a dimension entered by user
int getDimension(string dimension)
{
	int usr_inpt;
	bool bad_inpt = true;
	
	while (bad_inpt)
	{
		cout << "\n[?] Enter " << dimension << ": ";
			cin >> usr_inpt;
		

			// This checks for any invalid user input
		if ( ((usr_inpt <= 0) || (usr_inpt > 25)) || (cin.peek() != 10) )		// I noticed that cin.peek() returns diffrent values
		{																		// when diffrent data is entered into type int. For example,
			cout << "[!] ERROR: Invalid " << dimension << endl;					// entering intigers return 10 and entering a char	
			cin.clear();														// returns -1. Here I'm using return value of 10 to check for valid intiger.
			cin.ignore(100, '\n');												// Is there a better way to do this?
			
		}
			// The user provided valid input; escape from loop
		else
		{
			bad_inpt = false;
		}
		
		
	}
	 
	return usr_inpt;
}

	// Print a rectangle using given dimensions
int printRect(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "X";
		}
		
		cout << endl;
	}
	
	
	return 0;
}
