#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include <random>

class Roulette 
{
public:
	Roulette();
	void roll();

private:

	/* 
	 * Non-deterministic 32-bit seed
	 * This will cause that everytime we run this program
	 * It will give different results from our Roulette
	 */
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<int> rouletteGenerator;
};

#endif // ROULETTE_HPP
