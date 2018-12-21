//-----------------------------------------------------------------------
// Object: Task 03: Default parameter in a power function
//-----------------------------------------------------------------------
// File: ByDefault.cpp
// Summary: This program calculates 2^n for n in N
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-16	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <cctype> // toupper
using namespace std;

// Prototypes
double power(double base, double exponent = 2);

// Entry point
int main()
{
	// Shameless copy paste from PM
	for (int i = 0; i < 10; i++)
		cout << power(2, i) << " "; // prints 2 raised to the power of i
	cout << endl;
	cout << power(3) << endl; // will print 9
	cout << power(4) << endl; // will print 16
	cout << power(5) << endl; // will print 25

	cout << "Press any key to continue...";
	getchar();
	return 0;
}

// double power(double, double)
//
// Recursive function for calculating the product of the potent of given base and exponent
double power(double base, double exponent)
{
	if (exponent > 0)
		return base * power(base, exponent - 1);
	else if (exponent < 0)
		return power(base, exponent + 1) / base;
	else
		return 1;
}
