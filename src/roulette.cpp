#include "roulette.hpp"
#include "roulette_bets.hpp"

Roulette::Roulette(int roulette_verbose) : verbose(roulette_verbose)
{
	gen = std::mt19937(rd());
	rouletteGenerator = std::uniform_int_distribution<int>(0, 36);
}

void Roulette::roll()
{
	int random_number = rouletteGenerator(gen);
	RouletteBets::resetResult();
	RouletteBets::setResult(random_number);	
	if(verbose)
		RouletteBets::printResult();
}
