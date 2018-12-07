//-----------------------------------------------------------------------
// Object: Task 02: Abbreviate a name by trimming the first name
//-----------------------------------------------------------------------
// File: NameAbbrevation.cpp
// Summary: This program takes an input name and abbreviates it by
// trimming the character after the first letter of the first name.
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
const char* treatName(const char* string);

// Entry point
int main()
{
	cout << "Abbreviate a name!";

	char answer;

	do {
		cout << "\n=====================================\n";
		cout << "Please enter a name: ";
		const char* input = readLine();

		const char* treated = treatName(input);

		cout << "Treated name: " << treated << endl;

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		answer = readLine()[0];
	} while (tolower(answer) == 'y');

	return 0;
}

const char* treatName(const char* string)
{
	// Calculate the required size for output string;
	size_t endOfFirstName = strcspn(string, " ");
	size_t size = strlen(string) - (endOfFirstName - 1);

	// Create a buffer for output string
	char* out = new char[size + 1];	// Extra char for null-terminator
	char* ptr = out;

	*ptr = string[0];
	bool firstName = true;

	// Do a special copy
	char c = 0;
	while (c = *++string) { // Save current char to 'c', check if it is > 0 before continuing
		if (firstName) {
			if (c == ' ')
				firstName = false;
			else
				continue;
		}

		*++ptr = c;
	}

	// Add null terminator
	out[size] = '\0';

	// Return reversed string
	return out;
}