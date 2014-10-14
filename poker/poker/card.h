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

enum Value {
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	Ten = 10,
	Jack = 11,
	Queen = 12,
	King = 13,
	Ace = 14
};

// Implement core for the card
class Card {
	State state;
	Suit suit;
	int value;
	Card(Suit s, Value v);
	Card() = default;
	Card(const Card & other) = delete;
	friend class Deck;
public:
	Card(Card && other); // Move-constructor
	std::pair<Suit, int> look() const; // Return pair (Suit, Value) for this card
	void open();
};

bool operator==(Card&, Card&); // Operator == for two cards

#endif // !CARD_H