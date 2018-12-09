//-----------------------------------------------------------------------
// Object: Task 04: Abbreviate words according to Swedish Military 
// nomenclature.
//-----------------------------------------------------------------------
// File: Trim.cpp
// Summary: This program takes input string and abbreviates the string
// according to the Swedish Military Nomenclature.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-06	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Assignment-common code
#include "Common.h"

// Prototypes
const int MAX_LETTERS = 5;
const int FIRST_LETTERS_COUNT = 3;
const int LAST_LETTERS_COUNT = 2;
const char* CONSONANTS = "bcdfghjklmnpqrstvwxz";
const char* VOWELS = "aeiouyöäå";	// unused, saved for future purposes

bool isConsonant(char letter);
const char* abbreviateWord(const char* string);

// Entry point
int main()
{
	char answer;

	cout << "Militarify a word!";
	do {
		// ----- Start of task-related code -----
		cout << "\n=====================================\n";
		cout << "Please enter a word: ";
		const char* input = readLine();

		const char* treated = abbreviateWord(input);

		cout << "Word in military language: " << treated << endl;

		// ----- End of task-related code -----
		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		answer = readLine()[0];
	} while (tolower(answer) == 'y');

	return 0;
}

// bool isConsonant(char)
//
// Returns true if char exists in the CONSONANT string constant, the char 
// is indeed an consonant.
bool isConsonant(char letter)
{
	for (const char* c = CONSONANTS; *c; ++c)
		if (*c == letter)
			return true;
	return false;
}

// char* abbreviateWord(const char*)
//
// Abbrevate input word by the Swedish Military Equipment Nomenclature;
// keeping only maximum 5 consonants, the 3 first and the 2 last, 
// duplicates are compressed to single one.
const char * abbreviateWord(const char * string)
{
	// Create a working buffer
	size_t bufferSize = strlen(string);
	char* buffer = new char[bufferSize + 1];

	// Treat string and write to working buffer
	int offset = 0;
	for (const char* p = string; *p; ++p) {
		char c = tolower(*p);

		if (isConsonant(c)) 
			if (tolower(buffer[offset - 1]) != c) // Avoid duplicates of the same character
				buffer[offset++] = *p;
	}
	buffer[offset] = 0;

	// Create new buffer for output string
	size_t outSize = (offset < MAX_LETTERS) ? offset : MAX_LETTERS;
	char* out = new char[outSize + 1];
	out[outSize] = 0;

	// Copy string via memory copy (strcpy and strncpy methods were useless for this purpose)
	// All if 'size < 3', or the first part
	size_t sizeFirstPart = (outSize < FIRST_LETTERS_COUNT) ? outSize : FIRST_LETTERS_COUNT;
	memcpy(out, buffer, sizeFirstPart);

	// Last part if 'size > 3', overlap allowed
	if (outSize > FIRST_LETTERS_COUNT) {
		memcpy(
			out + FIRST_LETTERS_COUNT,              // 4th character of out
			buffer + offset - LAST_LETTERS_COUNT,   // Move to the end of the buffer, then go back 2 chars
			LAST_LETTERS_COUNT
		);
	}

	// Clear the working buffer
	delete [] buffer;

	return out;
}
