/**********************************************************************
*
* @file		roulette_bets.hpp
* @brief	Contains the definition of Roulette's type of simple bets
* @version	v1.01f00
* @date		5. Jul. 2020
* @author	Martin Moya
*
**********************************************************************/
#ifndef ROULETTE_BETS_HPP
#define ROULETTE_BETS_HPP

#include <map>
#include <string>

/**
 *
 * @class	RouletteBets
 * @brief	The RouletteBets class is used to model the Roulette's simple bets
 *
 */
class RouletteBets 
{
public:
	/**
	 * @enum simple_bets_t
	 * @brief simple_bets_t is used to specify what type of simple bet is the
	 * Roulette's output and Player's bet
	 */
	enum simple_bets_t { 
		EVEN, 		/**< Roulette's output is even */
		ODD,		/**< Roulette's output is odd */
		RED, 		/**< Roulette's output is red */
		BLACK, 		/**< Roulette's output is black */
		HIGH,		/**< Roulette's output is high */
		LOW, 		/**< Roulette's output is low */
		VALUE 		/**< Roulette's output is value */
	};

	/**
	 * @fn resetResult()
	 * @brief Reset each index of simple_bets_result to 0
	 *
	 * @returns None
	 */
	static void resetResult();

	/**
	 * @fn printResult()
	 * @brief prints to cout the values of simple_bets_result
	 *
	 * @returns None
	 */
	static void printResult();

	/**
	 * @fn setResult()
	 * @brief Updates simple_bets_result according to the input
	 * @param  value
	 *
	 * @returns None
	 */
	static void setResult(int value);

	/**
	 * @fn getResult()
	 *
	 * @brief returns if the simple bet passed as argument has won or not
	 *
	 * @param bet
	 *
	 * @returns simple_bets_result[bet] which is 1 if the bet has won, otherwise
	 * is 0
	 */
	static int getResult(simple_bets_t bet);

	/**
	 * @fn printBet()
	 *
	 * @brief Returns a simple_bets_t enum value as string given a enum as
	 * paramenter
	 *
	 * @param value
	 *
	 * @return enum parsed as std::string
	 */
	static std::string printBet(simple_bets_t value);

private:
	/**
	 * @var simple_bets_result
	 *
	 * @brief Map containing the results of the Roulette
	 *
	 * The results of the Roulette's simple bets, after a random number has been 
	 * generated, is stored inside this map. This data structure is useful for
	 * this case given that the results are calculated only once by setResult() 
	 * and then the Players can access to it to check if they won or not, 
	 * using getResult() and passing the Player's simple bet as argument
	 */
	static std::map<simple_bets_t, int> simple_bets_result;
};

#endif // ROULETTE_BETS_HPP
