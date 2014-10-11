#ifndef HAND_H
#define HAND_H

class Wallet {
	int money;
	int bidPlayer;
	friend class Game;
public:
	Wallet();
	int bid() const;
	int getMoney() const;
};


#endif HAND_H