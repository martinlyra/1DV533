//-----------------------------------------------------------------------
// File: Common.cpp
// Summary: This file is for ímplementation of declarations in the header
// file of same name (Common.h)
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-06	Created
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

#include "Common.h"

// Constants
const int BUFFER_SIZE = 256;

// const char* readLine()
//
// Helper function for reading whole input lines from user
const char* readLine()
{
	char input[BUFFER_SIZE];

	cin.getline(input, BUFFER_SIZE);

	streamsize readCount = cin.gcount();
	char* out = new char[readCount + 1];

	memcpy(out, input, readCount + 1);

	return out;
}