#ifndef CARD_H
#define CARD_H
#include <algorithm>
#include <utility>

enum State {
	OPEN, CLOSE
};

enum Suit {
	SPRADE, HEART, DIAMOND, CLUB
};

class Card {
	State state;
	Suit suit;
	int value;
public:
	Card() = default;
	Card(const Card & other) = delete;
	Card(Card && other);
	Card(Suit s, int v);
	std::pair<Suit, int> look() const;
	void open();
};

bool operator==(Card&, Card&);

#endif CARD_H