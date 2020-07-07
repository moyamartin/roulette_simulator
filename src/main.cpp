#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>

#include "player.hpp"
#include "roulette.hpp"

void printHelp();

int main(int argc, char* argv[])
{
	constexpr  char LOG_FILE_NAME[] = "log.txt";
	int verbose = 0, plays = 10000, final_balance = 0, time_flag = 0, 
		log_to_file = 0;
	std::streambuf *psbuf, *backup = std::cout.rdbuf();
	std::ofstream logfile;

	/* read the options passed to argv */
	for(int i = 0; i < argc; i++){
		// -v --> verbosity enabled
		if(!strcmp(argv[i], "-v")){
			verbose = 1;
		}
		// -p --> sets the number of cycles 
		// if the value is invalid it exits the app indicating to set a valid
		// number of cycles
		if(!strcmp(argv[i], "-p")) {
			plays = atoi(argv[i + 1]);
			if(plays == 0) {
				std::cout << "Set a valid number of cycles" << std::endl;
				return 0;
			}
		}
		// -t --> shows execution time
		if(!strcmp(argv[i], "-t")) {
			time_flag = 1;
		}
		// -f --> sends output to log.txt
		if(!strcmp(argv[i], "-f")) {
			log_to_file = 1;
		}
		// -h --> shows available options
		if(!strcmp(argv[i], "-h") || argc == 1) {
			printHelp();
			return 0;
		}
	}

	if(log_to_file) {
		logfile.open(LOG_FILE_NAME, std::ofstream::trunc);
		psbuf = logfile.rdbuf();
		std::cout.rdbuf(psbuf);
	}

	std::cout << "Welcome to ROULETTE++" << std::endl;

	// Creates instace of Roulette
	Roulette *roulette = new Roulette(verbose);
	// Creates an array of 6 players
	std::array<Player*, 6> players = {
		new Player("Player A", RouletteBets::RED, verbose),
		new Player("Player B", RouletteBets::BLACK, verbose),
		new Player("Player C", RouletteBets::HIGH, verbose),
		new Player("Player D", RouletteBets::LOW, verbose),
		new Player("Player E", RouletteBets::EVEN, verbose),
		new Player("Player F", RouletteBets::ODD, verbose)
	};

	auto t1 = std::chrono::high_resolution_clock::now();
	// Rolls the Roulette 'plays' times
	for(int i = 0; i < plays; i++) {
		final_balance = 0;
		std::cout << "------------ ROLL NUMBER: " << i + 1 << std::endl;
		// Rolls the number
		roulette->roll();
		// Update each player
		for(Player *player : players) {
			player->updateStats();
			// calculate the total balance
			final_balance += player->getBalance();
		}
		// Finally shows the total balance at each iteration
		std::cout << "------------ TOTAL BALANCE: " << final_balance << std::endl;
	}
	auto t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>
		( t2 - t1 ).count();
	if(time_flag){
		std::cout << "Execution time: " << duration << " uS"<< std::endl;
	}
	if(log_to_file){
		std::cout.rdbuf(backup);
		logfile.close();
	}
	
	return 0;
}

void printHelp()
{
	std::cout << "Welcome to ROULETTE++" << std::endl;
	std::cout << "by Martin Moya - 2020" << std::endl;
	std::cout << "Roulette++ is a casino roulette simulator which simulates"
		"N players on the same table with infinite money, making the same bet " 
		"on every roll" << std::endl;
	std::cout << "OPTIONS" << std::endl;
	std::cout << " \t-v \t\t\tenables verbosity, show players and roulette logs"
		<< std::endl;
	std::cout << " \t-p <number_of_plays> \t" 
		"sets the amount of plays to simulate. "
		"If ommited the number of plays is 10000" << std::endl;
	std::cout << "\t-t \t\t\tshows the execution time in microseconds [uS]" 
		<< std::endl;
	std::cout << "\t-f \t\t\tredirects output to log.txt file" << std::endl;
}
