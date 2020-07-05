#include <iostream>
#include <random>
#include <string>
#include <map>

int main()
{
	//double bet, winnings = 0;

	// Use arrays for player decision
	char gametype;
	std::map<std::string, int> roulette_result;

	roulette_result["even"] = 0;
	roulette_result["odd"] = 0;
	roulette_result["red"] = 0;
	roulette_result["black"] = 0;
	roulette_result["major"] = 0;
	roulette_result["minor"] = 0;
	roulette_result["zero"] = 0;
	roulette_result["value"] = 0;

	// Main Menu Screen
	std::cout << "Bienvenido a ROULETTE++\n\n";
	std::cout << "Seleccione una simple apuesta: par (p), impar (i), rojos (r), "
		"negros (r), mayores(M), menores(m)" << std::endl;
	std::cin >> gametype;

	/* Non-deterministic 32-bit seed
	 * This will cause that everytime we run this program
	 * It will give different results from our Roulette
	 */
	std::random_device rd; 
	// Engine: [0, 2^32)   mt(1729) deterministic 32-bit seed
	std::mt19937 mt(rd());
	// Uniform distribution between 0 and 36, the max number a Roulette can
	// output () -> [inclusive, inclusive]
	std::uniform_int_distribution<int> dist(0, 36);

	/* srand avoids to generate always the same number */
	//srand(time(nullptr));
	for(int i = 0; i < 10000; i++) {
		int random_number = dist(mt);
		roulette_result["value"] = random_number;
		if(!random_number) {
			roulette_result["zero"] = 1;
		} else {
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
		for(std::map<std::string,int>::iterator it = roulette_result.begin(); 
				it != roulette_result.end(); ++it) {
			std::cout << it->first << ": " << it->second << "\t";
		}
		std::cout << "\n" << std::endl;
	}
}
