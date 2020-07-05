#include <iostream>
#include <roulette.hpp>
#include <player.hpp>

int main()
{
	std::cout << "Bienvenido a ROULETTE++\n\n";

	Roulette *roulette = new Roulette();
	Player *player = new Player("Player A", "red");

	for(int i = 0; i < 100; i++) {
		roulette->roll(1);
		int won = roulette->getPlayerBetResult(player->getTableBet());
		player->updateStats(won, 1);
	}
}
