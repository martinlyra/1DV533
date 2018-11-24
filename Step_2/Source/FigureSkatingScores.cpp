//-----------------------------------------------------------------------
// Object: Task 07: Calculate the median score for figure skating
//-----------------------------------------------------------------------
// File: FigureSkatingScores.cpp
// Summary: This program calculates the judgemental score from an input
// of nine integers.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-11-24	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;

// Prototypes
const int INPUT_MAX_COUNT = 9;

void calculateScore();

// Entry point
int main()
{
	char answer;
	do
	{
		calculateScore();
		cout << "\nOne more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

// void calculateScore
// Takes 9 judgmental score and calculates the final median score
void calculateScore()
{
	int count = 0;
	double input = 0;
	double min = 0;
	double max = 0;
	double sum = 0;

	cout << "Please input " << 8 << " scores." << endl;

	while (count < INPUT_MAX_COUNT)
	{
		// Get input line and turn it into a string stream
		string line;
		getline(cin, line);
		istringstream is(line);

		istream_iterator<double> eos; // end of stream iterator
		istream_iterator<double> iterator(is); // integer iterator over stream

		do {
			input = *iterator;

			// Initialize min-max
			if (!count)
				min = max = input;
			// Max
			else if (input > max)
				max = input;
			// Min
			else if (input < min)
				min = input;

			sum += input;

			count++;

			++iterator;
		} while (eos != iterator && count < INPUT_MAX_COUNT);

		// Check if we've collected required number of input
		int diff = INPUT_MAX_COUNT - count;
		if (diff > 0)
			cout << diff << " more." << endl;
	}

	// Calculation & output
	sum -= max + min;
	sum /= count - 2;

	cout << setprecision(2)
	     << "\nThe final score is " << sum << endl;
}