#include "AIPlayer.h"

AIPlayer::AIPlayer() {
	playerName = "Default AI name";
}

AIPlayer::AIPlayer(std::string nm) {
	playerName = nm;
}

int AIPlayer::run(int nowBet) const {
	std::cout << "Money:" << wallet.getMoney() << std::endl;
	return nowBet;
}