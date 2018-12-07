//-----------------------------------------------------------------------
// Object: Task 05: Determine whether a string is a palindrome
//-----------------------------------------------------------------------
// File: ManOrWoman.cpp
// Summary: This program takes an input string and checks whether it is a
// palindrome or not. It ignores whitespaces.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-05	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// Prototypes
const int BUFFER_SIZE = 256;

const char* readLine();
void checkPalindrome();
bool isAPalindrome(const char* line);

// Entry point
int main()
{
	cout << "Palindrome or not?";

	char answer;

	do {
		checkPalindrome();

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		answer = readLine()[0];
	} while (tolower(answer) == 'y');

	return 0;
}

const char* readLine()
{
	char input[BUFFER_SIZE];

	cin.getline(input, BUFFER_SIZE);

	streamsize readCount = cin.gcount();

	char* out = new char[readCount + 1];

	memcpy(out, input, readCount + 1);

	return out;
}

void checkPalindrome()
{
	cout << "\n=====================================\n";

	if (isAPalindrome(readLine())) {
		cout << "It is a palindrom.";
	}
	else {
		cout << "It is not a palindrom.";
	}
}

bool isAPalindrome(const char* line)
{
	int length = strlen(line);

	int i = 0;
	int j = length - 1;

	while (i < length && j >= 0) {
		if (line[i] == ' ')
			i++;
		if (line[j] == ' ')
			j--;

		if (tolower(line[i]) != tolower(line[j]))
			return false;

		i++; j--;
	}

	return true;
}
