#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"
#include "Wallet.h"
#include "userInterface.h"

class Player {
protected:
	Wallet wallet;
	UserInterface uInterface;
	mutable std::vector<Card> cards;
	std::string playerName;
	friend class Game; // Only game can judge me 
public:
	Player();
	Player(std::string);
	virtual int run(int) const = 0; //You must return your current bid. If you want "check" return nowBet, "raise" - greater then nowBid, and "fold" in other cases.
	std::string name() const; // Public method
	int bidPlay() const; //Public method
};



#endif // !PLAYER_H