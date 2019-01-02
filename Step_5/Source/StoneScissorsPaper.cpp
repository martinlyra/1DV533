//-----------------------------------------------------------------------
// Object: Task 4 - Write a Stone-Scissor-Paper game
//-----------------------------------------------------------------------
// File: Time.cpp
// Summary: This program takes several numbers until a non-number is 
// given, then prints the output.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	Created by Martin	
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const int SCORE_LIMIT = 4;

enum Gesture {
	START,

	STONE,
	SCISSOR,
	PAPER,

	END
};

// Prototypes
const char* gestureToString(Gesture);
Gesture playerPickGesture();
bool endOfGame(int,int);
void playGame();
int pickWinner(Gesture, Gesture);

// Entry point
int main() {
	cout << "Stone-Scissor-Paper\n";
	cout << "===================\n";

	char answer = 'y';
	while (tolower(answer) == 'y') {
		playGame();

		cout << "Would you like to play again? (y/n):";
		cin >> answer;
	}

	return 0;
}

// const char* gestureToString(Gesture)
//
// Returns a string befitting given Gesture value
const char* gestureToString(Gesture gesture) {
	switch (gesture) {
	case STONE: return "Stone";
	case SCISSOR: return "Scissors";
	case PAPER: return "Paper";
	default: return "Unknown";
	}
}

// Gesture playerPickGesture()
//
// Function for asking the human player their choice of a hand gesture
Gesture playerPickGesture()
{
	int choice = 0;

	while (!(cin >> choice) || !(Gesture::START < choice && choice < Gesture::END)) {
		cout << "Invaild input, please try again!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return Gesture(choice);
}

// bool endOfGame(int, int)
//
// Checks whether the game is over or not
bool endOfGame(int scoreA, int scoreB) {
	return scoreA >= SCORE_LIMIT || scoreB >= SCORE_LIMIT;
}

// void playGame()
//
// Plays one full game of Rock-Scissor-Paper
void playGame()
{
	int playerScore = 0;
	int computerScore = 0;
	Gesture playerGesture, computerGesture;

	int counter = 0;
	while (!endOfGame(playerScore, computerScore)) {
		// Print round divider
		cout << "----- Round " 
			<< setw(2) << counter 
			<< " ( YOU: " 
			<< setw(2) << playerScore << " - " 
			<< setw(2) << computerScore << " :COM ) -----\n";

		// Pick gestures!
		cout << "Pick your gesture; (Stone: 1, Scissors: 2, Paper: 3): ";
		playerGesture = playerPickGesture();

		srand(time(NULL));
		computerGesture = Gesture(rand() % 3 + 1);
		cout << "The computer picks; " << gestureToString(computerGesture) << '\n\n';

		switch (pickWinner(playerGesture, computerGesture))
		{
		case 1: {
			cout << "You won the round!\n";
			playerScore++; 
			break;
		}
		case 2: {
			cout << "Computer won the round!\n";
			computerScore++; 
			break;
		}
		default: {
			cout << "Stalemate!\n";
			break;
		}
		}
		
		//cout << "Score: You vs. Com (" << playerScore << " - " << computerScore << ")\n";
		cout << endl;
		counter++;
	}

	cout << "\nGame over: First player has reached " << SCORE_LIMIT << endl;
	cout << ((playerScore > computerScore) ? "You have" : "The computer has")
		<< " won the game with (" << playerScore << " - " << computerScore << ")!\n\n";
}

// int pickWinner(Gesture,Gesture)
//
// Compares two gestures to pick a winning side. 
// Returns 0 if the gestures are equal and no one won.
// Returns 1 if player A won the round
// Returns 2 if player B won the round
int pickWinner(Gesture playerA, Gesture playerB) {
	int diff = playerB - playerA;

	return (3 + diff) % 3;
}