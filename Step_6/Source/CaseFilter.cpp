//-----------------------------------------------------------------------
// Object: Task 4 - Sum numbers stored in a file
//-----------------------------------------------------------------------
// File: CaseFilter.cpp
// Summary: 
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-11:	File created
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Constants
const char* TARGET_FILE_NAME = "abcfile.dat";

int main() {
	ifstream file;
	file.open(TARGET_FILE_NAME, ios::in | ios::binary);

	if (file.fail())
		cout << "Failed to open the file " << TARGET_FILE_NAME << "!\n";

	else {
		ofstream upperFile("upper.txt");
		ofstream lowerFile("lower.txt");

		char c;
		while (c = file.get()) {
			if (isalnum(c)) {
				if (isupper(c))
					upperFile << c;
				else if (islower(c))
					lowerFile << c;
			}
			else {
				upperFile << c;
				lowerFile << c;
			}
		}

		upperFile.close();
		lowerFile.close();

		cout << "Contents of the file " << TARGET_FILE_NAME << " have been processed!\n"
			<< "Check out lower.txt and upper.txt!\n";
	}

	file.close();

	cout << "\nPress any key to continue...\n";
	cin.get();
	return 0;
}