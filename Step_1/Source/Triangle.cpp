//-----------------------------------------------------------------------
// Object: Solution for Task 10 of 1st Assingment for 1DV533
//-----------------------------------------------------------------------
// File: Triangle.cpp
// Summary: This program takes lengths of two legs of a triangle,
// calculating the hypotenuse based on the lengths.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-08:	Created by Martin	
//-----------------------------------------------------------------------

// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Prototypes
void calculateHypotenuse();

int main()
{
	char answer;
	do
	{
		calculateHypotenuse();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void calculateHypotenuse()
{
	double lengthA;
	double lengthB;

	cout << "Specify the length of leg 'a': ";
	cin >> lengthA;
	cout << "Specify the length of leg 'b': ";
	cin >> lengthB;

	double hypotenuse = sqrt(pow(lengthA, 2) + pow(lengthB, 2));

	cout << fixed << setprecision(2);
	cout << "The triangle's hypotenuse is " << hypotenuse << " length units" << endl;
}