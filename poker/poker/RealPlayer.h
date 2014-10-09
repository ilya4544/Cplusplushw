#ifndef REALPLAYER_H
#define REALPLAYER_H
#include "player.h"

class RealPlayer : public Player {
	int run(int, std::vector<Card> &) const;
public:
	RealPlayer();
	RealPlayer(std::string nm, int m);
};

#endif REALPLAYER_H