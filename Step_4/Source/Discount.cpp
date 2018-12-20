//-----------------------------------------------------------------------
// Object: Task 06: 
//-----------------------------------------------------------------------
// File: Discount.cpp
// Summary: 
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-17	Created
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototypes
void load(double& sum);
int discount(double sum);
void print(double sum, double discountKr);

int main()
{
	double sum = 0.0, discountKr = 0.0;
	char answer;
	do {
		system("CLS"); // Clear screen
		cout << "Discount" << endl;
		cout << "======" << endl << endl;

		load(sum);

		discountKr = sum * discount(sum) / 100;

		sum = sum - discountKr;

		print(sum, discountKr);
		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer == 'Y'));

	return 0;
}

void load(double & sum)
{
	cout << "Enter the sum: ";
	cin >> sum;
}

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
// Add necessary function definitions here
void print(double sum, double dKr)
{
	cout << "Discount" << ':' << dKr << " kr" << endl;
	cout << "Net sum" << ':' << sum << " kr" << endl;
}