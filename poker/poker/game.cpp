#include "game.h"
int Game::stepPlayer(Player * player, int nowBid) {
	int res = player->run(nowBid);
	if (res - nowBid > player->wallet.money)
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
	player->wallet.money -= a - player->wallet.bidPlayer;
	player->wallet.bidPlayer = a;
}

void Game::nullBid(Player * player) {
	player->wallet.bidPlayer = 0;
}

void Game::addMoney(Player * player, int count) {
	player->wallet.money += count;
}

int Game::money(Player * player) const {
	return player->wallet.money;
}

void Game::getCard(Player * player) {
	Deck::getInstance().get(player->cards);
}

void Game::getFromDeck(std::vector<Card> & to) {
	Deck::getInstance().get(to);
}

void Game::generateCardDeck(int a) {
	Deck::getInstance().generateCard(a);
}

void Game::shuffleDeck() {
	Deck::getInstance().shuffle();
}