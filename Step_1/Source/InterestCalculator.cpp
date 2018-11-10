//-----------------------------------------------------------------------
// Object: Solution for Task 14 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: InterestCalculator.cpp
// Summary: This program calculates the interest of an amount of money
// over a given span of years.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-10:	Created by Martin	
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double INTEREST_RATE = 0.03f;

void calculateInterest();

int main()
{
	char answer;
	do
	{
		calculateInterest();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void calculateInterest()
{
	double span;
	double money;

	cout << "INTEREST CALCULATOR" << endl
		 << "================================" << endl;

	cout << "Load initial amount : ";
	cin >> money;
	cout << "Load number of years: ";
	cin >> span;

	cout << "================================" << endl;

	double moneyWithInterest = money * pow(1 + INTEREST_RATE, span);

	cout << fixed << setprecision(2);
	cout << "After " << span << " years, with " << INTEREST_RATE * 100 << " % interest rate," <<
		"the capital will be " << moneyWithInterest << " SEK" << endl << endl;
}