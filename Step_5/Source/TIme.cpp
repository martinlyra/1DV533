//-----------------------------------------------------------------------
// Object: Task 3 - Time
//-----------------------------------------------------------------------
// File: Time.cpp
// Summary: This program takes several numbers until a non-number is 
// given, then prints the output.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	Created by Martin	
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

// Constants
const int MAX_RANDOM_TIMES = 200;

const int HOURS_IN_A_DAY = 24;
const int MINUTES_IN_AN_HOUR = 60;

// Types
struct TimeType {
	int hour;
	int minute;
};

// Prototypes
int toMinutes(TimeType time);
TimeType toTime(int minutes);
TimeType timeDifference(TimeType timeA, TimeType timeB);
TimeType dynamicTimes();
void printTime(TimeType time);

// Entry point
int main() {
	cout << "Moment a) TimeType to minutes:\n";
	int minutes;
	TimeType timeA = { 10, 15 };
	minutes = toMinutes(timeA);
	cout << minutes << " minutes" << endl; // Should write: 615 minutes
	
	cout << "Moment b) Minutes to TimeType:\n";
	minutes = 124;
	TimeType time = toTime(minutes);
	printTime(time);
	cout << '\n';

	cout << "Moment c) Time difference:\n";
	TimeType timeB = { 10, 30 }, timeC = { 13, 20 }, difference;
	difference = timeDifference(timeB, timeC);
	printTime(difference);
	cout << '\n';

	cout << "Moment d) Largest difference in 200 random time values:\n";
	TimeType maxDiff = dynamicTimes();
	printTime(maxDiff);
	cout << '\n';

	cout << "Press any key to continue...\n";
	cin.get();
	return 0;
}

// int toMinutes(TimeType)
//
// Returns the total minutes of given time
int toMinutes(TimeType time)
{
	return time.hour * MINUTES_IN_AN_HOUR + time.minute;
}

// TimeType toTime(int)
//
// Computes the time given from total minutes
TimeType toTime(int minutes)
{
	return { minutes / MINUTES_IN_AN_HOUR, minutes % MINUTES_IN_AN_HOUR };
}

// TimeType timeDifference(TimeType, TimeType)
//
// Computes the difference between the two given times, also in form of time
TimeType timeDifference(TimeType timeA, TimeType timeB)
{
	return toTime(abs(toMinutes(timeA) - toMinutes(timeB)));
}

// TimeType dynamicTimes()
//
// Randomizes 200 time values, then picks the largest difference based on lowest and highest values
TimeType dynamicTimes()
{
	vector<int> v;
	v.reserve(MAX_RANDOM_TIMES);

	srand(time(NULL));

	int lowest = -1, highest = -1;
	for (int c = 0; c < MAX_RANDOM_TIMES; c++) {
		int i = rand() % (HOURS_IN_A_DAY * MINUTES_IN_AN_HOUR);
		v.push_back(i);

		if (lowest == -1 || i < lowest)
			lowest = i;
		if (highest == -1 || i > highest)
			highest = i;
	}

	v.clear();

	return toTime(highest - lowest);
}

// void printTime(TimeType)
//
// Outputs given time in the HH:MM format
void printTime(TimeType time)
{
	cout << setfill('0');
	cout << setw(2) << time.hour << ':';
	cout << setw(2) << time.minute;
}
