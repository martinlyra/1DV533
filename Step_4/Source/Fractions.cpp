//-----------------------------------------------------------------------
// Object: Task 07: Implement fraction arithmetic operations
//-----------------------------------------------------------------------
// File: Fractions.cpp
// Summary: This programs performs fraction arithmetics 
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-04	Created
//              2018-12-17  Modified for Step 4
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Constants
// enum Operation
// Enumeration representing arithmetic operations in mathematics
enum Operation {
	ADDITION,
	SUBSTRACTION,
	MULTIPLICATION,
	DIVISON,

	ALWAYS_AT_END // Count of enum values
};

// Prototypes
struct Fraction;

int gcd(int a, int b);
Operation pickOperation();
bool loadFraction(Fraction& fraction);
template<typename ... Args> string stringFormat(const char* format, Args ... args);

// struct Fraction
// A data structure for storing and easily processing fractions
//
struct Fraction
{
	int numerator;
	int denominator;

	// Default constructor
	Fraction()
	{

	}

	// Constructor
	Fraction(int numerator, int denominator)
		: numerator(numerator), denominator(denominator)
	{
		if (denominator < 0) {
			this->denominator *= -1;
			this->numerator *= -1;
		}
	}

	// Fraction abbreviate()
	// Return a Fraction with the smallest equivalent of the same fraction
	Fraction abbreviate()
	{
		int factor = gcd(numerator, denominator);
		return Fraction(numerator / factor, denominator / factor);
	}

	// string toStringFull()
	// Returns a string of the two terms in a divison
	string toStringFull()
	{
		return stringFormat("%i/%i", numerator, denominator);
	}

	// string toStringFull()
	// Returns a string of the fraction expressed as an integer followed by an fraction representing the decimals
	// If n % d = 0, no decimal fraction will be displayed
	// If n / d < 1, no integer quota will be displayed
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

	// Fraction operator+(Fraction&)
	//
	// Addition
	Fraction operator+(Fraction& other)
	{
		int n, d;

		if (denominator != other.denominator) {
			n = numerator * other.denominator + other.numerator * denominator;
			d = denominator * other.denominator;
		}
		else
		{
			n = numerator - other.numerator;
			d = denominator;
		}

		return Fraction(n, d);
	}

	// Fraction operator-(Fraction&)
	//
	// Substraction
	Fraction operator-(Fraction& other)
	{
		int n, d;

		if (denominator != other.denominator) {
			n = numerator * other.denominator - other.numerator * denominator;
			d = denominator * other.denominator;
		}
		else
		{
			n = numerator - other.numerator;
			d = denominator;
		}

		return Fraction(n, d);
	}

	// Fraction operator*(Fraction&)
	//
	// Multiplication
	Fraction operator*(Fraction& other)
	{
		int n, d;

		n = numerator * other.numerator;
		d = denominator * other.denominator;

		return Fraction(n, d);
	}

	// Fraction operator/(Fraction&)
	//
	// Divison
	Fraction operator/(Fraction& other)
	{
		int n, d;

		n = numerator * other.denominator;
		d = denominator * other.numerator;

		return Fraction(n, d);
	}
};

// Entry point
int main() {
	char answer;

	do {
		Operation op;
		char operationChar;
		Fraction fracA, fracB, fracR;

		// Ask for operation
		op = pickOperation();
		cout << '\n';

		// Get fraction A
		cout << "Please input the first fraction: ";
		while (!loadFraction(fracA)) 
			cout << "Improper input, please try again.\n";

		// Get fraction B
		cout << "Please input the second fraction: ";
		while (!loadFraction(fracB)) 
			cout << "Improper input, please try again.\n";

		// Calculate fraction R based on selected operation and the fractions A & B
		switch (op)
		{
		case ADDITION:
			operationChar = '+';
			fracR = fracA + fracB;
			break;
		case SUBSTRACTION:
			operationChar = '-';
			fracR = fracA - fracB;
			break;
		case MULTIPLICATION:
			operationChar = '*';
			fracR = fracA * fracB;
			break;
		case DIVISON:
			operationChar = '/';
			fracR = fracA / fracB;
			break;
		default:
			break;
		}

		// Print result
		cout << "\nCalculation:\n";
		cout << fracA.toStringFull() 
			<< " " << operationChar << " " 
			<< fracB.toStringFull() << " = " 
			<< fracR.abbreviate().toStringFull() << '\n';

		cout << endl << "Once more (Y/N)? ";
		cin >> answer;
	} while (tolower(answer) == 'y');

	return 0;
}

// int gcd(int, int)
//
// Greatest Common Divisor as a recursive function
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Operation pickOperation()
//
// Ask user to pick one mathematical arithmetic operation
Operation pickOperation()
{
	cout << "Pick arithmetic operator:\n"
		<< "1. + Addition\n"
		<< "2. - Substraction\n"
		<< "3. * Multiplication\n"
		<< "4. / Divison\n";
	cout << "What's your pick?: ";

	int pick;
	bool vaild = false;

	while (!vaild) {
		cin >> pick;
		pick -= 1;

		if (pick >= ADDITION && pick < ALWAYS_AT_END)
			vaild = true;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return Operation(pick);
}

// bool loadFraction(Fraction&)
//
// Loads input fraction to parameter, returns true if the input was read error-free.
bool loadFraction(Fraction & fraction)
{
	string input;

	getline(cin, input);

	int divisor = input.find('/');
	if (!divisor || divisor >= input.length())
		return false;

	int numerator = stoi(input.substr(0, divisor));
	int denominator = stoi(input.substr(divisor + 1));

	fraction = Fraction(numerator, denominator);

	return true;
}

// string stringFormat(const char*, ...)
//
// A novel function for C-like formatting of strings in a secure, memory-efficient, and hassle-free way.
// Returns the result as a std::string
template<typename ... Args>
string stringFormat(const char* format, Args ... args)
{
	size_t size = snprintf(nullptr, 0, format, args ...) + 1; // get approximate size
	char* buffer = new char[size];
	snprintf(buffer, size, format, args ...);	// write to buffer
	return string(buffer, size - 1);			// transform to string
}