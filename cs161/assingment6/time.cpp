#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


	// Range for valid hours
const int HOUR_MAX = 23;
const int HOUR_MIN = 0;

	// Range for valid minutes
const int MINUTE_MAX = 59;
const int MINUTE_MIN = 0;


int getInput(string timeMessure, int maxTime, int minTime) 
{
	int time;
	bool notInt, notInRange;
	bool invldTime = true;
	
		
	while(invldTime) {
			
		cout << "[?] Enter " << timeMessure << "(s): ";
			cin >> time;
			
			// This check for any invalid input by user
		notInt = ( cin.peek() != 10 );
		notInRange = ( (time < minTime) || (time > maxTime) ); 
			
		if (notInt || notInRange) {
			
			cout<< "[!] ERROR: Invalid " << timeMessure
				<<endl;
					
				//Clear input
			cin.clear();
			cin.ignore(100, '\n');
		}
		
		else {
			
			invldTime = false;
		}
	}
	
	return time;
}

	// Get start time in hours and minutes
void getTime(int& hour, int& minute)
{
	hour = getInput("hour", HOUR_MAX, HOUR_MIN);
	minute = getInput("minute", MINUTE_MAX, MINUTE_MIN);
}

	// This calculates the diffrence between start and end time
	// 		- returns time diffrence in minutes
	
int timeDiff(int startHour, int startMinute, int endHour, int endMinute ) {
	
	int diff;
	int startTime, endTime;
	
		// Covert hours to minutes and add minutes
	startTime = (startHour * 60) + startMinute;
	endTime = (endHour * 60) + endMinute;
	
		// Calculate the diffrence
	diff = (endTime - startTime);
	
	return diff;
}


void displayTime(int diff) {
	
	int hour, minute;
	
		// Convert diff (which is in minutes) =>
		// HH:MM format
	hour = (diff / 60);	// Should i cast this to a float and use floor() ?
	minute = (diff % 60);
	
		// Check for negative values
	if ( (hour < 0) || (minute < 0) ) {
		
		cout << "[!] ERROR: Woah! You went back in time!" << endl;
	}
	
	else {
		
		cout << "[-] The diffrence is: ";
		cout << setw(2) << setfill('0') << hour;
		cout << ":" << setw(2) << setfill('0') << minute 
		<< endl;
	}
	
}

int main()
{
	int startHour, startMinute;
	int endHour, endMinute;
	int diff;
	
	cout << "[-] Enter a start time..." << endl;
		getTime(startHour, startMinute);
	
	cout << "[-] Enter a stop time..." << endl;
		getTime(endHour, endMinute);
		
	diff = timeDiff( startHour, startMinute, 
					 endHour, endMinute );
					 
	
	displayTime(diff);
	
	return 0;
}
