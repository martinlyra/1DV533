//-----------------------------------------------------------------------
// Object: Task 5 - Sum numbers stored in a file
//-----------------------------------------------------------------------
// File: SMSFilter.cpp
// Summary: 
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-11:	File created
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Constants
const char* TARGET_FILE_NAME = "smslog_eng.txt";

const int MESSAGE_NUMBER_LENGTH = 11 + 1;
const int MESSAGE_DATE_LENGTH = 16 + 1;
const int MESSAGE_STRING_LENGTH = 255 + 1;

// Structs
struct SMSMessage {
	char sender[MESSAGE_NUMBER_LENGTH];
	char receiver[MESSAGE_NUMBER_LENGTH];
	char timestamp[MESSAGE_DATE_LENGTH];
	char message[MESSAGE_STRING_LENGTH];
};

// Prototype
bool senderFilter(const char* logFileName, const char* resultFileName, const char* sender);

int main() {
	senderFilter(TARGET_FILE_NAME, "filtered_sms.txt", "0702-235689");

	cout << "\nPress any key to continue...\n";
	cin.get();
	return 0;
}

bool senderFilter(const char * logFileName, const char * resultFileName, const char * sender)
{
	ifstream log(logFileName, ios::in);

	if (log.fail()) {
		log.close();
		cout << "Failed to open the file " << logFileName << "!\n";
		return false;
	}

	vector<SMSMessage> messages;

	SMSMessage message;
	while (log.peek() != EOF) {
		log.getline(message.sender, MESSAGE_NUMBER_LENGTH);
		log.getline(message.receiver, MESSAGE_NUMBER_LENGTH);
		log.getline(message.timestamp, MESSAGE_DATE_LENGTH);
		log.getline(message.message, MESSAGE_STRING_LENGTH);

		messages.push_back(message);
	}

	ofstream result(resultFileName);

	if (result.fail()) {
		cout << "Task succesful, but couldn't open and write to the file " << resultFileName << "!\n";
		return false;
	}

	for (auto message : messages) {
		if (strcmp(message.sender, sender) == 0) {
			result << message.sender << endl
				<< message.receiver << endl
				<< message.timestamp << endl
				<< message.message << endl
				<< endl;
		}
	}

	cout << "Task successful! Results saved to file " << resultFileName << "!\n";

	result.close();
	log.close();

	return true;
}
