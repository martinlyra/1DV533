//-----------------------------------------------------------------------
// Object: Task 5 - Take some friends then put them in order
//-----------------------------------------------------------------------
// File: FriendsInOrder.cpp
// Summary: This program takes several numbers until a non-number is 
// given, then prints the output.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	File created by Martin
//-----------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Constants
const int BUFLEN = 100; // Max length of reading buffer

// Prototypes
// Addition: Merge sort algothrim based off bottom-up shown on Wikipedia
void mergeArraySort(char *[], int);
void mergeArray(char *[], int, int, int, char*[]);

void sort(char *friendList[], int n); // n is the amount of elements
void print(char *friendList[], int n); // n is the amount of elements
void terminate(char *friendList[], int n); // n is the amount of elements

const int AMOUNT = 5;

// Entry point
int main()
{
	char* friends[AMOUNT]; // Vector with AMOUNT pcs of string pointers
	char buff[BUFLEN] = { "" }; // Creates string buffer (null terminated)
	int count = 0;
	while (count < AMOUNT) // As long as space available in the vector
	{
		cout << "Name a friend: ";
		cin.getline(buff, BUFLEN); // Temporary reading into string buffer
		int length = strlen(buff) + 1;					// #
		friends[count] = new char[length];				// #
		memcpy_s(friends[count], length, buff, length); // #
		++count;
	}
	sort(friends, count); // Sorts the ‘count’ first elements of the vector with string pointers
	print(friends, count); // Prints the ‘count’ first names
	terminate(friends, count); // Releases all allocated memory space

	cout << "\nPress any key to continue...\n";
	cin.get();
	return 0;
}

// void mergeArraySort(char*[], int)
//
// Merge Sorting, primary entry function that splits up the given array for sorting
void mergeArraySort(char *source[], int size)
{
	char** buffer = new char*[size];

	for (int width = 1; width < size; width *= 2) {
		for (int i = 0; i < size; i += width * 2) {
			mergeArray(source, min(i, size - 1), min(i + width, size - 1), min(i + 2*width, size), buffer);
		}

		// Save to source
		for (int i = 0; i < size; i++)
			source[i] = buffer[i];
	}

	delete[] buffer;
}

// void mergeArray(char*[], int, int, int, char*[])
//
// Sorting part of merge sort
void mergeArray(char *source[], int left, int right, int end, char *dest[])
{
	int i = left, j = right;
	for (int k = left; k < end; k++) {
		if (i < right && (j >= end || strcmp(source[i], source[j]) <= 0)) {
			dest[k] = source[i];
			i++;
		}
		else {
			dest[k] = source[j];
			j++;
		}
	}
}

// void sort(char*[], int)
//
// Sort the list in alphabetical order
void sort(char *friendList[], int n)
{
	mergeArraySort(friendList, n);
}

// void print(char*[], int)
//
// Print the list
void print(char *friendList[], int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << friendList[i] << endl;
}

// void terminate(char*[], int)
//
// Dellocate memory space used by the list
void terminate(char *friendList[], int n)
{
	for (int i = 0; i < n; i++)
		delete[] friendList[i];
}
