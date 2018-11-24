//-----------------------------------------------------------------------
// Object: Task 06: Find the second largest number from input
//-----------------------------------------------------------------------
// File: SecondLargestNum.cpp
// Summary: This program takes input of 10 numbers and then shows the
// second largest integer from input
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;

// Prototypes
const int INPUT_MAX_COUNT = 10;

void findSecondLargestInteger();

// Entry point
int main()
{
	char answer;
	do 
	{
		findSecondLargestInteger();
		cout << "\nOne more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');

	return 0;
}

// void findSecondLargestInteger
// Takes an input N times then takes the second largest input and prints 
// it to cout
void findSecondLargestInteger()
{
	int count = 0;
	int input = 0;
	int current = 0;
	int previous = 0;
	
	cout << "Please input " << INPUT_MAX_COUNT << " integers." << endl;
		
	while (count < INPUT_MAX_COUNT) 
	{
		// Get input line and turn it into a string stream
		string line;
		getline(cin, line);
		istringstream is(line);

		istream_iterator<int> eos; // end of stream iterator
		istream_iterator<int> iterator( is ); // integer iterator over stream

		do {
			input = *iterator;

			// Actual logic - largest
			if (input > current) {
				previous = current;
				current = input;
			}
			// Second largest
			else if (input > previous) {
				previous = input;
			}

			count++;

			++iterator;
		} while (eos != iterator && count < INPUT_MAX_COUNT);

		// Check if we've collected required number of input
		int diff = INPUT_MAX_COUNT - count;
		if (diff > 0)
			cout << diff << " more." << endl;
	}

	// Output
	cout << "\nSecond largest number is " << previous << endl;
}