#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "card.h"
#include "deck.h"
class Card;
class Deck;

class Player {
protected:
	std::vector<Card> cards;
	int money;
	int id;
	int bidPlayer;
	std::string playerName;
	friend class Game; // Only game can judge me 
public:
	Player();
	Player(std::string, int);
	virtual int run(int) = 0; // Return 0, if player check; >0 - player raise bid on this value; -1 - if player fold.

	std::string name() const;
	void getCard(Deck&);
	//std::vector<Card> lookCards() const;
	void openCard(Card&);
	void bet(int); // 
	int bid() const;
};



#endif // !PLAYER_H