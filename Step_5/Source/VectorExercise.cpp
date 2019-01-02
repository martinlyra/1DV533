//-----------------------------------------------------------------------
// Object: Task 1 - General vector exercrise without using <vector>
//-----------------------------------------------------------------------
// File: VectorExercise.cpp
// Summary: This program takes several numbers until a non-number is 
// given, then prints the output.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	Created by Martin	
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Entry point
int main() {

	int i, counter = 0;
	int* vector = nullptr;

	// Ask for input
	cout << "Enter integer numbers to store, type a non-number to stop:\n";
	while (cin >> i) {
		int* tmp = new int[counter + 1];
		memcpy_s(tmp, counter + 1, vector, counter);
		delete[] vector;
		vector = tmp;
		vector[counter] = i;
		counter++;
	}
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Print vector's contents
	cout << "Stored integers: ";
	for (int j = 0; j < counter; j++)
		cout << j << ' ';
	cout << endl;

	// Delete the vector
	delete[] vector;

	// End
	cout << "Press any key to continue...\n";
	cin.get();
	return 0;
}