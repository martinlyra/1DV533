//-----------------------------------------------------------------------
// Object: Task 2 - Correct the logical error in a coin-flip program
//-----------------------------------------------------------------------
// File: CoinFlip.cpp
// Summary: This program flips a coin 10 times and holds count on which-
// ever side it landed on in every flip.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	File created by Martin	
//-----------------------------------------------------------------------
#include <iostream>
#include <ctime>
using namespace std;

// Constants
enum Coin { Tails, Heads };

// Entry point
int main()
{
	int frequency0 = 0, frequency1 = 0;
	Coin face;
	
	srand(time(0)); // # srand(time(0)) should be called only once to guarantee unique numbers

	for (int counter = 1; counter <= 10; ++counter)
	{
		face = Coin(rand() % 2);
		
		switch (face)
		{
		case Tails: ++frequency0;
			break;
		case Heads: ++frequency1;
			break;
		}
	}
	cout << "Tails were rolled " << frequency0 << " times" << endl;
	cout << "Heads were rolled " << frequency1 << " times" << endl;
	
	cin.get();
	return 0;
}