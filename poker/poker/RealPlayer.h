#ifndef REALPLAYER_H
#define REALPLAYER_H
#include "player.h"

// Implement real players action
class RealPlayer : public Player {
	int run(int) const;
public:
	RealPlayer(); // Default constructor
	RealPlayer(std::string nm); // Constructor with name of the player
};

#endif // !REALPLAYER_H