//-----------------------------------------------------------------------
// Object: Solution for Task 9 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: PowerIncrease.cpp
// Summary: This program calculates the increase of power in 
// corresponding decibel (W to dB) 
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
void calculatePowerIncrease();

int main()
{
	char answer;
	do
	{
		calculatePowerIncrease();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void calculatePowerIncrease()
{
	int powerA;
	int powerB;

	cout << "POWER CALCULATIONS" << endl
		 << "================================" << endl;

	cout << "Load reference power: ";
	cin >> powerA;
	cout << "Load power          : ";
	cin >> powerB;

	cout << "================================" << endl;

	double decibel = 10 * log10(powerB / powerA);
	double levels = decibel / 3.0f;

	cout << fixed << setprecision(1);
	cout << "Change from reference power to current; " << powerA << " -> " << powerB
		 << " corresponds to power increase of " << decibel << " dB" << endl;
	cout << "Meaning an increase of " << levels << " levels, 3 dB each." << endl << endl;
}