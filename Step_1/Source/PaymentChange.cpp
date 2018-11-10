//-----------------------------------------------------------------------
// Object: Solution for Task 8 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: PaymentChange.cpp
// Summary: This program calculates the change and applicable forms of 
// currency covering the exact sum of the change.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-09:	Created by Martin	
//-----------------------------------------------------------------------

// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

// Prototypes

struct CurrencyInfo {
	const int value;
	const char* name;

	CurrencyInfo(int value, const char* name)
		: value(value), name(name) {}
};

// Valid Swedish Currency since October 2016, as of 2018
const vector<CurrencyInfo> swedishCurrency = 
{
	CurrencyInfo(1000, "1000-note"),
	CurrencyInfo(500, "500-note"),
	CurrencyInfo(200, "200-note"),
	CurrencyInfo(100, "100-note"),
	CurrencyInfo(50, "50-note"),
	CurrencyInfo(20, "20-note"),

	CurrencyInfo(10, "10-coin"),
	CurrencyInfo(5, "5-coin"),
	CurrencyInfo(2, "2-coin"),
	CurrencyInfo(1, "1-coin")
};

void calculateChange();

int main()
{
	char answer;
	do
	{
		calculateChange();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

double count(double value, double& remainder,double modulo) 
{
	remainder = fmodf(value, modulo);
	return (value - remainder) / modulo;
}

void calculateChange()
{
	double price;
	double payment;

	cout << "Price of the product you want to pay: ";
	cin >> price;
	cout << "State how much you want to pay: ";
	cin >> payment;

	double remainder = payment - ceil(price);
	cout << endl << "Change return " << remainder << endl
		<< "In following values" << endl;

	for (int i = 0; i < swedishCurrency.size(); i++) {
		CurrencyInfo info = swedishCurrency[i];
		double c = count(remainder, remainder, info.value);

		if (c > 0)
			cout << c << " " << info.name << (c > 1 ? "s" : "") << endl;
	}

}