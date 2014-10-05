#include "game.h"
int Game::stepPlayer(Player& player, int nowBid) {
	return player.run(nowBid);
}

void Game::kickPlayer(Player& player) {
	for (auto it = players.begin(); it != players.end(); it++)
		if ((*it).name() == player.name()) {
			players.erase(it);
			break;
		}
}

std::vector<Card> Game::lookCards(Player & player) const{
	return player.cards;
}

int Game::bid(Player & player) {
	return player.bidPlayer;
}

void Game::addMoney(Player & player, int count) {
	player.money += count;
}

int Game::money(Player & player) {
	return player.money;
}
