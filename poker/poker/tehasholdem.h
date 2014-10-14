#ifndef TEHASHOLDEM_H
#define TEHASHOLDEM_H
#include "game.h"

// Class for Texas Hold'em poker game
class TehasHoldem : public Game {
	void trade(int, std::vector<bool>&, std::vector<Card>&);
	std::vector<int> playRound();
	std::pair<int, int> maxCombination(Player * player, std::vector<Card> & openCards) const;
public:
	void runGame(std::vector<Player*>); // Start game
};

#endif // !TEHASHOLDEM_H