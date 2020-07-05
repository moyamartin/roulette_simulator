#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include <string>
#include <roulette_bets.hpp>

class Player
{
public:
	Player(std::string name, simple_bets_t table_bet);
	simple_bets_t getTableBet();
	int getBalance();
	void updateStats();

private:
	void updateCurrentBet();
	void resetBets();
	void showStats();

	simple_bets_t table_bet;
	std::string name;
	std::list<int> bets = {1, 2, 3, 4};
	int current_bet, balance;
};

#endif // PLAYER_HPP
