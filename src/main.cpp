#include <cstring>
#include <iostream>

#include "player.hpp"
#include "roulette.hpp"

int main(int argc, char* argv[])
{
	std::cout << "Welcome to ROULETTE++" << std::endl;

	time_t start, end, time_flag;
	int verbose = 0, plays = 10000;
	double time_taken;
	for(int i = 0; i < argc; i++){
		std::cout << argv[i] << std::endl;
		verbose = (!strcmp(argv[i], "-v")) ? 1 : 0;
		plays = (!strcmp(argv[i], "-p")) ? atoi(argv[i + 1]) : plays;
		time_flag = (!strcmp(argv[i], "-t")) ? 1 : 0;
	}

	Roulette *roulette = new Roulette(verbose);
	int final_balance = 0;
	std::array<Player*, 6> players = {
		new Player("Player A", RED, verbose),
		new Player("Player B", BLACK, verbose),
		new Player("Player C", MAJOR, verbose),
		new Player("Placer D", MINOR, verbose),
		new Player("Player E", EVEN, verbose),
		new Player("Player F", ODD, verbose)
	};

	for(int i = 0; i < plays; i++) {
		final_balance = 0;
		std::cout << "------------ ROLL NUMBER: " << i + 1 << std::endl;
		roulette->roll();
		for(Player *player : players) {
			player->updateStats();
			final_balance += player->getBalance();
		}
		std::cout << "------------ TOTAL BALANCE: " << final_balance << std::endl;
	}

}
