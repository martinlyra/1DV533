//-----------------------------------------------------------------------
// Object: Task 08: Functions based on dates
//-----------------------------------------------------------------------
// File: DateFunction.cpp
// Summary:	Takes an input date in form of single integer then finds
// the next date from that day.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-17	Created
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototypes
bool leapYear(int year);
int daysInMonth(int year, int month);
int tomorrow(int date);

// Entry point
int main()
{
	cout << "Date functions" << endl;

	char answer;
	do {
		int input;

		cout << "======" << endl << endl;

		cout << "Please enter the current date: ";
		
		cin >> input;

		cout << "The date tomorrow is: " << tomorrow(input) << endl;

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (tolower(answer == 'y'));

	return 0;
}

// bool leapYear(int)
//
// Returns true if the given year is a leap year
bool leapYear(int year)
{
	if (year % 4)
		return false;

	if (year % 100 || year % 400)
		return false;

	return true;
}

// int daysInMonth(int, int)
//
// Returns the amount of days in the given month of selected year
int daysInMonth(int year, int month)
{
	switch (month) {
	case 1: return 31;	// January  Januari
	case 2: {			// Feburary	Feburari
		return leapYear(year) ? 29 : 28;
	}
	case 3: return 30;	// March	Mars
	case 4: return 31;	// April
	case 5: return 31;	// May		Maj
	case 6: return 30;	// June		Juni
	case 7: return 31;	// July		Juli
	case 8: return 31;	// August	Augusti
	case 9: return 30;	// September
	case 10: return 31;	// Oktober
	case 11: return 30;	// November
	case 12: return 31; // December

	default: return -1;	// INVAILD / UNKNOWN
	}
}

// int tomorrow(int)
//
// Finds the next day after the given date
int tomorrow(int date)
{
	int day = date % 100;
	int month = (date / 100) % 100;
	int year = date / 10000;

	int days = daysInMonth(year, month);

	day++;

	if (day > days) {
		day = 1;
		month++;

		if (month > 12) {
			month = 1;
			year++;
		}
	}

	return year * 10000 + month * 100 + day;
}

