#include "AIPlayer.h"
AIPlayer::AIPlayer() {
	money = 0;
	playerName = "Default AI name";
}

AIPlayer::AIPlayer(std::string nm, int m) {
	money = m;
	playerName = nm;
}

int AIPlayer::run(int nowBet) {
	bet(nowBet);
	return 0;
}