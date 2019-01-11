//-----------------------------------------------------------------------
// Object: Task 1 - Telehphone contact registar
//-----------------------------------------------------------------------
// File: PhoneRegistar.cpp
// Summary: This program takes user input then saves it to a file.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-10:	File created
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Constants
const char* TARGET_FILE_NAME = "tfnregister.csv";

// Prototypes
void phoneRegistar();

int main()
{
	char answer;
	do
	{
		phoneRegistar();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

void phoneRegistar()
{
	string first, last, num;

	cout << "First name: ";
	getline(cin, first);

	cout << "Surname: ";
	getline(cin, last);

	cout << "Phone number: ";
	getline(cin, num);

	ofstream file;
	file.open(TARGET_FILE_NAME, ios::app | ios::out);
	file << first << ',' << last << ',' << num << '\n';
	file.close();

	cout << "Details has been saved to " << TARGET_FILE_NAME << endl;
}
