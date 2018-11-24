//-----------------------------------------------------------------------
// Object: Task 03: Product of odds from 1 to 15
//-----------------------------------------------------------------------
// File: OddNumberSum.cpp
// Summary: This program takes the odd numbers from 1 to 15, then 
// multiply them together to an output product.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototypes
const int NUMBER_RANGE_MIN = 1;
const int NUMBER_RANGE_MAX = 15;

bool isOdd(int integer);

// Entry point
int main()
{
    int sum = 1;

	// Calculate product
    for (int i = NUMBER_RANGE_MIN; i <= NUMBER_RANGE_MAX; i++) {
        if (isOdd(i))
            sum *= i;
    }

	// Output
    cout << "The sum of odd integers between " << NUMBER_RANGE_MIN
         << " and " << NUMBER_RANGE_MAX << " is:" << endl
         << sum << endl << endl;

	cout << "Press any key to continue...";
	fgetc(stdin);
}

// bool isOdd
// Checks whether given integer is odd or not, true if odd
bool isOdd(int integer)
{
    return integer % 2;
}
