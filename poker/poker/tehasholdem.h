#ifndef TEHASHOLDEM_H
#define TEHASHOLDEM_H
#include "game.h"

class TehasHoldem : public Game {
	void trade(int, std::vector<Player> &, std::vector<bool>&);
	std::vector<Player> playRound();
	std::pair<int, int> maxCombination(Player & player, std::vector<Card> & openCards) const;
public:
//	TehasHoldem() = default;
	void runGame(std::vector<Player>);
};

#endif TEHASHOLDEM_H