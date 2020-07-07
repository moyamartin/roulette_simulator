/**********************************************************************
*
* @file		player.cpp
* @brief	Contains the definition of class Player
* @version	v1.01f00
* @date		5. Jul. 2020
* @author	Martin Moya
*
**********************************************************************/

#include <iostream>

#include "player.hpp"

Player::Player(std::string player_name, 
		RouletteBets::simple_bets_t player_table_bet, int player_verbose) :
	 table_bet(player_table_bet), name(player_name), balance(0), 
	 verbose(player_verbose)
{
	resetBets();
	updateCurrentBet();
	if(verbose){
		showStats();
	}
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
	// Computes the new bet adding the front and the back of the bets list
	current_bet = bets.front() + bets.back();
	// If current bet exceeds Table's limits then reset the bets list
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
	// Check if user has won by checking the RouletteResults dictionary
	if(RouletteBets::getResult(table_bet)) {
		/* User Won */
		// Increases the balance by the current_bet
		balance += current_bet;			
		// Pushes the current bet to the end of the list
		bets.push_back(current_bet);	
	} else {
		/* User Lost */
		// Decreases the balance by the current_bet
		balance -= current_bet;
		// Check if the bets list has elements to pop at the front and the back
		if(bets.size() > 2){
			bets.pop_front();
			bets.pop_back();
		} else {
			// If list ran out of elements to pop, then reset it
			resetBets();
		}
	}
	// If verbose then show stats
	if(verbose){
		showStats();
	}
	updateCurrentBet();
}
