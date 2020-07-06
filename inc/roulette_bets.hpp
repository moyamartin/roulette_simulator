#ifndef ROULETTE_BETS_HPP
#define ROULETTE_BETS_HPP

#include <map>
#include <string>


class RouletteBets 
{
public:
	enum simple_bets_t { EVEN, ODD, RED, BLACK, MAJOR, MINOR, VALUE };
	static void resetResult();
	static void printResult();
	static void setResult(int value);
	static int getResult(simple_bets_t bet);
	static std::string printBet(simple_bets_t value);

private:
	static std::map<simple_bets_t, int> simple_bets_result;
};

#endif // ROULETTE_BETS_HPP
