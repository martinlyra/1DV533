//-----------------------------------------------------------------------
// Object: Task 06: Calculate and display discount and final price
//-----------------------------------------------------------------------
// File: Discount.cpp
// Summary: This program takes an input price, selects the appropriate
// discount and then detucts from the final price.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-17	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Prototypes
void load(double& sum);
int discount(double sum);
void print(double sum, double discountKr);

// Entry point
int main()
{
	cout << "Discount" << endl;

	double sum = 0.0, discountKr = 0.0;
	char answer;
	do {
		cout << "======" << endl << endl;

		load(sum);

		discountKr = sum * discount(sum) / 100;

		sum = sum - discountKr;

		print(sum, discountKr);
		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (tolower(answer == 'y'));

	return 0;
}

// void load(double&)
//
// Loads an input double to parameter
void load(double & sum)
{
	cout << "Enter the sum: ";
	cin >> sum;
}

// int discount(double)
//
// Selects an discount based on the given value
int discount(double sum)
{
	if (sum < 500.0f)
		return 0;
	else if (sum < 1000.0f)
		return 5;
	else if (sum < 5000.0f)
		return 10;
	else
		return 15;
}

// void print(double, double)
//
// Prints an elaborate output for both sum and discount
void print(double sum, double dKr)
{
	cout << fixed << setprecision(2);
	cout << "Discount    : " << setfill('.') << setw(10) << round(dKr) << " kr" << endl;
	cout << "Net sum     : " << setfill('.') << setw(10) << round(sum) << " kr" << endl;
}
