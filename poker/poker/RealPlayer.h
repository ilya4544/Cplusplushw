#ifndef REALPLAYER_H
#define REALPLAYER_H
#include "player.h"
//#include <iostream>

class RealPlayer : public Player {
	int run(int);
public:
	RealPlayer();
	RealPlayer(std::string nm, int m);
};

#endif REALPLAYER_H