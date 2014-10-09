#include "game.h"
int Game::stepPlayer(Player * player, int nowBid, std::vector<Card> & openCards) {
	int res = player->run(nowBid, openCards);
	if (res - nowBid > player->money)
		return -1;
	if (res == nowBid) {
		bet(player, nowBid);
		return 0;
	}
	if (res > nowBid) {
		bet(player, res);
		return (res - nowBid);
	}
	return -1;
}

void Game::clearCards(Player * player) {
	player->cards.clear();
}

void Game::kickPlayer(Player * player) {
	for (auto it = players.begin(); it != players.end(); it++)
		if ((*it)->name() == player->name()) {
		players.erase(it);
		break;
		}
}

std::vector<Card>& Game::lookCards(Player * player) const {
	return player->cards;
}

void Game::bet(Player * player, int a) {
	player->money -= a - player->bidPlayer;
	player->bidPlayer = a;
}

void Game::nullBid(Player * player) {
	player->bidPlayer = 0;
}

void Game::addMoney(Player * player, int count) {
	player->money += count;
}

int Game::money(Player * player) const {
	return player->money;
}

void Game::getCard(Player * player) {
	deck.get(player->cards);
}