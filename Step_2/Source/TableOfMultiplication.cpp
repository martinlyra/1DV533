//-----------------------------------------------------------------------
// Object: Task 04: Print a multiplication table 
//-----------------------------------------------------------------------
// File: TableOfMultiplication.cpp
// Summary: This program prints a table showing multiplication of n with
// 10, 100, and 1000.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
const int NUMBER_RANGE_MIN = 1;
const int NUMBER_RANGE_MAX = 15;

const char* HORIZONTAL_DIVIDER = "===================================";

void printMultTable();

int main()
{
	// Do
    printMultTable();
	cout << "Press any key to continue...";
	fgetc(stdin);

    return 0;
}

void printMultTable()
{
	// Print header
	cout << setw(5) << "n"
		<< setw(10) << "10*n"
		<< setw(10) << "100*n"
		<< setw(10) << "1000*n"
		<< endl;
	cout << HORIZONTAL_DIVIDER << endl;

	// Calculate and print the contents
	for (int i = NUMBER_RANGE_MIN; i <= NUMBER_RANGE_MAX; i++) {
		cout << setw(5) << i
			<< setw(10) << 10*i
			<< setw(10) << 100*i
			<< setw(10) << 1000*i
			<< endl;
	}

	// Footer
	cout << HORIZONTAL_DIVIDER << endl << endl;
}
