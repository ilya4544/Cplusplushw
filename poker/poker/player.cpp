#include "player.h"

Player::Player() {
	money = 0;
	playerName = "Default Name";
}

Player::Player(std::string name, int m) {
	playerName = name;
	money = m;
}

int Player::bid() const {
	return bidPlayer;
}

std::string Player::name() const {
	return playerName;
}