#include "tehasholdem.h"
#include "RealPlayer.h"
#include "AIPlayer.h"

int main() {
	TehasHoldem game;
	RealPlayer* I = new RealPlayer("Ilya Lyamkin");
	AIPlayer* ai = new AIPlayer("Dummy AI");
	std::vector<Player*> pl;
	pl.push_back(I);
	pl.push_back(ai);
	game.runGame(pl);
	delete I;
	delete ai;
	return 0;
}