/**********************************************************************
*
* @file		roulette.hpp
* @brief	Contains the definition of class Roulette
* @version	v1.01f00
* @date		5. Jul. 2020
* @author	Martin Moya
*
**********************************************************************/
#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include <random>

/**
 * @class	Roulette
 * @brief	The Roulette class models a roulette that generates random numbers
 */
class Roulette 
{
public:
	/**
	 * @fn Roulette
	 *
	 * @brief Roulette's constructors
	 *
	 * Instantiates the random number generator for the Roulette's output
	 *
	 * @param roulette_verbose Enables Roulette's verbosity
	 */
	Roulette(int roulette_verbose);

	/**
	 * @fn roll
	 *
	 * @brief Generates a random number and updates the RouletteBets result
	 *
	 * @see RouletteBets
	 *
	 * @returns None
	 */
	void roll();

private:
	/**
	 * @var seed
	 * @brief uniformly-distributed integer random number generator used as seed
	 *
	 * This assure us that every time that the app is ran the random numbers are
	 * not repeated. i.e. if the app is ran and a sequence of rolls is not
	 * repetead, the next time the app is ran this sequence is NOT repeated
	 * again
	 *
	 * @see <a href="http://www.cplusplus.com/reference/random/random_device/">
	 * random_device</a>
	 */
	std::random_device seed;

	/**
	 * @var engine
	 * @brief A Mersenne Twister pseudo-random generator used by
	 * uniform_int_distribution
	 *
	 * @see <a href="http://www.cplusplus.com/reference/random/mt19937/">
	 * mt19937</a>
	 */
	std::mt19937 engine;

	/**
	 * @var rouletteGenerator
	 * @brief Generates the random output of the Roulette's
	 *
	 * @see 
	 * <a href="https://en.cppreference.com/w/cpp/numeric/random/
	 * uniform_int_distribution">
	 * uniform_int_distribution</a>
	 */
	std::uniform_int_distribution<int> rouletteGenerator;

	/**
	 * @var verbose
	 * @brief Enables Roulette's verbosity
	 *
	 * Everytime that a number is rolled it prints the result
	 */
	int verbose;

	/**
	 * @var MAX_ROULETTE_NUMBER
	 * @brief Sets the maximum number of the roulette
	 */
	static constexpr int MAX_ROULETTE_NUMBER = 36;

	/**
	 * @var MIN_ROULETTE_NUMBER
	 * @brief Sets the minimum number of the roulette
	 */
	static constexpr int MIN_ROULETTE_NUMBER = 0;
};

#endif // ROULETTE_HPP
