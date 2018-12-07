//-----------------------------------------------------------------------
// Object: Task 01: Reverse a string with pointer decrementation
//-----------------------------------------------------------------------
// File: Backwards.cpp
// Summary: This program takes an input string and reverses it
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-06	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

#include "Common.h"

// Prototypes
const char* reverseString(const char* string);

// Entry point
int main()
{
	cout << "Reverse a string!";

	char answer;

	do {
		cout << "\n=====================================\n";
		cout << "Please enter a text: ";
		const char* input = readLine();

		const char* reversed = reverseString(input);

		cout << "The text backwards: " << reversed << endl;

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		answer = readLine()[0];
	} while (tolower(answer) == 'y');

	return 0;
}

const char* reverseString(const char* string)
{
	// Create a buffer copy of same size
	size_t size = strlen(string);
	char* out = new char[size + 1];

	// Set the pointer at other end of the array and plant null terminator
	char* ptr = &(out[size]);
	*ptr = '\0';

	// Do bilateral copy
	while (*string) {
		*--ptr = *string;
		++string;
	}

	// Compare the pointers to ensure that the memory is intact
	_ASSERT(ptr == out);

	// Return reversed string
	return out;
}