#include "player.h"

Player::Player() {
	playerName = "Default Name";
}

Player::Player(std::string name) {
	playerName = name;
}

std::string Player::name() const {
	return playerName;
}

int Player::bidPlay() const {
	return wallet.bid();
}