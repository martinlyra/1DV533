//-----------------------------------------------------------------------
// Object: Task 02: Take N numbers, then find numbers lower than M
//-----------------------------------------------------------------------
// File: ArrayExercise.cpp
// Summary: This program finds primes in a specified (constant) range
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-04	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

// Entry point
int main()
{
	char answer;

	do {
		// Prepare variables
		int count;
		vector<int> integers = { };

		// Get number for how many N to get
		cout << "Enter how many N to input: ";
		cin >> count;

		// Get N until count has been reached
		for (int i = 0; i < count; i++) {
			int in;
			cout << "Number " << i + 1 << ": ";
			cin >> in;
			integers.push_back(in);
		}

		// Get number M
		int m;
		cout << "Enter number M to compare with N: ";
		cin >> m;

		// Count how many N lower than M
		int c = 0;
		for (int n : integers) {
			if (n < m)
				c++;
		}

		cout << c << " numbers lower than M." << "\n\n";

		// Print the integers in reverse order
		for (int i = integers.size() - 1; i >= 0; i--)
			cout << integers[i] << endl;

		// End of program
		cout << "\nDo you want to repeat again? (y/n)";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');

	return 0;
}