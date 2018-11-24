//-----------------------------------------------------------------------
// Object: Task 09: Calculate the sum of digits in a number
//-----------------------------------------------------------------------
// File: NumberSum.cpp
// Summary: This program validates input then calculates the sum of the 
// digits in the number.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <limits>
using namespace std;

// Prototypes
void calculateSum();

// Entry point
int main()
{
	char answer;
	do
	{
		calculateSum();
		cout << "\nOne more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

// void calculateSum()
// Takes a positive number between 0 and INT_MAX, then calculates the sum
// of digits in the number
void calculateSum()
{
	// Take and validate input until valid
	bool valid = false;
	long input;
	cout << "Input a positive number between " << 0 << " and " << INT_MAX << ".\n";
	do {
		cin >> input;
		if (input < 0)
			cout << "Input number can't be negative! Try again.\n";
		else if (input > INT_MAX)
			cout << "Input number can't be larger than " << INT_MAX << "! Try again.\n";
		else
			valid = true;
	} while (!valid);

	// Calculate sum
	unsigned int number = input;
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	// Output
	cout << "The sum is " << sum << endl;
}

