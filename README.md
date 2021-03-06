## Roulette++

Roulette++ is a Casino Roulette Simulator written in C++11 which follows the next rules:
- The roulette has 37 numbers (0 - 36)
- The player can only make simple bets (red, black, even, odd, high, low)
- The number 0 is a special number. When the roulette outputs this number it means that the players who made a simple bet have lost (in this case, everyone).
- If the player has won a simple bet. The dealer pays the double of what the player has bet. i.e. Player A bets 10 units, the dealer pays 20 (bet + earnings). Otherwise, the dealer keeps with the bet, in this case, Player A has lost 10 units.
    
For this simulation the table's range is between 4000 units and 5 units. Every player of the simulation has a list of every bet, and begins with the following sequence:

1 - 2 - 3 - 4

The current bet is a sum of the beginning and the end of the list. i.e. first bet of Player A would be 1 + 4 = 5. If the player has won, then he add the last bet to the end of the list and sums it to the current balance, thus the list would be:

1 - 2 - 3 - 4 - 5

and his net balance is 5 units. On the other hand if the player losses, it deletes the first and last values and extracts the latter bet to the current balance, in this case the list would end up being:

2 - 3

and his net balance is -5 units.

The players have an unlimited amount of money, so when the bet excedes the maximum bet or is lower than the minimum bet or even does not have any bet left on the list, it is automatically re established to its original sequence (1 - 2 - 3 - 4).

For testing purposes, the program is fixed with six players (Player A, Player B, Player C, Player D, Player E and Player F), these players always make the same simple bet (red, black, high, low, even, odd respectively) and the simulation runs 10000 times showing on each run the sum of all the player's balance.

## Build and run
### Linux
* Clone the repository\
    `git clone https://github.com/moyamartin/roulette_simulator.git` 
* Open a terminal, change to the directory where you cloned Roulette++ and to build type:<br>
    `make`<br>
* The executable file is build in `$PWD/bin`, to execute type (-p argument sets the nr of simulations): <br>
`bin/roulette -p 100` <br>
or <br>
```
cd bin
./roulette -p 100
```
**NOTE:** This software can be run with a few options:

| Option			| Description																				|
|-------------------|:-----------------------------------------------------------------------------------------:|
| -h				| Shows available options																	|
| -v				| Enables verbose mode																		|
| -f				| Prints cout to file log.txt																|
| -p [nr]			| Sets the number of cycles to simulate. If ommited the number of cycles is set to 10000	|
| -t				| Measures the execution time																|


## Documentation

Doxygen documentation can be found [here!](https://moyamartin.github.io/roulette_simulator)

## Authors
* **Martin Moya** - Initial work
