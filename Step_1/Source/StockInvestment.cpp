//-----------------------------------------------------------------------
// Object: Solution for Task 13 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: StockInvestment.cpp
// Summary: This program calculates the return for a stock investment
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-10:	Created by Martin	
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

const double INTEREST_RATE = 0.03f;

void calculateInvestment();

int main()
{
	char answer;
	do
	{
		calculateInvestment();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void calculateInvestment()
{
	double initialInvestment;
	int years;
	vector<double> changes;

	cout << "INVESTMENT CALCULATOR" << endl
		<< "================================" << endl;

	cout << "Load initial amount : ";
	cin >> initialInvestment;
	cout << "Load number of years: ";
	cin >> years;

	cout << "================================" << endl;

	cout << "Load stock changes (%) for the " << years << " years;" << endl;
	
	double d;
	for (int i = 0; i < years; i++) {
		cout << i + 1 << ": ";
		cin >> d;
		changes.push_back(1 + d / 100);
	}

	double totalChange = 1;
	for (int i = 0; i < years; i++) {
		totalChange *= changes[i];
	}

	cout << "================================" << endl;

	cout << fixed << setprecision(2);
	cout << "For the given stock changes, the return for the investment is "
		<< initialInvestment * totalChange << " SEK" << endl << endl;
}