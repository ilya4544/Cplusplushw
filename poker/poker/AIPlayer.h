#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "player.h"

//Implement AI players action 
class AIPlayer : public Player {
	int run(int) const;
public:
	AIPlayer(); // Default constructor
	AIPlayer(std::string); // Constructor with name of the player
};

#endif // !AIPLAYER_H