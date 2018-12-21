//-----------------------------------------------------------------------
// Object: Task 01: The cubic problem using functions
//-----------------------------------------------------------------------
// File: CubicProblem.cpp
// Summary: This program takes the side of a cube, then calculates the
// volume.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-16	Created
//-----------------------------------------------------------------------

#include <iostream>
#include <cctype> // toupper
using namespace std;

// Prototypes
void getSide(double& side);
double cubeVolume(double side);
void printVolume(double side);

// Entry point
int main()
{
	char answer = 'Y';
	cout << "Cubes" << endl;
	cout << "=====" << endl << endl;
	do
	{
		double side;

		getSide(side);
		printVolume(side);
		
		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

// void getSide(double&)
//
// Loads input value to parameter
void getSide(double& side)
{
	cout << "Enter the side length of the cube to be computed: ";
	cin >> side;
}

// double cubeVolume(double)
//
// Caculates the volume of a cube with the given side
double cubeVolume(double side)
{
	return side * side * side;
}

// void printVolume(double)
//
// Output for the solution of the cubic problem
void printVolume(double side)
{
	cout << "Volume of cube is: " << cubeVolume(side) << " volume units" << endl;
}
