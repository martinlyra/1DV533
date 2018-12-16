//-----------------------------------------------------------------------
// Object: Task 04: Abbreviate a name by trimming the first name
//-----------------------------------------------------------------------
// File: Encryption.cpp
// Summary: This program takes an input name and abbreviates it by
// trimming the character after the first letter of the first name.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2018-12-16	Created
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

// Constants
const char* CIPHER_KEY = "defghijklmnopqrstuvwxyzabc";
const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
int BUFFER_SIZE = 255;

// Prototypes
char* encrypt(char* encryptedText, const char* plaintext);

int main()
{
	char answer = 'Y';
	cout << "Encryption" << endl;
	cout << "=====" << endl << endl;
	do
	{
		char* plain = new char[BUFFER_SIZE];
		char* encrypted = nullptr;

		// Ask for input
		cout << "Enter a text to encrypt: ";
		cin.getline(plain, BUFFER_SIZE);

		// Encrypt
		encrypted = encrypt(encrypted, plain);

		// Output
		cout << encrypted << endl;

		delete[] plain;

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

char * encrypt(char * encryptedText, const char * plaintext)
{
	size_t length = strlen(plaintext);
	char* buffer = new char[length + 1];
	buffer[length] = 0;
	
	for (int i = 0; i < length; i++) {
		char c = tolower(plaintext[i]);
		
		const char* offset = strchr(ALPHABET, c);
		ptrdiff_t index = offset - ALPHABET;
		
		if (index >= 0)
			buffer[i] = CIPHER_KEY[index];
		else
			buffer[i] = plaintext[i];
	}

	encryptedText = buffer;
	return encryptedText;
}
