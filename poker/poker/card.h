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
	Card(Suit s, int v);
	Card() = default;
	Card(const Card & other) = delete;
	friend class Deck;
public:
	Card(Card && other);
	std::pair<Suit, int> look() const;
	void open();
};

bool operator==(Card&, Card&);

#endif CARD_H