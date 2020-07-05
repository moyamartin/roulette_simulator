#include <iostream>
#include <roulette.hpp>

int main()
{
	std::cout << "Bienvenido a ROULETTE++\n\n";
	
	Roulette *roulette = new Roulette();

	for(int i = 0; i < 10000; i++) {
		roulette->roll(1);
	}
}
