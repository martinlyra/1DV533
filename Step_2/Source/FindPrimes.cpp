//-----------------------------------------------------------------------
// Object: Task 08: Find primes from 2 to 100
//-----------------------------------------------------------------------
// File: FindPrime.cpp
// Summary: This program finds primes in a specified (constant) range
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

// Prototype
const int NUMBER_RANGE_MIN = 2;
const int NUMBER_RANGE_MAX = 100;

vector<int> knownPrimes = { };

bool isAPrime(int integer, vector<int> primes);

// Entry point
int main()
{
	// Header
	cout << "PRIME FINDER\nPrimes between "
		<< NUMBER_RANGE_MIN << " and " << NUMBER_RANGE_MAX
		<< "\n===================================\n";

	// Find primes
	for (int i = NUMBER_RANGE_MIN; i <= NUMBER_RANGE_MAX; i++)
	{
		if (isAPrime(i, knownPrimes)) {
			knownPrimes.push_back(i);
			cout << i << " ";
		}
	}

	// End of program
	cout << "\n\nPress any key to continue...";
	fgetc(stdin);
}

// bool isAPrime
// Checks whether an integer is a prime against a list of known primes
bool isAPrime(int integer, vector<int> primes)
{
	for (int prime : primes)
		if ((prime != 1 || prime != 0) && integer % prime < 1)
			return false;
	return true;
}