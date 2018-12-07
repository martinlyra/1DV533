//-----------------------------------------------------------------------
// Object: Task 03: Take a fraction then shorten it, if possible
//-----------------------------------------------------------------------
// File: Fractions.cpp
// Summary: This programs calculates different ways to display fractions.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-04	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Prototypes
int gcd(int a, int b);
template<typename ... Args> string stringFormat(const char* format, Args ... args);

struct Fraction
{
	int numerator;
	int denominator;

	Fraction(int numerator, int denominator)
		: numerator(numerator), denominator(denominator)
	{
		if (denominator < 0) {
			this->denominator *= -1;
			this->numerator *= -1;
		}
	}

	Fraction abbreviate()
	{
		int factor = gcd(numerator, denominator);
		return Fraction(numerator / factor, denominator / factor);
	}

	string toStringFull() 
	{
		return stringFormat("%i/%i", numerator, denominator);
	}

	string toStringMixed()
	{
		int remainder = numerator % denominator;
		int quota = (numerator - remainder) / denominator;

		if (remainder) {
			if (quota)
				return stringFormat("%i %i/%i", quota, remainder, denominator);
			return toStringFull();
		}
		return stringFormat("%i", quota);
	}
};

// Entry point
int main()
{
	char answer;

	do {
		cout << "FRACTION CALCULATOR"
			<< "\n===================================\n";

		// Variables
		int n, d;

		cout << "Enter the numerator: ";
		cin >> n;

		cout << "Enter the denominator: ";
		cin >> d;

		// Turn input into data struct & shorten
		Fraction frac(n, d);

		auto abbreviated = frac.abbreviate();

		// Print result
		cout << "The fraction can be abbreviated to "
			<< abbreviated.toStringFull() << " == "
			<< abbreviated.toStringMixed() << "\n";

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');

	return 0;
}

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

template<typename ... Args>
string stringFormat(const char* format, Args ... args) 
{
	size_t size = snprintf(nullptr, 0, format, args ...) + 1; // get approximate size
	char* buffer = new char[size];
	snprintf(buffer, size, format, args ...);	// write to buffer
	return string(buffer, size - 1);			// transform to string
}