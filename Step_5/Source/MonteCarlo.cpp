//-----------------------------------------------------------------------
// Object: Task 6 - Monte Carlo's Pi method for determination of Pi
//-----------------------------------------------------------------------
// File: MonteCarlo.cpp
// Summary: This program takes several numbers until a non-number is 
// given, then prints the output.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	Created by Martin	
//-----------------------------------------------------------------------
// Required for M_PI
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
using namespace std;

// Constants
const double RADIUS = 100;
const int TEST_CASE_START = 100;
const int TEST_CASE_END = 10000;
const int TEST_CASE_STEP = 100;

// Types
struct Position {
	double x, y;
};

// Prototypes
bool below(Position, double);
Position throwDart(double);		// renamed throwDart to not confuse with the keyword 'throw'
void throwSeries(double);

// Entry point
int main() {
	srand(time(NULL));

	// Table header
	cout << setw(6) << "num" << ' ' << setw(10) << "pi" << ' ' << "accurancy" << '\n';
	cout << setfill('_');
	cout << setw(7) << '|' << setw(11) << '|' << setw(9) << '\n';
	cout << setfill(' ');

	// Start determining the PI with Monte Carlo's method.
	for (int i = TEST_CASE_START; i <= TEST_CASE_END; i += TEST_CASE_STEP)
		throwSeries(i);

	// End
	cout << "Press any key to continue...\n";
	cin.get();
	return 0;
}

// bool below(Position, double)
//
// Returns true if the absolute of Position (as vector) is smaller than the distance
bool below(Position position, double maxDistance)
{
	return (pow(position.x, 2) + pow(position.y, 2)) < pow(maxDistance, 2);
}

// Position throwDart(double)
//
// Returns a random position (of a thrown dart), values range from 0 to 'max'
Position throwDart(double max)
{
	return { double(rand() % int(max)), double(rand() % int(max)) };
}

// void throwSeries(double)
//
// Throws n number of darts then determines the pi based on Monte Carlo's method
void throwSeries(double n)
{
	double withinCount = 0;
	for (int i = 0; i < n; i++)
		if (below(throwDart(RADIUS), RADIUS))
			withinCount++;

	double determinedPi = withinCount / n * 4;
	double accurancy = (determinedPi - M_PI) / M_PI * 100;

	cout << setw(6) << setprecision(0)<< n << '|';
	cout << setw(10) << setprecision(5) << fixed << determinedPi << '|';
	cout << setw(7) << setprecision(3) << accurancy << '%' << endl;
}