/**********************************************************************
*
* @file		roulette.cpp
* @brief	Contains the definition of class Roulette
* @version	v1.01f00
* @date		5. Jul. 2020
* @author	Martin Moya
*
**********************************************************************/
#include "roulette.hpp"
#include "roulette_bets.hpp"

Roulette::Roulette(int roulette_verbose) : verbose(roulette_verbose)
{
	engine = std::mt19937(seed());
	rouletteGenerator = std::uniform_int_distribution<int>(MIN_ROULETTE_NUMBER, 
			MAX_ROULETTE_NUMBER);
}

void Roulette::roll()
{
	int random_number = rouletteGenerator(engine);
	RouletteBets::resetResult();
	RouletteBets::setResult(random_number);	
	if(verbose){
		RouletteBets::printResult();
	}
}
