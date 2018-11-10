//-----------------------------------------------------------------------
// Object: Solution for Task 5 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: TemperatureConverter.cpp
// Summary: This program converts temperatures in Fahrenheit to Celsius
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-08:	Created by Martin	
//-----------------------------------------------------------------------

// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
const double FAHRENHEIT_TO_CELSIUS = (212 - 32) / 100.0f;

void estimateTravelTime();

int main()
{
	char answer;
	do
	{
		estimateTravelTime();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void estimateTravelTime() 
{
	double input;

	// Ask for input
	cout << "Input the temperature in Fahrenheit: ";
	cin >> input;

	// Do actual conversion
	double out = (input - 32) / FAHRENHEIT_TO_CELSIUS;

	// Print the result
	cout << fixed << setprecision(1);
	cout << "The temperature is " << out << " C" << endl;
}