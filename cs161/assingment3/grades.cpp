#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

	// This is a simple grade calculator

int main ()
{
	int sum, exam1, exam2, exam3, exam4, exam5;
	double average, finalScore;
	bool error = false;

	char letterGrade;
	string firstName, lastName;

		// Prompt user for information
		// Sample input: Joe 
		// 				 Smith
		// 				 78 88 90 89 92
	
	cout << endl << "[?] Enter student's first name: ";		// First name
		getline(cin, firstName);
	
	cout << "[?] Enter " << firstName << "'s last name: ";		// Last name
		getline(cin, lastName);
	
	
	cout << "[?] Enter " << firstName << "'s scores from exam 1 - 5: ";		// Exam scores
		cin >> exam1 >> exam2 
			>> exam3 >> exam4
			>> exam5;


		// Final grade calculation
	
	sum = ( exam1 + exam2 +
			exam3 + exam4 + 
			exam5 );

	average = ( (static_cast<double>(sum)) / 500.0 );
	finalScore = ( average * 100.0 );


		// Assign letter grade based on finalScore
	
	if ( finalScore < 0.0 )		// No one deserve a negative score
		error = true;

	if ( finalScore < 60.0 )
		letterGrade = 'F';
	
	else if ( finalScore < 70.0 )
		letterGrade = 'D';

	else if ( finalScore < 80.0 )
		letterGrade = 'C';

	else if ( finalScore < 90.0 )
		letterGrade = 'B';

	else if ( finalScore <= 100.0 )		// No one get extra credit
		letterGrade = 'A';

	else {
		error = true;
	}
		
	
		// Show grade if no errors
	
	if ( (error == true) ) {
		cout << endl << "[!] ERROR: Please check your input!"
		<< endl;
	}

	else {
		
		cout << endl << lastName << ", " << firstName << "\t" << letterGrade 
			 << " (" << sum << "/500 = " << fixed << setprecision(1) << finalScore << "%)" 
			 << endl;
		
	}
	
	return 0;
	
}
