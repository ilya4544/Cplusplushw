#ifndef CARD_H
#define CARD_H
#include "player.h"

enum State {
	OPEN, CLOSE
};

enum Suit {
	SPRADE, HEART, DIAMOND, CLUB
};

enum Value {
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

class Card {
	State state;
	Suit suit;
	int value;
public:
	Card() = default;
	Card(Suit s, int v);
//	void take(Player *);
	std::pair<Suit, int> look() const;
	void open();
};

bool operator==(Card&, Card&);

#endif CARD_H