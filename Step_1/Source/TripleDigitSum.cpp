//-----------------------------------------------------------------------
// Object: Solution for Task 11 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: TripleDigitSum.cpp
// Summary: This program calculates the sum of a 3-digit number input.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-10:	Created by Martin	
//-----------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

const int DIGIT_COUNT = 3;

void getDigitSum();

int main()
{
	char answer;
	do
	{
		getDigitSum();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void getDigitSum()
{
	string input;

	cout << "Give me a 3-digit number: ";
	cin >> input;

	if (input.length() > DIGIT_COUNT) {
		cout << "The number has more than 3 digits. Please try again." << endl;
		return;
	}
	else if (input.length() < DIGIT_COUNT) {
		cout << "The number has less than 3 digits. Please try again." << endl;
		return;
	}

	int sum = 0;
	for (int i = 0; i < DIGIT_COUNT; i++) {
		sum += (input.at(i) - '0');	// The '0' character comes before the other values, we can get the actual value this way
	}

	cout << "The sum of the number's digits is " << sum << endl << endl;
}