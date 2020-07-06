#include <iostream>

#include "roulette_bets.hpp"

std::map<simple_bets_t, int> RouletteBets::simple_bets_result = {
	{EVEN, 0},
	{ODD, 0},
	{RED, 0},
	{BLACK, 0},
	{MAJOR, 0},
	{MINOR, 0},
	{VALUE, 0}
};

int RouletteBets::getResult(simple_bets_t value)
{
	return simple_bets_result[value];
}

void RouletteBets::setResult(int random_number)
{
	simple_bets_result[VALUE] = random_number;
	if(random_number > 0) {
		simple_bets_result[EVEN] = (random_number%2 == 0) ? 1 : 0;
		simple_bets_result[ODD] = !simple_bets_result[EVEN];
		if(random_number < 19) {
			simple_bets_result[MINOR] = 1;
			if(random_number <= 10) {
				simple_bets_result[BLACK] = simple_bets_result[EVEN];
			} else {
				simple_bets_result[BLACK] = simple_bets_result[ODD];
			}
		} else { 
			simple_bets_result[MINOR] = 0;
			if(random_number <= 28) {
				simple_bets_result[BLACK] = simple_bets_result[EVEN];
			} else {
				simple_bets_result[BLACK] = simple_bets_result[ODD];
			}
		}
		simple_bets_result[MAJOR] = !simple_bets_result[MINOR];
		simple_bets_result[RED] = !simple_bets_result[BLACK];
	}
}

void RouletteBets::resetResult()
{
	for(std::map<simple_bets_t, int>::iterator it = 
			simple_bets_result.begin();
			it != simple_bets_result.end(); it++) {
		it->second = 0;
	}
}

void RouletteBets::printResult()
{
	std::cout << "[ROULETTE LOG] ------- RESULT" << std::endl;
	for(std::map<simple_bets_t, int>::iterator it = 
			simple_bets_result.begin();
			it != simple_bets_result.end(); it++) {
		std::cout << "\t" << printBet(it->first) << ": " << it->second << "\t";
	}
	std::cout << std::endl <<  "[ROULETTE LOG ENDS] --------------" << std::endl;
}

std::string RouletteBets::printBet(simple_bets_t value)
{
	switch(value) {
		case EVEN:	return "EVEN";
		case ODD:	return "ODD";
		case RED:	return "RED";
		case BLACK:	return "BLACK";
		case MAJOR:	return "MAJOR";
		case MINOR:	return "MINOR";
		case VALUE:	
		default:	return "VALUE";
	}
}
