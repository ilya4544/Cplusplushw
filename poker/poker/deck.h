#ifndef DECK_H
#define DECK_H
#include <vector>
#include <ctime>
#include "card.h"
class Card;

class Deck {
	std::vector<Card> deck;
	void genFourSuit(int v);
	void add(Card);
public:
	Deck() = default;
	Deck(int);
	Card get();
	void shuffle();
};

#endif DECK_H