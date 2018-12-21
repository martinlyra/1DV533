//-----------------------------------------------------------------------
// Object: Task 05: Calculate the height of an offspring, in Imperial
//-----------------------------------------------------------------------
// File: Encryption.cpp
// Summary: This program takes input gender and two heights, in inferior 
// Imperial, calculating the approximate height of the child, in inferior
// Imperial.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-16	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Constants
const double FOOT_TO_MILIMETERS = 304.8f;
const double INCH_TO_MILIMETERS = 25.4f;

// Gender enum
enum Gender
{
	INVAILD,
	FEMALE,
	MALE
};

// Prototypes
Gender getGender();
int getImperialHeight();
int calculateChildHeight(Gender gender, int motherHeight, int fatherHeight);
string metricToImperial(int metric);
template<typename ... Args> string stringFormat(const char* format, Args ... args);

// Entry point
int main() {
	char answer;

	do {
		Gender gender = getGender();

		cout << "Provide the heights as thie example 3\'2\"" << endl;
		cout << "Please provide mother's height: ";
		int motherHeight = getImperialHeight();
		cout << "Please provide father's height: ";
		int fatherHeight = getImperialHeight();

		int childHeight = calculateChildHeight(gender, motherHeight, fatherHeight);

		cout << "The child's approximate height is: " << metricToImperial(childHeight) << endl;

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (tolower(answer) == 'y');

	return 0;
}

// Gender getGender() 
//
// Loads gender from user input
Gender getGender() {
	char answer;
	Gender out = Gender::INVAILD;

	cout << "Please provide gender (M)ale or (F)emale: ";

	while (out == Gender::INVAILD) {
		cin >> answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		answer = tolower(answer);

		if (answer == 'm')
			out = Gender::MALE;
		else if (answer == 'f')
			out = Gender::FEMALE;
		else
			cout << "Invalid input, please try again (M/F): ";
	}

	return out;
}

// int getImperialHeight()
//
// Loads an Imperial height from user input, converted to milimeter
int getImperialHeight() {
	string imperial;

	getline(cin, imperial);

	int divider = imperial.find_first_of('\'');
	int stop = imperial.find_first_of('\"');

	int feet = stoi(imperial.substr(0, divider));
	int inches = stoi(imperial.substr(divider + 1, stop));

	return round(double(feet) * FOOT_TO_MILIMETERS + double(inches) * INCH_TO_MILIMETERS);
}

// int calculateChildHiehgt(Gender, int, int)
//
// Calculates the height of the child based on the given parameters.
int calculateChildHeight(Gender gender, int motherHeight, int fatherHeight) {
	switch (gender) {
	case MALE: return (motherHeight * 13 / 24) + fatherHeight / 2;
	case FEMALE: return (fatherHeight * 12 / 26) + motherHeight / 2;
	default: return 0;
	}
}

// string metricToImperial(int)
//
// Converts metric (milimeter) to Imperial in the foot'yard" format
string metricToImperial(int metric) {
	double remainder = metric % int(FOOT_TO_MILIMETERS);

	int inches = remainder / INCH_TO_MILIMETERS;
	int feet = round((metric - remainder) / FOOT_TO_MILIMETERS);

	return stringFormat("%i\'%i\"", feet, inches);
}

// string stringFormat(const char*, ...)
//
// A novel function for C-like formatting of strings in a secure, memory-efficient, and hassle-free way.
// Returns the result as a std::string
template<typename ... Args>
string stringFormat(const char* format, Args ... args)
{
	size_t size = snprintf(nullptr, 0, format, args ...) + 1; // get approximate size
	char* buffer = new char[size];
	snprintf(buffer, size, format, args ...);	// write to buffer
	return string(buffer, size - 1);			// transform to string
}
