#ifndef GAME_H
#define GAME_H
#include "player.h"

class Game { // Has access to players functions. Player don't have it, because he want cheating.
protected:
	Deck deck;
	UserInterface uInterface;
	std::vector<Player*> players;
	int countPlayers;
	std::vector<Card>& lookCards(Player*) const;
	void addMoney(Player *, int);
	int money(Player *) const;
	void kickPlayer(Player *);
	int stepPlayer(Player *, int, std::vector<Card>&);
	void bet(Player *, int a);
	void nullBid(Player * player);
	void clearCards(Player * player);
	void getCard(Player * player);
public:
	Game() = default;
	virtual void runGame(std::vector<Player*>) = 0;
};

#endif GAME_H