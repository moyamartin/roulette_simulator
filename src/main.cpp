#include <iostream>
#include <roulette.hpp>
#include <player.hpp>

int main()
{
	std::cout << "Bienvenido a ROULETTE++\n\n";

	Roulette *roulette = new Roulette();
	int final_balance = 0;
	std::array<Player*, 6> players = {
		new Player("Player A", "red"),
		new Player("Player B", "black"),
		new Player("Player C", "major"),
		new Player("Placer D", "minor"),
		new Player("Player E", "even"),
		new Player("Player F", "odd")
	};

	for(int i = 0; i < 10; i++) {
		final_balance = 0;
		std::cout << "------------ ROLL NUMBER: " << i + 1 << std::endl;
		roulette->roll(1);
		for(Player *player : players) {
			player->updateStats(roulette->getPlayerBetResult(
						player->getTableBet()));
			final_balance += player->getBalance();
		}
		std::cout << "------------ TOTAL BALANCE: " << final_balance << std::endl;
		std::cout << "\n\n" << std::endl;
	}
}
