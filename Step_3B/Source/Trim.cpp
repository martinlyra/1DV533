//-----------------------------------------------------------------------
// Object: Task 03: Trim the spaces off a string
//-----------------------------------------------------------------------
// File: Trim.cpp
// Summary: This program takes an input string and trims off leading
// and trailing spaces in the string.
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
char* trimString(const char* string);

// Entry point
int main()
{
	cout << "Abbreviate a name!";

	char answer;

	do {
		cout << "\n=====================================\n";
		cout << "Please enter a text: ";
		const char* input = readLine();

		const char* treated = trimString(input);

		cout << "Trimmed text: " << treated << endl;

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		answer = readLine()[0];
	} while (tolower(answer) == 'y');

	return 0;
}

char * trimString(const char * string)
{
	// Calculate size for the buffer and indices for the copy
	size_t size = strlen(string);

	const char * leadPointer = string;
	for (; *leadPointer == ' ' && *leadPointer != '\0'; ++leadPointer);

	const char * trailPointer = &string[size - 1];
	for (; *trailPointer == ' ' && trailPointer > leadPointer; --trailPointer);

	// Create a buffer with appropriate size
	ptrdiff_t difference = trailPointer - leadPointer;
	size_t bufferSize = size - difference;
	char* out = new char[bufferSize + 1];

	// Perform copy
	char* tmp = out;
	while (leadPointer <= trailPointer) {
		*tmp = *leadPointer;

		++tmp;
		++leadPointer;
	}

	// Add null terminator
	out[bufferSize] = '\0';

	return out;
}
