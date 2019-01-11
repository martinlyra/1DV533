//-----------------------------------------------------------------------
// Object: Task 2 - Sum numbers stored in a file
//-----------------------------------------------------------------------
// File: NumSummator.cpp
// Summary: 
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-10:	File created
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Constants
const char* TARGET_FILE_NAME = "integers.txt";

int main()
{
	vector<int> integers;

	ifstream file;
	file.open(TARGET_FILE_NAME, ios::in);
	
	if (file.fail())
		cout << "Failed to open the file " << TARGET_FILE_NAME << "!\n";

	else {
		int integer;
		while (file >> integer)
			integers.push_back(integer);

		int total = 0;
		double average = 0;
		int max = 0;

		for (int integer : integers)
		{
			total += integer;
			average += double(integer) / integers.size();

			if (integer > max)
				max = integer;
		}

		cout << "Sum: " << total << endl;
		cout << "Mean: " << average << endl;
		cout << "Max: " << max << endl;
	}

	file.close();

	cout << "\nPress any key to continue...\n";
	cin.get();
	return 0;
}