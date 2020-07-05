#include <iostream>
#include <roulette.hpp>

Roulette::Roulette()
{
	gen = std::mt19937(rd());
	// Uniform distribution between 0 and 36, the max number a Roulette can
	// output () -> [inclusive, inclusive]
	rouletteGenerator = std::uniform_int_distribution<int>(0, 36);
}

Roulette::~Roulette()
{
	for(std::map<std::string, int>::iterator it = roulette_result.begin();
			it != roulette_result.end(); it++) {
		roulette_result.erase(it->first);
	}
}

void Roulette::resetResult()
{
	for(std::map<std::string, int>::iterator it = roulette_result.begin();
			it != roulette_result.end(); it++) {
		it->second = 0;
	}
}

void Roulette::printResult()
{
	std::cout << "------- ROULETTE RESULT" << std::endl;
	for(std::map<std::string, int>::iterator it = roulette_result.begin();
			it != roulette_result.end(); it++) {
		std::cout << it->first << ": " << it->second << "\t";
	}
	std::cout<<"\n"<< std::endl;

}

int Roulette::getPlayerBetResult(std::string table_bet)
{
	return roulette_result[table_bet];
}

void Roulette::roll(int debug)
{

	int random_number = rouletteGenerator(gen);
	resetResult();
	roulette_result["value"] = random_number;
	if(random_number > 0) {
		roulette_result["zero"] = 0;
		roulette_result["even"] = (random_number%2 == 0) ? 1 : 0;
		roulette_result["odd"] = !roulette_result["even"];
		if(random_number < 19) {
			roulette_result["minor"] = 1;
			if(random_number <= 10) {
				roulette_result["black"] = roulette_result["even"];
			} else {
				roulette_result["black"] = roulette_result["odd"];
			}
		} else { 
			roulette_result["minor"] = 0;
			if(random_number <= 28) {
				roulette_result["black"] = roulette_result["even"];
			} else {
				roulette_result["black"] = roulette_result["odd"];
			}
		}
		roulette_result["major"] = !roulette_result["minor"];
		roulette_result["red"] = !roulette_result["black"];
	}
		printResult();
}
