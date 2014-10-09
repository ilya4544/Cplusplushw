#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "player.h"

class AIPlayer : public Player {
	int run(int, std::vector<Card>&) const;
public:
	AIPlayer();
	AIPlayer(std::string, int);
};

#endif