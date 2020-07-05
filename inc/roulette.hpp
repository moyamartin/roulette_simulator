#ifndef ROULETTE_H
#define ROULETTE_H

#include <map>
#include <random>
#include <string>

class Roulette 
{
private:
	std::map<std::string, int> roulette_result = {
		{"even",	0},
		{"odd",		0},
		{"red",		0},
		{"black",	0},
		{"major",	0},
		{"minor",	0},
		{"value",	0}
	};

	/* 
	 * Non-deterministic 32-bit seed
	 * This will cause that everytime we run this program
	 * It will give different results from our Roulette
	 */
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<int> rouletteGenerator;
	
	void printResult();
	void resetResult();

public:
	Roulette();
	~Roulette();

	std::map<std::string, int> roll(int debug);
};

#endif
