#include <iostream>
#include <iomanip>

using namespace std;

// Interactive Body Masss Index (BMI) calculator
int main() {

	double weight, height;
	double bmi;

	cout << "Welcome to the BMI calculator" << endl;
	cout << "Enter your weight in pounds:\t";

	cin >> weight;
	
	cout << "Enter your height in inches:\t";
	
	cin >> height;

	
	// BMI calculation: BMI = (Weight / Height^2) * 703
	bmi = (weight / (height * height)) * 703;


	cout << fixed << setprecision(1)
	     << "Your BMI is " << bmi << endl;


	return 0;
}

