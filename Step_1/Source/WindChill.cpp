//-----------------------------------------------------------------------
// Object: Solution for Task 12 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: WindChill.cpp
// Summary: This program calculates the effective temperature for wind
// chill. Based on given parameters; temperature and wind velocity.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-09:	Created by Martin	
//-----------------------------------------------------------------------

// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Prototypes
void effectiveTemperature();

int main()
{
	char answer;
	do
	{
		effectiveTemperature();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void effectiveTemperature()
{
	double temperature;
	double windVelocity;

	cout << "Please enter the temperature: ";
	cin >> temperature;
	cout << "Please enter the wind velocity: ";
	cin >> windVelocity;

	double effective =
		13.12667f +
		0.6225f	* temperature -
		13.924748 * pow(windVelocity, 0.16f) +
		0.4875195 * temperature * pow(windVelocity, 0.16f);
	effective = round(effective);

	cout << "The effective tempereture for the wind chill is: " << effective << endl;
}