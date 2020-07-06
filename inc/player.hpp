#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include <string>

#include "roulette_bets.hpp"

class Player
{
public:
	Player(std::string name, RouletteBets::simple_bets_t table_bet, 
			int player_verbose);
	RouletteBets::simple_bets_t getTableBet();
	int getBalance();
	void updateStats();
	void showStats();

private:
	void updateCurrentBet();
	void resetBets();

	RouletteBets::simple_bets_t table_bet;
	std::string name;
	std::list<int> bets;
	int current_bet, balance, verbose;
	static constexpr int MAX_BET = 4000;
};

#endif // PLAYER_HPP
