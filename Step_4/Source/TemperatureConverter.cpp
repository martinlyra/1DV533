//-----------------------------------------------------------------------
// Object: Solution for Task 2 of 4th Assingment for 1DV533
//-----------------------------------------------------------------------
// File: TemperatureConverter.cpp
// Summary: This program converts temperatures in Fahrenheit to Celsius
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-08:	Created by Martin	
//    			2018-12-16: Original solution edited for 4th assign
//-----------------------------------------------------------------------

// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
const double FAHRENHEIT_TO_CELSIUS = (212 - 32) / 100.0f;

bool convertTemperature(double fahrenheit, double& celcius);

// Entry point
int main()
{
	char answer;
	do
	{
		double input;
		double out;

		// Ask for input
		cout << "Input the temperature in Fahrenheit: ";
		cin >> input;

		// Do actual conversion
		convertTemperature(input, &out);

		// Print the result
		cout << fixed << setprecision(1);
		cout << "The temperature is " << out << " C" << endl;

		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

// bool convertTemperature(double, double&)
//
// Converts to Celcius from Fahrenheit via parameter. Returns true if the temperature is equal to or warmer than 0 C
bool convertTemperature(double fahrenheit, double& celcius) 
{
	celcius = (fahrenheit - 32) / FAHRENHEIT_TO_CELSIUS;

	return celcius >= 0;
}