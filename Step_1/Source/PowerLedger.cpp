//-----------------------------------------------------------------------
// Object: Solution for Task 6 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: PowerLedger.cpp
// Summary: This program calculates monthly cost based on power
// consumption and a fixed price for the electricity.
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
const double COST_PER_KILOWATT = 0.9493f;	// In integer SEK, no cents ('öre')
const double FIXED_COST = 320 / 12.0f;			// Fixed yearly cost divided to a single monthly cost

void calculateCost();

int main()
{
	char answer;
	do
	{
		calculateCost();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void calculateCost()
{
	int previousConsumption;
	int currentConsumption;
	
	cout << "Previous power meter reading (kWh): ";
	cin >> previousConsumption;
	cout << "Current power meter reading (kWh): ";
	cin >> currentConsumption;

	int delta = currentConsumption - previousConsumption;
	double cost = FIXED_COST + delta * COST_PER_KILOWATT;

	cout << "The total cost for power consumption this month is " << cost << " SEK" << endl;
}