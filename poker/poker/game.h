#ifndef GAME_H
#define GAME_H
#include "player.h"

// Implement everything related to the game 
class Game {
protected:
	UserInterface uInterface;
	std::vector<Player*> players;
	int countPlayers;

	std::vector<Card>& lookCards(Player*) const;
	void addMoney(Player *, int);
	int money(Player *) const;
	void kickPlayer(Player *);
	int stepPlayer(Player *, int);
	void bet(Player *, int a);
	void nullBid(Player * player);
	void clearCards(Player * player);
	void getCard(Player * player);

	void getFromDeck(std::vector<Card> & to);
	void generateCardDeck(int);
	void shuffleDeck();
public:
	Game() = default; // Default constructor
	virtual void runGame(std::vector<Player*>) = 0; // Start game with the players
};

#endif // !GAME_H