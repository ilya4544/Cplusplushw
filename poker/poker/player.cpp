#include "player.h"

Player::Player() {
	money = 0;
	playerName = "Default Name";
}

Player::Player(std::string name, int m) {
	playerName = name;
	money = m;
}

void Player::getCard(Deck& deck) {
	cards.push_back(deck.get());
}

//std::vector<Card> Player::lookCards() const{
	//return cards;
//}

int Player::run(int) {
	return 42;
}

void Player::bet(int a) {
	money -= a - bidPlayer;
	bidPlayer = a;
}

int Player::bid() const {
	return bidPlayer;
}

std::string Player::name() const {
	return playerName;
}