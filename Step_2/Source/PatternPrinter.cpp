//-----------------------------------------------------------------------
// Object: Task 05: Print a specified pattern
//-----------------------------------------------------------------------
// File: SecondLargestNum.cpp
// Summary: This program prints a pattern of stars in a checkerboard 
// pattern.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototypes
const int PATTERN_HORIZONTIAL_REPETITION_NUM = 8;
const int PATTERN_VERTICAL_REPETITION_NUM = 8;

void drawPattern();

// Entry point
int main()
{
	// Draw the pattern
	drawPattern();

	cout << "\nPress any key to continue...";
	fgetc(stdin);
}

// void drawPattern
// Draws a pattern of stars (asterisks) in a checkerboard pattern to cout
void drawPattern()
{
	// Vertical
	for (int x = 0; x < PATTERN_VERTICAL_REPETITION_NUM; x++) 
	{
		// Horizontal
		for (int y = 0; y < PATTERN_HORIZONTIAL_REPETITION_NUM; y++) 
		{
			if (!y && x % 2)
				cout << " ";
			else {
				cout << "* ";
			}	
		}
		cout << endl;
	}
}