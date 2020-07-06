#include <chrono>
#include <cstring>
#include <iostream>
#include <fstream>

#include "player.hpp"
#include "roulette.hpp"

int main(int argc, char* argv[])
{
	constexpr  char LOG_FILE_NAME[] = "log.txt";
	int verbose = 0, plays = 10000, final_balance = 0, time_flag = 0, 
		log_to_file = 0;
	std::streambuf *psbuf, *backup = std::cout.rdbuf();
	std::ofstream logfile;

	for(int i = 0; i < argc; i++){
		if(!strcmp(argv[i], "-v")){
			verbose = 1;
		}
		if(!strcmp(argv[i], "-p")) {
			plays = atoi(argv[i + 1]);
		}
		if(!strcmp(argv[i], "-t")) {
			time_flag = 1;
		}
		if(!strcmp(argv[i], "-f")) {
			log_to_file = 1;
		}
	}

	if(log_to_file) {
		logfile.open(LOG_FILE_NAME, std::ofstream::trunc);
		psbuf = logfile.rdbuf();
		std::cout.rdbuf(psbuf);
	}

	std::cout << "Welcome to ROULETTE++" << std::endl;

	Roulette *roulette = new Roulette(verbose);
	std::array<Player*, 6> players = {
		new Player("Player A", RED, verbose),
		new Player("Player B", BLACK, verbose),
		new Player("Player C", MAJOR, verbose),
		new Player("Placer D", MINOR, verbose),
		new Player("Player E", EVEN, verbose),
		new Player("Player F", ODD, verbose)
	};

	auto t1 = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < plays; i++) {
		final_balance = 0;
		std::cout << "------------ ROLL NUMBER: " << i + 1 << std::endl;
		roulette->roll();
		for(Player *player : players) {
			player->updateStats();
			final_balance += player->getBalance();
		}
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
