#include <iostream>

#include "player.hpp"

Player::Player(std::string player_name, 
		RouletteBets::simple_bets_t player_table_bet, int player_verbose) :
	 table_bet(player_table_bet), name(player_name), balance(0), 
	 verbose(player_verbose)
{
	resetBets();
	updateCurrentBet();
	if(verbose)
		showStats();
}

RouletteBets::simple_bets_t Player::getTableBet()
{
	return table_bet;
}

void Player::resetBets()
{
	bets = {1, 2, 3, 4};
}

void Player::showStats()
{
	std::cout << "[PLAYER LOG] ---------- " << name  << " STATS" 
		<< std::endl;
	if(RouletteBets::getResult(table_bet) == 1) {
		std::cout << "WON" << std::endl;
	} else if(RouletteBets::getResult(table_bet) == 0) {
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
	std::cout << "[PLAYER LOG ENDS] ----------" << std::endl;
}

void Player::updateCurrentBet()
{
	current_bet = bets.front() + bets.back();
	if(current_bet > MAX_BET || current_bet < MIN_BET) { 
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
	if(verbose)
		showStats();
	updateCurrentBet();
}
