//-----------------------------------------------------------------------
// Object: Task 04: Determine gender for a Swedish Personal Number
//-----------------------------------------------------------------------
// File: ManOrWoman.cpp
// Summary: This program checks whether a input Swedish Personal Number 
// belongs to a man or a woman.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-05	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// Prototypes
const string DIGITS = "0123456789";
const string VALID_CHARS = DIGITS + '-';

void checkPersonalNumber();
string getPersonalNumber();

// Entry point
int main()
{
	cout << "Swedish Personal Number: Man or Woaman?";

	char answer;

	do {
		checkPersonalNumber();

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');

	return 0;
}

void checkPersonalNumber()
{
	cout << "\n=====================================\n";

	string input;
	bool validInput = false;

	cout << "Please enter a SPN: ";
	while (!validInput) {
		input = getPersonalNumber();

		if (input.length() > 0)
			validInput = true;

		if (!validInput)
			cout << "\nPlease try again:";
	}

	cout << "The number belongs to a ";
	if (input[8] % 2)
		cout << "man\n";
	else
		cout << "woman\n";
}

string getPersonalNumber() 
{
	string out;
	string buffer;

	// Get input
	cin >> buffer;

	size_t length = buffer.length();

	// Validiation
	if (length > 11) {
		cout << "The personal number can't be longer than 11 characters!\n";
	}
	else if (length < 10) {
		cout << "The personal number can't be shorter than 10 characters!\n";
	}
	else {
		// Check if string contains no invaild characters
		for (char c : buffer)
			if (VALID_CHARS.find(c) > VALID_CHARS.length() - 1) {
				cout << "The number must be digits and an optional dash only!\n";
				return "\0";
			}

		// Sanitize and validate the input
		if (length == 11) {
			size_t offset = buffer.find('-', 0);

			if (offset != 6) {
				cout << "The personal number must be in this format: YYMMDD-NNNN, dash optional\n";
			}
			else {
				out = buffer.substr(0, offset);
				out += buffer.substr(offset + 1);
			}
		}
		else {
			out = buffer;
		}
	}

	return out;
}

