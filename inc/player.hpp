#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <iterator>
#include <string>

class Player
{
private:
	std::string name, table_bet;
	std::list<int> bets = {1, 2, 3, 4};
	int current_bet, balance;

	void updateCurrentBet();
	void resetBets();
	void showStats(int win);

public:
	/* ctor */
	Player(std::string name, std::string table_bet);
	/* dtor */
	~Player();
		
	std::string getTableBet();
	int getBalance();
	void updateStats(int win);
};

#endif
