#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include "card.h"
#include "deck.h"
//#include "userInterface.h"
class Card;
class Deck;

class Player {
protected:
	//UserInterface uInterface;
	std::vector<Card> cards;
	int money;
	int id;
	int bidPlayer;
	std::string playerName;
	friend class Game; // Only game can judge me 
public:
	Player();
	Player(std::string, int);
	virtual int run(int) = 0; //You must return your current bid.If you want "check" return nowBet, "raise" - greater then nowBid, and "fold" in other cases.
	void bet(int); // TODO: Move to private for anticheating
	std::string name() const;
	void getCard(Deck&);
	//std::vector<Card> lookCards() const;
	void openCard(Card&);
	int bid() const;
};



#endif // !PLAYER_H