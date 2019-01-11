//-----------------------------------------------------------------------
// Object: Task 3 - Filter logged data from specific point from others
//-----------------------------------------------------------------------
// File: SensorLogger.cpp
// Summary: This program loads results from the log file then filters the
// data based on whom it came from, in this case; 'A' point.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-10:	File created
//-----------------------------------------------------------------------

// This makes Windows (Visual) shut up about "insecure methods" like asctime
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

// Constants
const char* TARGET_FILE_NAME = "timelog.dat";

// Structs
struct DataRecord {
	char logger;
	double temperature;
	time_t localTime;
};

int main() {
	vector<DataRecord> records;

	ifstream file;
	file.open(TARGET_FILE_NAME, ios::in | ios::binary);

	if (file.fail())
		cout << "Failed to open the file " << TARGET_FILE_NAME << "!\n";

	else {
		DataRecord record;
		while (file.read((char*)&record, sizeof(record)))
			records.push_back(record);

		ofstream out("A.txt", ios::out);
		out << "Data A\n";

		for (DataRecord record : records) {
			if (record.logger == 'A') {
				out << setprecision(1) << fixed << setw(5)
					<< record.temperature << ", "
					<< asctime(localtime(&record.localTime));
			}
		}

		out.close();

		cout << "File " << TARGET_FILE_NAME 
			<< " has been succesfully read, filtered data has been saved to A.txt\n";
	}

	file.close();

	cout << "\nPress any key to continue...\n";
	cin.get();
	return 0;
}