#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"
#include "userInterface.h"
#include "Wallet.h"

//Class for realization player
class Player {
protected:
	Wallet wallet;
	UserInterface uInterface;
	mutable std::vector<Card> cards;
	std::string playerName;
	friend class Game; // Only game can judge me 
public:
	Player(); // Default constructor
	Player(std::string); // Constructor takes name of the player
	virtual int run(int) const = 0; // You must return your current bid. If you want "check" return nowBet, "raise" - greater then nowBid, and "fold" in other cases.
	std::string name() const; // Return players name
	int bidPlay() const; // Return current bid
};

#endif // !PLAYER_H