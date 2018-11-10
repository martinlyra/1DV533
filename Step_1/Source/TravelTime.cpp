//-----------------------------------------------------------------------
// Object: Solution for Task 7 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: TravelTime.cpp
// Summary: This program calculates the time it takes to travel a given
// distance for given velocity
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
const int KILOMETRE_IN_A_MILE = 10;		// Nordic/Scandinavian mile, *not* Imperial mile
const int MINUTES_IN_A_HOUR = 60;

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
	double distance;
	double velocity;

	cout << "Specify distance to travel in mil: ";
	cin >> distance;
	cout << "Specify velocity in km/h: ";
	cin >> velocity;

	int time = distance / velocity * KILOMETRE_IN_A_MILE * MINUTES_IN_A_HOUR;

	int minutes = time % MINUTES_IN_A_HOUR;
	int hours = (time - minutes) / MINUTES_IN_A_HOUR;

	cout << "It'll take ";
	if (hours > 0)
		cout << hours << (hours == 1 ? " hour" : " hours") << " and ";
	cout << minutes << " minutes to travel the distance" << endl;
}