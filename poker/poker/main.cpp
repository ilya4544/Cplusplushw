#include "tehasholdem.h"
#include "RealPlayer.h"
#include "AIPlayer.h"

int main() {
	TehasHoldem game;
	RealPlayer* I = new RealPlayer("Ilya Lyamkin", 2000);
	AIPlayer* ai = new AIPlayer("Dummy AI", 2000);
	std::vector<Player*> pl;
	pl.push_back(I);
	pl.push_back(ai);
	game.runGame(pl);
	return 0;
}