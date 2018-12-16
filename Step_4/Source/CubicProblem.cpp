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
void getSide(double* side);
double cubeVolume(double side);
void printVolume(double side);

int main()
{
	char answer = 'Y';
	cout << "Cubes" << endl;
	cout << "=====" << endl << endl;
	do
	{
		double side;

		getSide(&side);
		printVolume(side);
		
		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

void getSide(double * side)
{
	cout << "Enter the side length of the cube to be computed: ";
	cin >> *side;
}

double cubeVolume(double side)
{
	return side * side * side;
}

void printVolume(double side)
{
	cout << "Volume of cube is: " << cubeVolume(side) << " volume units" << endl;
}
