#ifndef HAND_H
#define HAND_H

// Class for keeping money and current bid of the player
class Wallet {
	int money;
	int bidPlayer;
	friend class Game;
public:
	Wallet(); // Default constructor
	int bid() const; // Return current bid
	int getMoney() const; // Return current balance  
};


#endif // !HAND_H