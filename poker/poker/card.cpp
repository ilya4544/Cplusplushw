#include "card.h"

Card::Card(Suit s, int v) {
	suit = s;
	value = v;
	state = CLOSE;
}


std::pair<Suit, int> Card::look() const {
	return std::make_pair(suit, value);
}

Card::Card(Card && other) {
	value = std::move(other.value);
	state = std::move(other.state);
	suit = std::move(other.suit);
}

void Card::open() {
	state = OPEN;
}

bool operator==(Card & a, Card & b) {
	return (a.look() == b.look());
}
