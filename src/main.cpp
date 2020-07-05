#include <iostream>
#include <roulette.hpp>
#include <player.hpp>

int main()
{
	std::cout << "Bienvenido a ROULETTE++\n\n";

	Roulette *roulette = new Roulette();
	int final_balance = 0;
	std::array<Player*, 6> players = {
		new Player("Player A", RED),
		new Player("Player B", BLACK),
		new Player("Player C", MAJOR),
		new Player("Placer D", MINOR),
		new Player("Player E", EVEN),
		new Player("Player F", ODD)
	};

	for(int i = 0; i < 10; i++) {
		final_balance = 0;
		std::cout << "------------ ROLL NUMBER: " << i + 1 << std::endl;
		roulette->roll();
		for(Player *player : players) {
			player->updateStats();
			final_balance += player->getBalance();
		}
		std::cout << "------------ TOTAL BALANCE: " << final_balance << std::endl;
		std::cout << "\n\n" << std::endl;
	}
}
