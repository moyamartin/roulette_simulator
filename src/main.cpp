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
	const int MAX_NUMBER = 37;
	int random_number;

//	double bet, winnings = 0;

	// Use arrays for player decision
	char gametype;

	// Main Menu Screen
	cout << "Bienvenido a ROULETTE++\n\n";
	cout << "Seleccione una simple apuesta: par (p), impar (i), rojos (r), "
		"negros (r), mayores(M), menores(m)" << endl;
	cin >> gametype;

	/* srand avoids to generate always the same number */
	srand(time(nullptr));
	for(int i = 0; i < 10000; i++) {
		random_number = rand() ;
		cout << random_number << endl;
		if(!random_number%2) {
			cout << "es par" << endl;
		} else { 
			cout << "es impar" << endl;
		}

		if(random_number >= 18) {
			cout << "Es mayor" << endl;
		} else {
			cout << "Es menor" << endl;
		}

	}

	/*
	// User selects a specific number to place bet on
	if(!gametype.compare("n"))
	{
		cout << "What number would you like to bet on? "; cin >> number;
		if(number == 00)
			number = 37;

		srand(time(NULL));
		random = rand() %MAX_NUMBER + 1;

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
			cout << "You win $" << 35.0*bet << endl;
			winnings += 35*bet;
		}
	}

	// User selects even or odd
	if(!gametype.compare("o"))
	{

		cout << "Would you like to bet on even (E) or odd (O)? "; cin >> evenodd;

		srand(time(NULL));
		random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
		cout << "The ball landed on " << random << endl;

		// selects EVEN
		if(!evenodd.compare('E')) {
			// even win
			if(random%2 == 0) {
				cout << "You win $" << bet << endl;
				winnings += bet;
			}
			// even lose
			else {
				cout << "You lose $" << bet << endl;
				winnings -= bet;
			}
		}

		// selects ODD
		if(evenodd.compare('O')){
			// odd lose
			if(random%2 == 0) {
				cout << "You lose $" << bet << endl;
				winnings -= bet;
			} else {
				cout << "You win $" << bet << endl;
				winnings += bet;
			}
		}
	}

	// Final Results
	cout << "You won a total of $" << winnings << "\n";
	*/
}
