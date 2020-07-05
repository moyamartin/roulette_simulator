#include <player.hpp>
#include <iostream>

Player::Player(std::string name, std::string table_bet)
{
	this->table_bet = table_bet;
	this->name = name;
	updateCurrentBet();
	balance = 0;
}

Player::~Player()
{
}

std::string Player::getTableBet()
{
	return table_bet;
}

void Player::resetBets()
{
	bets = {1, 2, 3, 4};
}

void Player::showStats()
{
	std::cout << name << " ------- STATS\n";
	std::cout << "Table Bet: "  << table_bet << "\n";
	std::cout << "Bets list: ";
	for(std::list<int>::iterator it = bets.begin(); it != bets.end(); 
			++it) {
		std::cout << *it << "\t";
	}
	std::cout << "\n" << "Balance: " << balance << "\n" << std::endl;
}

void Player::updateCurrentBet()
{
	current_bet = bets.front() + bets.back();
	if(current_bet > 4000) { 
		resetBets();
		updateCurrentBet();
	}
}

void Player::updateStats(int win, int debug)
{
	if(win) {
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
	if(debug)
		showStats();

}
