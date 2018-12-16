//-----------------------------------------------------------------------
// Object: Task 01: Abbreviate a name by trimming the first name
//-----------------------------------------------------------------------
// File: CubicProblem.cpp
// Summary: This program takes an input name and abbreviates it by
// trimming the character after the first letter of the first name.
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

int main()
{
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

double power(double base, double exponent)
{
	if (!exponent)
		return 1;
	return base * power(base, exponent - 1);
}
