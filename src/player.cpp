#include <iostream>

#include <player.hpp>


Player::Player(std::string player_name, simple_bets_t player_table_bet) :
	 table_bet(player_table_bet), name(player_name), balance(0)
{
	resetBets();
	updateCurrentBet();
}

simple_bets_t Player::getTableBet()
{
	return table_bet;
}

void Player::resetBets()
{
	bets = {1, 2, 3, 4};
}

void Player::showStats()
{
	std::cout << "PLAYER " << name  << "\t STATS: ";
	if(RouletteBets::getResult(table_bet)) {
		std::cout << "WON" << std::endl;
	} else { 
		std::cout << "LOST" << std::endl;
	}
	std::cout << "Current bet: " << current_bet << std::endl;
	std::cout << "Table Bet: "  << RouletteBets::printBet(table_bet) 
		<< std::endl;
	std::cout << "Bets list: ";
	for(std::list<int>::iterator it = bets.begin(); it != bets.end(); 
			++it) {
		std::cout << *it << "\t";
	}
	std::cout << "Balance: " << balance << std::endl;
	std::cout << "PLAYER ----------" << std::endl;
}

void Player::updateCurrentBet()
{
	current_bet = bets.front() + bets.back();
	if(current_bet > MAX_BET) { 
		resetBets();
		updateCurrentBet();
	}
}

int Player::getBalance()
{
	return balance;
}

void Player::updateStats()
{
	if(RouletteBets::getResult(table_bet)) {
		balance += current_bet;
		bets.push_back(current_bet);
	} else {
		balance -= current_bet;
		if(bets.size() > 2){
			bets.pop_front();
			bets.pop_back();
		} else {
			resetBets();
		}
	}
	updateCurrentBet();
	showStats();
}
