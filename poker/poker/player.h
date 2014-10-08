#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"
#include "userInterface.h"

class Player {
protected:
	UserInterface uInterface;
	std::vector<Card> cards;
	int money;
	int id;
	int bidPlayer;
	std::string playerName;
	friend class Game; // Only game can judge me 
public:
	Player();
	Player(std::string, int);
	virtual int run(int) const = 0; //You must return your current bid. If you want "check" return nowBet, "raise" - greater then nowBid, and "fold" in other cases.
	std::string name() const; // Public method
	int bid() const; // Public method
};



#endif // !PLAYER_H