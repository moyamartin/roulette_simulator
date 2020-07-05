#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include <string>

#include "roulette_bets.hpp"

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
	std::list<int> bets;
	int current_bet, balance;
	static constexpr int MAX_BET = 4000;
};

#endif // PLAYER_HPP
