//-----------------------------------------------------------------------
// Object: This program has some syntax errors. Use the compiler to find
// and correct them. Document your changes with comments or in log.
//-----------------------------------------------------------------------
// File: CompileError.cpp
// Summary: This program calculates the weekly pay, given hours per week
// and wages per hour.
// Version: 1.1
// Owner: Tommy Löfqvist
//---------------------------------------------------------------------
// Log:			2005-03-09	Created the file, Mats!
//				2009-08-14	Revised by Tommy.Using manipulators to format output
//							instead of IO-flags. Inserted "wait for return code" at the end.
//				2012-10-21:	Revised by Anne. Converted to English version and VS2012
//				2018-11-08: Solved by Martin. Marked with # in comments.
//-----------------------------------------------------------------------
#include <iostream> // Preprocessor directives
#include <iomanip>
using namespace std;

int main()	// # Return type was void, changed to int, otherwise it would return nothing.
{
	// Define and initialize variables
	int hoursPerWeek = 35;
	double hourlyWages = 83;

	// Calculate weekly salary
	double weeklyWages = hoursPerWeek * hourlyWages;		// # Type was missing

	// Display results
	cout << fixed // Floating point format
		<< setprecision(2) // 2 decimals
		<< showpoint; // Show trailing zero’es

	cout << " Given an hourly wage of " << hourlyWages << " kr" << endl
		<< " and the number of hours per week " << hoursPerWeek << endl
		<< "the weekly wages will be: " << weeklyWages << " kr" << endl;	// # Missing semicolon (statement terminator)
		cout << "\nPress return!";
	cin.get(); // Wait for return
	return 0;
}