//-----------------------------------------------------------------------
// Object: Task 6 - Surface measurements and their averages
//-----------------------------------------------------------------------
// File: SurfaceMeasurements.cpp
// Summary: This program loads numbers from file and calculates mean
// values and largest difference between measures numbers.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-11:	File created
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Constants
const char* TARGET_FILE_NAME = "surfacedata.txt";

// Prototypes
void printRow(const char* keyName, double value);

// Entry point
int main() {
	ifstream data(TARGET_FILE_NAME, ios::in);

	if (data.fail())
		cout << "Failed to open the file " << TARGET_FILE_NAME << "!\n";
	else {
		vector<double> numbers;
		
		double i;
		while (data >> i)
		{
			numbers.push_back(i);
		}

		data.close();

		double arithmetic = 0, rootMean = 0, min, max;
		min = max = numbers.front();

		for (double num : numbers) {
			arithmetic += abs(num);
			rootMean += pow(num, 2);

			if (num < min)
				min = num;
			if (num > max)
				max = num;
		}

		arithmetic /= numbers.size();
		rootMean = sqrt(rootMean / numbers.size());

		cout << fixed << setprecision(3);
		printRow("Ra", arithmetic);
		printRow("Rq", rootMean);
		printRow("Maximum height", max - min);

		cout << setprecision(0);
		printRow("Amount of numbers", numbers.size());

		cout << "All done!\n";
	}

	cout << "\nPress any key to continue...\n";
	cin.get();
	return 0;
}

// void printRow(const char*, double)
//
// Prints a standardized row with variable name and value
void printRow(const char * keyName, double value)
{
	cout << setw(20) << left << keyName << ":" << setw(10) << right << value << endl;
}
