/**********************************************************************
*
* @file		player.hpp
* @brief	Contains the definition of class Player
* @version	v1.01f00
* @date		5. Jul. 2020
* @author	Martin Moya
*
**********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include <string>

#include "roulette_bets.hpp"

/**
 *
 * @class	Player
 * @brief	The Player class is used to model a player in
 * 			the simulator. 
 *
 * 			It is in charge of creating, handling and updating
 * 			the bets list mentioned in the problem's statement as well as the
 * 			player's balance.
 *
 */
class Player
{
public:
	/**
	 * @fn Player
	 * @brief Player's constructor
	 *
	 * The Player's constructor sets the bets list to {1, 2, 3, 4} and
	 * current_bet to 5 (sum of bets[0] and bets[1])
	 *
	 * @param name User's name.
	 * @param table_bat User's simple bet (RED, BLACK, EVEN, ODD, HIGH, LOW)
	 * @param player_verbose Enables player log's output
	 *
	 * @see RouletteBets
	 */
	Player(std::string name, RouletteBets::simple_bets_t table_bet, 
			int player_verbose);

	/**
	 *	@fn getTableBet()
	 *	@brief Returns the Player's simple bet
	 *
	 *	@see RouletteBets
	 *	@returns table_bet
	 */
	RouletteBets::simple_bets_t getTableBet();

	/**
	 * @fn getBalance
	 * @brief Returns the current balance of the player.
	 *
	 * @returns balance
	 */
	int getBalance();

	/**
	 * @fn updateStats
	 *
	 * @brief Updates the current player stats.
	 *
	 * If the player has won then it adds the current_bet to balance and
	 * appends it to the end of bets list. Otherwise, it deletes the first and
	 * last element of bets list and extracts the current_bet to balance
	 *
	 * @see updateCurrentBet()
	 * @returns None
	 */
	void updateStats();

	/**
	 * @fn showStats
	 *
	 * @brief Prints the current stats of the player
	 *
	 * @returns None
	 */
	void showStats();

private:
	/**
	 * @fn updateCurrentBet()
	 * @brief Updates current_bet
	 *
	 * current_bet is updated by adding the first and the last index
	 * of bets list. If the current_bet is greater than MAX_BET or lower than
	 * MIN_BET then it resets the bets_list
	 *
	 * @see resetBets()
	 * @returns None
	 */
	void updateCurrentBet();

	/**
	 * @fn resetBets
	 * @brief Resets bets list to {1, 2, 3, 4}
	 * @returns None
	 */
	void resetBets();

	/**
	 * @var table_bet
	 * @brief holds Player's simple bet
	 *
	 * @see RouletteBets
	 */
	RouletteBets::simple_bets_t table_bet;

	/**
	 * @var name
	 * @brief hold Player's name
	 */
	std::string name;

	/**
	 * @var bets
	 * @brief holds the Player's available bets
	 *
	 * The bets list is implemented as a double linked list because although we
	 * only care about the first and last index, we need to keep track of all
	 * the available bets. A double list allows us to pop the first and last
	 * input quickly [Player losses] (O(1) complexity) and add an element
	 * [Player wins] with the same complexity (O(1))
	 */
	std::list<int> bets;

	/**
	 *	@var current_bet
	 *	@brief holds the Player's current bet
	 */
	int current_bet;

	/**
	 * @var balance
	 * @brief holds the Player's current balance
	 */
	int balance;

	/**
	 * @var verbose
	 * @brief enables Player's verbosity
	 *
	 * If set to 1 (true) the player prints to cout the current stats
	 */
	int verbose;

	/**
	 * @var MAX_BET 
	 * @brief Holds table's maximum bet
	 */
	static constexpr int MAX_BET = 4000;

	/**
	 * @var MIN_BET
	 * @brief Holds table's minimum bet
	 */
	static constexpr int MIN_BET = 5;
};

#endif // PLAYER_HPP
