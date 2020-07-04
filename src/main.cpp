//----------------------------------------------------
// Roulette in C++
//----------------------------------------------------
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Set as CONSTANT for Random number generation
	int const MIN_NUMBER = 1, MAX_NUMBER = 36;
	int number;
	int random;

	double bet, winnings = 0;

	// Use arrays for player decision
	char gametype[2];
	char evenodd[2];

	// Main Menu Screen
	cout << "Welcome to ROULETTE\n\n";
	cout << "How much would you like to bet?\n"; cin >> bet;

	cout << "Would you like to bet on a specific number (N) or on odd/even (O)? "; cin >> gametype;

	// User selects a specific number to place bet on
	if(gametype == "n")
	{
		cout << "What number would you like to bet on? "; cin >> number;
		if(number == 00)
			number = 37;

		srand(time(NULL));
		random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

		cout << "The ball landed on " << random << "\n";

		// Lose
		if(number != random)
		{
			cout << "You lose $" << bet << "\n";
			winnings -= bet;
		}
		// Win
		else
		{
			cout << "You win $" << 35*bet << endl;
			winnings += 35*bet;
		}
	}

	// User selects even or odd
	if(gametype == "o")
	{

		cout << "Would you like to bet on even (E) or odd (O)? "; cin >> evenodd;

		srand(time(NULL));
		random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
		cout << "The ball landed on " << random << endl;

		// selects EVEN
		if(evenodd == "E")
		{
			// even win
			if(2*(random/2) == random)
			{
				cout << "You win $" << bet << endl;
				winnings += bet;
			}
			// even lose
			else
			{
				cout << "You lose $" << bet << endl;
				winnings -= bet;
			}
		}

		// selects ODD
		if(evenodd == "O")
		{
			// odd lose
			if(2*(random/2) == random)
			{
				cout << "You lose $" << bet << endl;
				winnings -= bet;
			}
			// odd win
			else
			{
				cout << "You win $" << bet << endl;
				winnings += bet;
			}
		}
	}

	// Final Results
	cout << "You won a total of $" << winnings << "\n";
}
